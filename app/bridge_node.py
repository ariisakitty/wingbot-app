import rclpy
from rclpy.node import Node
from bridge_interface.msg import Server2Robot, Robot2Server

class BridgeNode(Node):
    def __init__(self):
        super().__init__('bridge_node')
        self.s2r_pub_ = self.create_publisher(Server2Robot, 'server2robot', 10)
        self.s2r_timer_ = self.create_timer(1, self.publish_s2r)

        self.r2s_sub_ = self.create_subscription(Robot2Server, 'robot2server', self.r2s_callback, 10)
        self.r2s_sub_

        self.r2s = ""
        self.s2r = ""

    def publish_s2r(self, msg):
        print(f"gate: {self.s2r_msg.gate} / activate: {self.s2r_msg.activate} / engage: {self.s2r_msg.engage} / estop: {self.s2r_msg.estop}")
        self.s2r_pub_.publish(msg)
    
    def r2s_callback(self, msg):
        self.r2s = msg.data  # Update the r2s variable with received message
        self.get_logger().info('Received: "%s"' % self.r2s) 

def run_bridge_node():
    rclpy.init()
    bridge_node = BridgeNode()
    rclpy.spin(bridge_node)
    bridge_node.destroy_node()
    rclpy.shutdown()
