// This program subscribes to turtle1/pose and shows its messages on its screen.
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip> // for std::setprecision and std::fixed. 
                   // If we use ROS_INFO instead of ROS_INFO_STREAM, this header is not needed.
                   
// A callback function. Executed each time a new pose message arrives.
void poseMessageReceived(const turtlesim::Pose& msg)
{
    // ROS_INFO_STREAM(std::setprecision(2) << std::fixed 
    //     << "position=(" << msg.x << "," << msg.y << ")"
    //     << " direction=" << msg.theta);
    ROS_INFO("position = (%0.2f, %0.2f), direction = %0.2f", 
        msg.x, msg.y, msg.theta);
}

int main(int argc, char **argv)
{
    // Initialize the ROS system and become a node.
    ros::init(argc, argv, "subscribe_to_pose");
    ros::NodeHandle nh;
    
    // Create a subscriber object.
    ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000, 
        &poseMessageReceived);
        
    // Let ROS take over.
    ros::spin();
}
