#include "ros/ros.h"
#include "logger.h"
#include "bridge.h"
#include "joint_state_publisher.h"
#include "joint_state_subscriber.h"
#include "entry_publisher.h"
#include "entry_subscriber.h"



int bit_rate = 500000;
int hardware_id = 013000;
using namespace ros; 

void const cbMessage(const kaco::Message& msg){
/*

uint16_t cob_id;

	/// Remote transmission request (0 if it's not an RTR message, 1 if it is an RTR message)
	uint8_t rtr;

	/// Message's length (0 to 8)
	uint8_t len;

	/// Data bytes
	uint8_t data[8];

	/// Extracts the node id from the COB-ID.
	uint8_t get_node_id() const;
*/
/*PRINT("---------------------------------------------------------------------------------------------");
PRINT("node_id="<<msg.get_node_id());
PRINT("cob_id="<<msg.cob_id);
PRINT("len="<<msg.len);
PRINT_HEX("data="<<msg.data[0]<<" "<<msg.data[1]<<" "<<msg.data[2]<<" "<<msg.data[3]<<" "<<msg.data[4]<<" "<<msg.data[5]<<" "<<msg.data[6]<<" "<<msg.data[7]);
*/




}

int main(int argc, char **argv) {
    

    PRINT("SUPER ITS WORK  - myfile.cpp  !!!");
    ros::init(argc, argv, "myfile_node");
    ROS_INFO_STREAM("my_cpp_tutorial_node is started");
    ros::NodeHandle n("~");

    if (n.getParam("can_hardware_id", hardware_id)){
       ROS_INFO("hardware_id OK");
    }
       ROS_INFO("Kvaser CAN Interface - Got hardware_id: %d", hardware_id);

    if (n.getParam("can_bit_rate", bit_rate)){
       ROS_INFO("bit_rate OK");
    }
       ROS_INFO("Kvaser CAN can_bit_rate - Got can_bit_rate: %d", bit_rate);



    ros::spin();

    	const kaco::Value v1 = (int16_t)123;

	kaco::Core::MessageReceivedCallback mrcb;
	mrcb = cbMessage;

      	const std::string busname = "can0";//"slcan0";

        const std::string baudrate = "1M";//"500K";

	PRINT("This example publishes and subscribes JointState messages for each connected CiA 402 device as well as"
		<<"uint8 messages for each connected digital IO device (CiA 401).");

	const double loop_rate = 10; // [Hz]

	kaco::Master master;


    return 0;
}