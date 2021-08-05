#include "mathop.hh"

MathOp::MathOp(ros::NodeHandle *nh): nh(nh)
{
	
}

AddGeometryMsgComp::AddGeometryMsgComp(ros::NodeHandle *nh): MathOp(nh)
{
	nh->param("topic_in1", topic_in1, std::string("topic_in1"));	
	nh->param("topic_in2", topic_in2, std::string("topic_in2"));	
	nh->param("topic_out", topic_out, std::string("topic_out"));	
	nh->param("component_in1", component_in1, std::string("linear.x"));
	nh->param("component_in2", component_in2, std::string("linear.x"));
	nh->param("component_out", component_out, std::string("linear.x"));
	pub = nh->advertise<geometry_msgs::Twist>(topic_out, 1);
	sub1 = nh->subscribe(topic_in1, 1, &AddGeometryMsgComp::callback_1, this);
	sub2 = nh->subscribe(topic_in2, 1, &AddGeometryMsgComp::callback_2, this);

	msg1.linear.x = 0;
	msg1.linear.y = 0;
	msg1.linear.z = 0;
	msg1.angular.x = 0;
	msg1.angular.y = 0;
	msg1.angular.z = 0;
	msg2.linear.x = 0;
	msg2.linear.y = 0;
	msg2.linear.z = 0;
	msg2.angular.x = 0;
	msg2.angular.y = 0;
	msg2.angular.z = 0;

	ROS_INFO_STREAM("Input Topic 1 is "<< topic_in1);
	ROS_INFO_STREAM("Input Topic 2 is "<< topic_in2);
	ROS_INFO_STREAM("Output Topic is "<< topic_out);
	
	ROS_INFO_STREAM("Input Component 1 is "<< component_in1);
	ROS_INFO_STREAM("Input Component 2 is "<< component_in2);
	ROS_INFO_STREAM("Output Component is "<< component_out);

}

void AddGeometryMsgComp::callback_1(const geometry_msgs::Twist& m) {msg1 = m;}
void AddGeometryMsgComp::callback_2(const geometry_msgs::Twist& m) {msg2 = m;}


void AddGeometryMsgComp::publish()
{
	double val1, val2, val_out;

	if(component_in1 == "linear.x"){val1  = msg1.linear.x;}
	else if(component_in1 == "linear.y"){val1  = msg1.linear.y;}
	else if(component_in1 == "linear.z"){val1 = msg1.linear.z;}
	else if(component_in1 == "angular.x"){val1  = msg1.angular.x;}
        else if(component_in1 == "angular.y"){val1 = msg1.angular.y;}
        else if(component_in1 == "angular.z"){val1 = msg1.angular.z;}

	if(component_in2 == "linear.x"){val2  = msg2.linear.x;}
	else if(component_in2 == "linear.y"){val2  = msg2.linear.y;}
	else if(component_in2 == "linear.z"){val2 = msg2.linear.z;}
	else if(component_in2 == "angular.x"){val2  = msg2.angular.x;}
        else if(component_in2 == "angular.y"){val2 = msg2.angular.y;}
        else if(component_in2 == "angular.z"){val2 = msg2.angular.z;}

	val_out = val1 + val2;
	
	msg_out.linear.x = 0;
	msg_out.linear.y = 0;
	msg_out.linear.z = 0;
	msg_out.angular.x = 0;
	msg_out.angular.y = 0;
	msg_out.angular.z = 0;
	if(component_out == "linear.x"){msg_out.linear.x = val_out;}
        else if(component_out == "linear.y"){msg_out.linear.y = val_out;}
        else if(component_out == "linear.z"){msg_out.linear.z = val_out;}
        else if(component_out == "angular.x"){msg_out.angular.x = val_out;}
        else if(component_out == "angular.y"){msg_out.angular.y = val_out;}
        else if(component_out == "angular.z"){msg_out.angular.z = val_out;}

	pub.publish(msg_out);	


}

