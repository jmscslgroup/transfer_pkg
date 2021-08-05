#ifndef MATHOP_HH
#define MATHOP_HH


#include <ros/ros.h>
#include <ros/console.h>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Float64.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>


/* This class performs Math operation on two separate component of two different topic types */

class MathOp
{
	protected:
		ros::NodeHandle *nh;
		ros::Publisher pub;
		std::string topic_in1;
		std::string topic_in2;
		std::string topic_out;
		ros::Subscriber sub1, sub2;

	public:
		MathOp(ros::NodeHandle *nh);

};

class AddGeometryMsgComp: MathOp
{
	protected:
		std::string component_in1;
		std::string component_in2;
		std::string component_out;
		geometry_msgs::Twist msg1;
		geometry_msgs::Twist msg2;
		geometry_msgs::Twist msg_out;


	public:
		AddGeometryMsgComp(ros::NodeHandle *nh);
		void callback_1(const geometry_msgs::Twist& msg);
		void callback_2(const geometry_msgs::Twist& msg);
		void publish();
};

#endif // MATHOP_HH
