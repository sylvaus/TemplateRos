/**
 * File description
 */

#include "algo.hpp"
#include "main_cfg.hpp"
#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, ROS_NODE_NAME);

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>(ROS_PUB_CHAT, 1000);
  ros::Subscriber sub = n.subscribe(ROS_SUB_CHAT, 1000, chatterCallback);

  ros::Rate loop_rate(LOOP_RATE);

  int count = 0;
  while (ros::ok()) {
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
