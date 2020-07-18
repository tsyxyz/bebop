cmake_minimum_required(VERSION 3.0.2)
project(bebop_control_msgs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(DIRECTORY msg)

generate_messages(DEPENDENCIES std_msgs LANGS gencpp genpy)

catkin_package(
  INCLUDE_DIRS .
  CATKIN_DEPENDS roscpp rospy std_msgs
)