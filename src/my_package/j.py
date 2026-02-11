import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Float32



class Sub(Node):
    def __init__(self):
        super().__init__("sub_node")
        self.subscription = self.create_subscription(Float32, "score",self.listener_callback, 10)
        self.publisher_= self.create_publisher(String, "grade", 10)
        self.timer = self.create_timer(1.0, self.timer_callback)


    def listener_callback(self, msg):
        self.get_logger().info(f"I heard: {msg.data}")
    
    def timer_callback(self):
        msg = String()
        msg.data = "A"
        self.publisher_.publish(msg)
    
  
def main(args=None):
    rclpy.init(args=args)
    sub_node = Sub()
    rclpy.spin(sub_node)
    sub_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
