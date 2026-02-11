import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, String



class Pub(Node):
    def __init__(self):
        super().__init__("pub_node")
        self.publisher_ = self.create_publisher(Float32, "score", 10)
        self.subscription = self.create_subscription(
            String, 
            "grade", 
            self.listener_callback, 
            10)
        self.timer = self.create_timer(1.0, self.timer_callback)

    def listener_callback(self, msg):
        self.get_logger().info(f"I heard: {msg.data}")

    def timer_callback(self):
        msg = Float32()
        msg.data = 4.0
        self.publisher_.publish(msg)
    

def main(args=None):
    rclpy.init(args=args)
    pub_node = Pub()
    rclpy.spin(pub_node)
    pub_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()

   