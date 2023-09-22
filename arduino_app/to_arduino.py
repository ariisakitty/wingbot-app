import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt8
import serial

class ArduinoStateSubscriberNode(Node):
    def __init__(self):
        super().__init__('arduino_state_subscriber')
        self.subscription = self.create_subscription(
            UInt8,
            'arduino_state',
            self.arduino_state_callback,
            10
        )
        self.serial_port = '/dev/ttyACM0'
        self.baud_rate = 9600
        try:
            self.ser = serial.Serial(self.serial_port, self.baud_rate)
            self.get_logger().info(f'Serial port {self.serial_port} opened')
        except serial.SerialException as e:
            self.get_logger().error(f'Error opening serial port: {e}')
            self.ser = None
        
        self.timer_period = 1.0  # Timer period in seconds (1Hz)
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.data_to_send = 1
        
    def arduino_state_callback(self, msg):
        self.data_to_send = msg.data
        self.get_logger().info(f'Received: {self.data_to_send}')

    def timer_callback(self):
        # This method will be called every second
        self.publish_to_arduino()
        
    def publish_to_arduino(self):
        if self.ser is None or self.data_to_send is None:
            return
        
        try:
            message = "<{}>".format(self.data_to_send).encode('utf-8')
            self.ser.write(message)
            self.get_logger().info(f'Sent to Arduino: {self.data_to_send}')
        except serial.SerialException as e:
            self.get_logger().error(f'Error writing to serial port: {e}')
        
def main(args=None):
    rclpy.init(args=args)
    node = ArduinoStateSubscriberNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    if node.ser is not None:
        node.ser.close()  # Close the serial port when shutting down
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
