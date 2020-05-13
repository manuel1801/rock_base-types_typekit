cmake_minimum_required(VERSION 2.8.3)

project(rock_base-types_typekit)

find_package(catkin REQUIRED COMPONENTS rtt_ros)
find_package(Eigen3 REQUIRED)
# include_directories(include  ${Boost_INCLUDE_DIR} ${EIGEN_INCLUDE_DIRS})
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})



catkin_package(
  CATKIN_DEPENDS rtt_ros 
)

add_definitions(-DRTT_COMPONENT)



include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

orocos_library(rock_typekit 
  src/rock_typekit.cpp
  src/my_type.cpp
  src/Waypoint.cpp
  src/Angle.cpp
  src/Pose.cpp
  # src/my_class_type.cpp
  src/JointState.cpp
)
target_link_libraries(rock_typekit ${catkin_LIBRARIES} ${USE_OROCOS_LIBRARIES})


orocos_component(${PROJECT_NAME} src/test_component.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} rock_typekit)

orocos_generate_package()

install(FILES  
  start.ops 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})