#include "ros/ros.h"
#include "logger.h"


int bit_rate = 500000;
int hardware_id = 013000;


int main(int argc, char **argv) {
    

    PRINT("SUPER ITS WORK  - myfile.cpp  !!!");
    ros::init(argc, argv, "kacanopen_example_myfile");
    //ROS_INFO_STREAM("my_cpp_tutorial_node is started");
    ros::NodeHandle n("~");

    if (n.getParam("can_hardware_id", hardware_id)){
       ROS_INFO("hardware_id OK");
    }
       ROS_INFO("Kvaser CAN Interface - Got hardware_id: %d", hardware_id);

    if (n.getParam("can_bit_rate", bit_rate)){
       ROS_INFO("bit_rate OK");
    }
       ROS_INFO("Kvaser CAN can_bit_rate - Got can_bit_rate: %d", bit_rate);



    //ros::spin();    
    return 0;
}