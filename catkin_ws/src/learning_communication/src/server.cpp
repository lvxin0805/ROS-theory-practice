#include "ros/ros.h"
#include "learning_communication/AddTwoInts.h"

bool add(learning_communication::AddTwoInts::Request &req,
        learning_communication::AddTwoInts::Response &res)
{
    res.sum = req.a + req.b;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints");
    ros::spin();
    return 0;
}
