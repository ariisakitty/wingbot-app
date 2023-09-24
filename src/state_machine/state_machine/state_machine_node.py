import rclpy
from rclpy.node import Node

from std_msgs.msg import UInt8
from sensor_msgs.msg import NavSatFix
from bridge_interface.msg import Server2Robot, Robot2Server

class StateMachineNode(Node):
    def __init__(self):
        super().__init__('state_machine_node')

        # Initialize the messages
        self.robot2server_msg = Robot2Server()
        self.last_navsatfix_timestamp = self.get_clock().now()
        self.arduino_state_msg = UInt8()
        self.in_triangle_count = 0
        self.triangle = [
            (39.22256584953551, -84.2708385284572),
            (39.2223581884994, -84.27097255577404),
            (39.2223611893858, -84.2707246439741)
        ]

        # Subscription
        self.sub_fix = self.create_subscription(NavSatFix, 'fixposition/navsatfix', self.callback_navsat, 10)
        self.sub_server = self.create_subscription(Server2Robot, 'server2robot', self.callback_server, 10)

        # Publisher
        self.pub_robot = self.create_publisher(Robot2Server, 'robot_left/robot2server', 10)
        self.pub_arduino_state = self.create_publisher(UInt8, 'arduino_state', 10)

        # Timer
        self.timer = self.create_timer(1, self.timer_callback)  

    def callback_navsat(self, msg: NavSatFix):
        # Extract the latitude and longitude
        self.robot2server_msg.loc.lat = msg.latitude
        self.robot2server_msg.loc.lng = msg.longitude
        self.robot2server_msg.is_on = True

        # Update the timestamp for the last received NavSatFix message
        self.last_navsatfix_timestamp = self.get_clock().now()

    def callback_server(self, msg: Server2Robot):
        # Transfer "gate" from Server2Robot to Robot2Server
        self.robot2server_msg.gate = msg.gate

        # Transfer "activate" from Server2Robot to "is_activated" in Robot2Server
        self.robot2server_msg.is_activated = msg.activate

        # Transfer "engage" from Server2Robot to "is_engaged" in Robot2Server
        self.robot2server_msg.is_engaged = msg.engage

        # Transfer "estop" from Server2Robot to Robot2Server
        self.robot2server_msg.estop = msg.estop

    def timer_callback(self):
        # Check the time difference
        current_time = self.get_clock().now()
        time_diff = current_time - self.last_navsatfix_timestamp
        if time_diff.nanoseconds >= 3*1e9:
            self.robot2server_msg.is_on = False

        print (f'in_triangle_count: {self.in_triangle_count}')
        if is_point_inside_triangle(self.robot2server_msg.loc.lat, self.robot2server_msg.loc.lng, self.triangle):
            self.in_triangle_count += 1
            if self.in_triangle_count >= 5:
                self.robot2server_msg.is_at_ww_pos = True
        else:
            self.in_triangle_count = 0
            self.robot2server_msg.is_at_ww_pos = False

        self.pub_robot.publish(self.robot2server_msg)

        # Arduino portion
        if self.robot2server_msg.is_engaged == True:
            self.arduino_state_msg.data = 3
        elif self.robot2server_msg.is_on == True:
            self.arduino_state_msg.data = 2
        else:
            self.arduino_state_msg.data = 1
        
        self.pub_arduino_state.publish(self.arduino_state_msg)

def is_point_inside_triangle(lat, lng, triangle):
    def sign(p1, p2, p3):
        return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1])

    b1 = sign((lat, lng), triangle[0], triangle[1]) < 0.0
    b2 = sign((lat, lng), triangle[1], triangle[2]) < 0.0
    b3 = sign((lat, lng), triangle[2], triangle[0]) < 0.0

    return ((b1 == b2) and (b2 == b3))

def main(args=None):
    rclpy.init(args=args)
    node = StateMachineNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
