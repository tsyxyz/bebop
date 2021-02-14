cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_CXX_STANDARD 11)

include_directories(${ROS_LIB_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../../bebop_msgs/include
)

# Remove this if using an Arduino without native USB (eg, other than Leonardo)
add_definitions(-DUSB_CON)

generate_arduino_firmware(chassis
  SRCS chassis.cpp ${ROS_LIB_DIR}/time.cpp
  BOARD uno
  PORT /dev/ttyACM0
)
