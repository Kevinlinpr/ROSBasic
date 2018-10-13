#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
inline void chatterCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard:[%s]",msg->data.c_str());
    // using namespace std;
    // std::cout<<"I heard ["<<msg->data<<"]"<<std::endl;
    
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter",1000,chatterCallback);
    ros::spin();
    return 0;
}