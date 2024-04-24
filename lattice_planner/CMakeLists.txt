cmake_minimum_required(VERSION 3.0.2)
project(lattice_planner)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  visualization_msgs
  message_generation
)


add_message_files(
        FILES
        pathArray.msg
)

generate_messages(
        DEPENDENCIES
        std_msgs
        nav_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES SimplePathPlanner
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)

add_executable(simple_path_planner
        src/simple_path_planner.cpp
        )
target_link_libraries(simple_path_planner
        ${catkin_LIBRARIES}
        )

add_executable(fake_obstacle_publisher
        src/fake_obstacle_publisher.cpp
        )
target_link_libraries(fake_obstacle_publisher
        ${catkin_LIBRARIES}
        )

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

