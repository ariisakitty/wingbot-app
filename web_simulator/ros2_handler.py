import time
import rclpy
from rclpy.node import Node
from bridge_interface.msg import Robot2Server, LatLng

class ROS2Publisher(Node):

    def __init__(self):
        super().__init__('web_interface_publisher')
        self.publisher_left = self.create_publisher(Robot2Server, 'robot_left/robot2server', 10)
        self.publisher_right = self.create_publisher(Robot2Server, 'robot_right/robot2server', 10)

    def publish_messages(self):
        left_locs = [
            LatLng(lat=39.050841067691984, lng=-84.65810003637769),
            LatLng(lat=39.050925698245166, lng=-84.65811843519225),
            LatLng(lat=39.05100483321613, lng=-84.65814674106082),
            LatLng(lat=39.051127931883634, lng=-84.65819061515711),
            LatLng(lat=39.05118728295021, lng=-84.65825713394823)
        ]

        right_locs = [
            LatLng(lat=39.05093009463476, lng=-84.65797690584944),
            LatLng(lat=39.05103121152008, lng=-84.65786085178831),
            LatLng(lat=39.051091661762825, lng=-84.65781839298546),
            LatLng(lat=39.051152111953805, lng=-84.65779716358402),
            LatLng(lat=39.05118178748317, lng=-84.65777168830232)
        ]

        for i in range(6):
            if i < 5:
                msg_left = Robot2Server()
                msg_left.loc = left_locs[i]
                msg_left.is_at_ww_pos = False

                msg_right = Robot2Server()
                msg_right.loc = right_locs[i]
                msg_right.is_at_ww_pos = False

                self.publisher_left.publish(msg_left)
                self.publisher_right.publish(msg_right)

                self.get_logger().info(f'Published message {i+1}')
            else:
                msg_left = Robot2Server()
                msg_left.loc = left_locs[i-1]
                msg_left.is_at_ww_pos = True

                msg_right = Robot2Server()
                msg_right.loc = right_locs[i-1]
                msg_right.is_at_ww_pos = True

                self.publisher_left.publish(msg_left)
                self.publisher_right.publish(msg_right)

                self.get_logger().info(f'Published message {i+1}')


            time.sleep(1)

    def spawn_vehicle_on_vsr(self):
        loc = LatLng(lat=39.05118728295021, lng=-84.65825713394823)
        ww_obj = [LatLng(lat=39.051210363907074, lng=-84.65846659737564)]

        msg_left = Robot2Server()
        msg_left.loc = loc
        msg_left.ww_obj = ww_obj
        
        self.publisher_left.publish(msg_left)

        self.get_logger().info('Spawned vehicle on VSR')

    def remove_vehicle_on_vsr(self):
        loc = LatLng(lat=39.05118728295021, lng=-84.65825713394823)

        msg_left = Robot2Server()
        msg_left.loc = loc
        
        self.publisher_left.publish(msg_left)

        self.get_logger().info('Removed vehicle from VSR')

rclpy.init(args=None)
ros2_publisher = ROS2Publisher()