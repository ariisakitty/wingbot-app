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

        # Subscription
        self.sub_fix = self.create_subscription(NavSatFix, 'fixposition/navsatfix', self.callback_navsat, 10)
        self.sub_server = self.create_subscription(Server2Robot, 'server2robot', self.callback_server, 10)

        # Publisher
        self.pub_robot = self.create_publisher(Robot2Server, 'robot2server', 10)
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

        # Logic for your state machine and eventual publishing on Robot2Server
        self.pub_robot.publish(self.robot2server_msg)

        if self.robot2server_msg.is_engaged == True:
            self.arduino_state_msg.data = 3
        elif self.robot2server_msg.is_on == True:
            self.arduino_state_msg.data = 2
        else:
            self.arduino_state_msg.data = 1
        
        self.pub_arduino_state.publish(self.arduino_state_msg)



def main(args=None):
    rclpy.init(args=args)
    node = StateMachineNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
