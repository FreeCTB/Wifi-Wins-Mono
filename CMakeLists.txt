cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation)

##find pcl
find_package(PCL REQUIRED)


## Declare ROS messages and services
add_message_files(FILES Num.msg Position.msg)
add_service_files(FILES AddTwoInts.srv )

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
#include_directories(include${catkin_INCLUDE_DIRS})
#include_directories(include${PCL_INCLUDE_DIRS})
include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})

#add_executable(talker src/talker.cpp)
#target_link_libraries(talker ${catkin_LIBRARIES})
#add_dependencies(talker beginner_tutorials_generate_messages_cpp)

#add_executable(listener src/listener.cpp)
#target_link_libraries(listener ${catkin_LIBRARIES})
#add_dependencies(listener beginner_tutorials_generate_messages_cpp)

#add_executable(path_listener src/path_listener.cpp)
#target_link_libraries(path_listener ${catkin_LIBRARIES})
#add_dependencies(path_listener beginner_tutorials_generate_messages_cpp)

add_executable(pcl_create src/pcl_create.cpp)
target_link_libraries(pcl_create ${catkin_LIBRARIES} ${PCL_LIBRARIES})
add_dependencies(pcl_create beginner_tutorials_generate_messages_cpp)

add_executable(path_tracker_listener src/path_tracker_node.cpp)
target_link_libraries(path_tracker_listener ${catkin_LIBRARIES})
add_dependencies(path_tracker_listener beginner_tutorials_generate_messages_cpp)


