

This directory contains some example launch files and other configuration that can
be used with the Gazebo simulator.

For more information about using Gazebo with ROS, start at 
http://wiki.ros.org/gazebo_ros_pkgs.  

Files:

example-pioneer3at-emptyworld.launch is an example launch file that runs Gazebo then
spawns a P3AT robot.  (Currently no sensors.)

You can then move the robot by publishing to the /cmd_vel topic, either:
1. Use rostopic
2. Use rviz:
	* Install rviz_plugin_tutorials
	* Run rviz
	* Select Add Panel... from the Panels menu
	* Select the teleop panel
	* Enter /cmd_vel as the output topic of the teleop panel
	* Drag within the telop panel


example.launch is an example launch file for spawning simulated robots from urdf
files in gazebo (if already running).  specify arguments with roslaunch:
  urdf  Path to URDF file
  robot Name of robot, used to find control configuration file, etc.

e.g.:

  roslaunch example.launch urdf:=../description/urdf/pioneer-lx.urdf.xacro robot:=pioneer-lx

If not specified, defaults to pioneer3dx.



