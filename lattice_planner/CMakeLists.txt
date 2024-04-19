cmake_minimum_required(VERSION 3.0.2)
project(lattice_planner)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES SimplePathPlanner
#  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy
#  DEPENDS system_lib
)

add_executable(simple_path_planner
        src/simple_path_planner.cpp
        )
target_link_libraries(simple_path_planner
        ${catkin_LIBRARIES}
        )

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

