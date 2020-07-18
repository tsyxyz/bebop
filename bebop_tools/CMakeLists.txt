cmake_minimum_required(VERSION 3.0.2)
project(bebop_tools)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  
  bebop_control_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp rospy std_msgs bebop_control_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../bebop_msgs/include
)

add_executable(chassis_test src/chassis_test.cpp)
target_link_libraries(chassis_test ${catkin_LIBRARIES} gflags)