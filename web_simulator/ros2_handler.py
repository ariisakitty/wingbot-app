import time
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from bridge_interface.msg import Robot2Server, Server2Robot, LatLng

TARGET_GATE = "B8"

class ROS2Publisher(Node):

    def __init__(self):
        super().__init__('web_interface_publisher')
        self.publisher_left = self.create_publisher(Robot2Server, 'robot_left/robot2server', 10)
        self.publisher_right = self.create_publisher(Robot2Server, 'robot_right/robot2server', 10)

        self.subscription = self.create_subscription(
            Server2Robot, 
            'server2robot', 
            self.server2robot_callback, 
            10
        )
        self.subscription  # prevent unused variable warning
        self.is_activated = False
        self.is_engaged = False
        self.is_estop = False

    def server2robot_callback(self, msg):
        self.get_logger().info('Received from server2robot:')
        # self.get_logger().info(f'Gate: {msg.gate}')
        # self.get_logger().info(f'Activate: {msg.activate}')
        # self.get_logger().info(f'Engage: {msg.engage}')
        # self.get_logger().info(f'Estop: {msg.estop}')

        print(f'self.isestop: {self.is_estop} / msg.estop: {msg.estop}')
        if self.is_activated == False and msg.activate == True:
            self.is_activated = True
            loc = LatLng(lat=39.05116164579066, lng=-84.65826420651443)

            msg_left = Robot2Server()
            msg_left.is_on = True
            msg_left.loc = loc
            msg_left.is_at_ww_pos = True
            msg_left.gate = TARGET_GATE
            msg_left.is_activated = self.is_activated
            msg_left.is_engaged = self.is_engaged
            msg_left.estop = False

            self.publisher_left.publish(msg_left)

            self.get_logger().info('Respond to /activate')
        
        if self.is_engaged == False and msg.engage == True:
            self.is_engaged = True
            left_loc = LatLng(lat=39.05121168933777, lng=-84.65826353226554)
            right_loc = LatLng(lat=39.051207523421034, lng=-84.65774385430196)

            msg_left = Robot2Server()
            msg_left.is_on = True
            msg_left.loc = left_loc
            msg_left.is_at_ww_pos = True
            msg_left.gate = TARGET_GATE
            msg_left.is_activated = self.is_activated
            msg_left.is_engaged = self.is_engaged
            msg_left.estop = False
            self.publisher_left.publish(msg_left)


            msg_right = Robot2Server()
            msg_right.is_on = True
            msg_right.loc = right_loc
            msg_right.is_at_ww_pos = True
            msg_right.gate = TARGET_GATE
            msg_right.is_activated = self.is_activated
            msg_right.is_engaged = self.is_engaged
            msg_right.estop = False
            self.publisher_right.publish(msg_right)

        if self.is_engaged == True and msg.engage == False:
            self.is_engaged = False
            left_loc = LatLng(lat=39.05116164579066, lng=-84.65826420651443)
            right_loc = LatLng(lat=39.051167947199865, lng=-84.6577411720931)

            msg_left = Robot2Server()
            msg_left.is_on = True
            msg_left.loc = left_loc
            msg_left.is_at_ww_pos = False
            msg_left.gate = ""
            msg_left.is_activated = False
            msg_left.is_engaged = False
            self.publisher_left.publish(msg_left)


            msg_right = Robot2Server()
            msg_right.is_on = True
            msg_right.loc = right_loc
            msg_right.is_at_ww_pos = False
            msg_right.gate = ""
            msg_right.is_activated = False
            msg_right.is_engaged = False
            self.publisher_right.publish(msg_right)


        if self.is_estop == False and msg.estop == True:
            self.is_estop = True
            left_loc = LatLng(lat=39.05116164579066, lng=-84.65826420651443)
            right_loc = LatLng(lat=39.051167947199865, lng=-84.6577411720931)

            msg_left = Robot2Server()
            msg_left.is_on = True
            msg_left.loc = left_loc
            msg_left.is_at_ww_pos = True
            msg_left.gate = TARGET_GATE
            msg_left.is_activated = self.is_activated
            msg_left.is_engaged = self.is_engaged
            msg_left.estop = True
            self.publisher_left.publish(msg_left)


            msg_right = Robot2Server()
            msg_right.is_on = True
            msg_right.loc = right_loc
            msg_right.is_at_ww_pos = True
            msg_right.gate = TARGET_GATE
            msg_right.is_activated = self.is_activated
            msg_right.is_engaged = self.is_engaged
            msg_right.estop = True
            self.publisher_right.publish(msg_right)

        if self.is_estop == True and msg.estop == False:
            self.is_estop = False
            left_loc = LatLng(lat=39.05116164579066, lng=-84.65826420651443)
            right_loc = LatLng(lat=39.051167947199865, lng=-84.6577411720931)

            msg_left = Robot2Server()
            msg_left.is_on = True
            msg_left.loc = left_loc
            msg_left.is_at_ww_pos = True
            msg_left.gate = TARGET_GATE
            msg_left.is_activated = self.is_activated
            msg_left.is_engaged = self.is_engaged
            msg_left.estop = False
            self.publisher_left.publish(msg_left)


            msg_right = Robot2Server()
            msg_right.is_on = True
            msg_right.loc = right_loc
            msg_right.is_at_ww_pos = True
            msg_right.gate = TARGET_GATE
            msg_right.is_activated = self.is_activated
            msg_right.is_engaged = self.is_engaged
            msg_right.estop = False
            self.publisher_right.publish(msg_right)
        

    def publish_messages(self):
        left_locs = [
            LatLng(lat=39.050787915430014, lng=-84.65809642276515),
            LatLng(lat=39.05085111423119, lng=-84.65809340868582),
            LatLng(lat=39.05089480719647, lng=-84.65808838522028),
            LatLng(lat=39.05095410474897, lng=-84.65809340868582),
            LatLng(lat=39.05100013834092, lng=-84.65809843215139),
            LatLng(lat=39.05104227075473, lng=-84.65811450724112),
            LatLng(lat=39.05107972176811, lng=-84.65813058233087),
            LatLng(lat=39.05110702978619, lng=-84.6581536902724),
            LatLng(lat=39.05113121687911, lng=-84.65817981229323),
            LatLng(lat=39.05115384350691, lng=-84.65822301409695),
            LatLng(lat=39.05116164579066, lng=-84.65826420651443),
            LatLng(lat=39.05116164579066, lng=-84.65826420651443)
        ]

        right_locs = [
            LatLng(lat=39.05091041182038, lng=-84.65796581266095),
            LatLng(lat=39.050958005902004, lng=-84.65794170002631),
            LatLng(lat=39.05100013834092, lng=-84.65792261085723),
            LatLng(lat=39.05103602891724, lng=-84.65790050760883),
            LatLng(lat=39.051057875346046, lng=-84.65788242313286),
            LatLng(lat=39.05107942136167, lng=-84.65786455369994),
            LatLng(lat=39.05110285468259, lng=-84.65784443713362),
            LatLng(lat=39.05112420503487, lng=-84.65782834388055),
            LatLng(lat=39.051140868719955, lng=-84.65780956841863),
            LatLng(lat=39.051155970181185, lng=-84.6577887813001),
            LatLng(lat=39.051163781280565, lng=-84.65776330031608),
            LatLng(lat=39.051167947199865, lng=-84.6577411720931)
        ]

        for i in range(13):
            if i < 12:
                msg_left = Robot2Server()
                msg_left.is_on = True
                msg_left.loc = left_locs[i]
                msg_left.is_at_ww_pos = False
                msg_left.gate = TARGET_GATE

                msg_right = Robot2Server()
                msg_right.is_on = True
                msg_right.loc = right_locs[i]
                msg_right.is_at_ww_pos = False
                

                self.publisher_left.publish(msg_left)
                self.publisher_right.publish(msg_right)

                self.get_logger().info(f'Published message {i+1}')
            else:
                msg_left = Robot2Server()
                msg_left.is_on = True
                msg_left.loc = left_locs[i-1]
                msg_left.is_at_ww_pos = True
                msg_left.gate = TARGET_GATE

                msg_right = Robot2Server()
                msg_right.is_on = True
                msg_right.loc = right_locs[i-1]
                msg_right.is_at_ww_pos = True

                self.publisher_left.publish(msg_left)
                self.publisher_right.publish(msg_right)

                self.get_logger().info(f'Published message {i+1}')


            time.sleep(1.0)

    def spawn_vehicle_on_vsr(self):
        loc = LatLng(lat=39.05116164579066, lng=-84.65826420651443)
        ww_obj = [LatLng(lat=39.051210363907074, lng=-84.65846659737564)]

        msg_left = Robot2Server()
        msg_left.is_on = True
        msg_left.loc = loc
        msg_left.is_at_ww_pos = True
        msg_left.ww_obj = ww_obj
        msg_left.gate = TARGET_GATE
        msg_left.is_activated = self.is_activated
        msg_left.is_engaged = self.is_engaged
        
        self.publisher_left.publish(msg_left)

        self.get_logger().info('Spawned vehicle on VSR')

    def remove_vehicle_on_vsr(self):
        loc = LatLng(lat=39.05116164579066, lng=-84.65826420651443)

        msg_left = Robot2Server()
        msg_left.is_on = True
        msg_left.loc = loc
        msg_left.is_at_ww_pos = True
        msg_left.gate = TARGET_GATE
        msg_left.is_activated = self.is_activated
        msg_left.is_engaged = self.is_engaged
        
        self.publisher_left.publish(msg_left)

        self.get_logger().info('Removed vehicle from VSR')

def spin_ros2_node(node):
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    executor.spin()

# rclpy.init(args=None)
# ros2_publisher = ROS2Publisher()

# Start spinning the node in a new thread
# threading.Thread(target=spin_ros2_node, daemon=True).start()
