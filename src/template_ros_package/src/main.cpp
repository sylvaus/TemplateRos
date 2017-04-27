/**
  * File description
  */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "algo.hpp"
#include "main_cfg.hpp"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */


int main(int argc, char **argv)
{
  ros::init(argc, argv, ROS_NODE_NAME);

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>(ROS_PUB_CHAT, 1000);

  ros::Rate loop_rate(LOOP_RATE);

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = text_count(count);

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}
