cmake_minimum_required(VERSION 2.8.3)
project(bebop_arduino)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  rosserial_arduino
  rosserial_client
  roscpp
  rospy
  std_msgs
  bebop_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs bebop_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../bebop_msgs/include
)

rosserial_generate_ros_lib(
  PACKAGE rosserial_arduino
  SCRIPT make_libraries.py
)

add_dependencies(bebop_arduino_ros_lib
  bebop_msgs_generate_messages_cpp
  bebop_msgs_generate_messages_py
)

rosserial_configure_client(
  DIRECTORY firmware
  TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(firmware chassis ALL)
rosserial_add_client_target(firmware chassis-upload)
