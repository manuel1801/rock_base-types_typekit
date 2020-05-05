cmake_minimum_required(VERSION 2.8.3)

project(rock_base-types_typekit)

find_package(catkin REQUIRED COMPONENTS rtt_ros)

catkin_package(
  CATKIN_DEPENDS rtt_ros 
)

add_definitions(-DRTT_COMPONENT)

orocos_component(${PROJECT_NAME} src/test_component.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

orocos_library(rock_typekit 
  src/rock_typekit.cpp
  src/my_type.cpp
  # src/Waypoint.cpp
)
target_link_libraries(rock_typekit ${catkin_LIBRARIES} ${USE_OROCOS_LIBRARIES})

orocos_generate_package()

install(FILES  
  start.ops 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})