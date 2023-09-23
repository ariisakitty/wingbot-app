import rclpy
from rclpy.node import Node
from bridge_interface.msg import Server2Robot, Robot2Server

class BridgeNode(Node):
    def __init__(self):
        super().__init__('bridge_node')
        self.s2r_pub_ = self.create_publisher(Server2Robot, 'server2robot', 10)
        self.s2r_timer_ = self.create_timer(1, self.publish_s2r)

        self.r2s_left_sub_ = self.create_subscription(Robot2Server, 'robot_left/robot2server', self.r2s_left_callback, 10)
        self.r2s_right_sub2_ = self.create_subscription(Robot2Server, 'robot_right/robot2server', self.r2s_right_callback, 10)
        
        self.r2s_left = Robot2Server()
        self.r2s_right = Robot2Server()
        self.s2r = Server2Robot()

        self.r2s_update_callback = None

    def publish_s2r(self):
        print(f"@publish_s2r@ gate: {self.s2r.gate} / activate: {self.s2r.activate} / engage: {self.s2r.engage} / estop: {self.s2r.estop}")
        self.s2r_pub_.publish(self.s2r)

    def set_s2r(self, value):
        print(f"@set_s2r@ value: {value}")
        self.s2r.gate = value["gate"] if value["gate"] is not None else ""
        self.s2r.activate = value["activate"] 
        self.s2r.engage = value["engage"]
        self.s2r.estop = value["estop"]

    def r2s_left_callback(self, msg):
        self.r2s_left = msg # Update the r2s variable with received message
        self.get_logger().info('Received: "%s"' % self.r2s_left) 
        if self.r2s_update_callback is not None:
            self.r2s_update_callback(self.r2s_left, self.r2s_right)

    def r2s_right_callback(self, msg):
        self.r2s_right = msg # Update the r2s variable with received message
        self.get_logger().info('Received: "%s"' % self.r2s_right) 
        if self.r2s_update_callback is not None:
            self.r2s_update_callback(self.r2s_left, self.r2s_right)
            
    def set_r2s_update_callback(self, callback):
        self.r2s_update_callback = callback

def run_bridge_node(callback):
    rclpy.init()
    bridge_node = BridgeNode()
    bridge_node.set_r2s_update_callback(callback)
    return bridge_node
