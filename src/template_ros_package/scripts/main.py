#!/usr/bin/env python
"""
File description
"""

import rospy
import algo
from std_msgs.msg import String

ROS_NODE_NAME = 'talker_py'
ROS_PUB_CHAT = 'chatter_py'
LOOP_RATE = 10


def main():
    pub = rospy.Publisher(ROS_PUB_CHAT, String, queue_size=10)
    rospy.init_node(ROS_NODE_NAME, anonymous=True)
    rate = rospy.Rate(LOOP_RATE)  # 10hz
    while not rospy.is_shutdown():
        hello_str = algo.get_text(rospy.get_time())
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
