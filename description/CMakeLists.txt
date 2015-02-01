cmake_minimum_required(VERSION 2.8.3)
project(amr_robots_description)

find_package(catkin REQUIRED COMPONENTS geometry_msgs sensor_msgs std_msgs robot_state_publisher urdf)

catkin_package(
    CATKIN_DEPENDS robot_state_publisher urdf geometry_msgs sensor_msgs std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(amr_robot_publisher_generic src/publisher.cc)
target_link_libraries(amr_robot_publisher ${catkin_LIBRARIES})

install(TARGETS amr_robot_publisher
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(amr_robot_publisher_p3at src/publisher3at.cc)
add_executable(amr_robot_publisher_p3dx src/publisher3dx.cc)
target_link_libraries(amr_robot_publisher_p3at ${catkin_LIBRARIES})
target_link_libraries(amr_robot_publisher_p3dx ${catkin_LIBRARIES})

install(TARGETS amr_robot_publisher_p3at amr_robot_publisher_p3dx
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY 
   launch defs meshes models
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
