#include "ros/ros.h"
#include "ex_4/JintControlSrv.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "jint_control_srv_client");
	if (argc != 6)
	{
		ROS_INFO("usage: mode, time, rotation, shoulder, elbow");
		return 1;
	}

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<ex_4::JintControlSrv>("jint_control_srv");

	ex_4::JintControlSrv srv;

	srv.request.mode = atoi(argv[1]);
	srv.request.time = atof(argv[2]);
	srv.request.teta1 = atof(argv[3]);
	srv.request.teta2 = atof(argv[4]);
	srv.request.teta3 = atof(argv[5]);

	if (client.call(srv))
	{
		ROS_INFO("Status: %d", srv.response.status);
	}
	else
	{
		ROS_ERROR("Failed to call service jint");
		return 1;
	}

	return 0;
}