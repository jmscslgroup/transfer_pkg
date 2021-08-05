#include "mathop.hh"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_geometrymsgs");
	ros::NodeHandle nh;
	std::string onnx_model;
	AddGeometryMsgComp adder = AddGeometryMsgComp(&nh);

	ros::Rate rate(50);
	ros::Duration(1.0).sleep();
	while (ros::ok())
	{
		ros::spinOnce();
		adder.publish();
		rate.sleep();
	}

	return 0;
}


