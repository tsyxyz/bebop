cmake_minimum_required(VERSION 2.8.3)
project(bebop_msgs)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(DIRECTORY msg)

generate_messages(DEPENDENCIES std_msgs LANGS gencpp genpy)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp rospy std_msgs
)