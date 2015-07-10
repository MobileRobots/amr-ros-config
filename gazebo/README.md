

This directory contains some example launch files and other configuration that can
be used with the Gazebo simulator.

For more information about using Gazebo with ROS, start at <http://wiki.ros.org/gazebo_ros_pkgs>,
and also read the documentation at <http://gazebosim.org>, especially <http://gazebosim.org/tutorials?cat=connect_ros>

example-pioneer3at-world.launch is an example launch file that runs Gazebo with an 
empty world (unless you specify a `world_name` argument), then
spawns a P3AT robot.  (Currently no sensors.) 

You can then move the robot by publishing to the `/cmd_vel` topic, either:
1. Use rostopic
2. Use rviz:
	* Install `rviz_plugin_tutorials`:
		* For ROS jade: `sudo apt-get install ros-jade-rviz-plugin-tutorials`
		* For ROS indigo: `sudo apt-get install ros-indigo-rviz-plugin-tutorials`
	* Run rviz
	* Select Add Panel... from the Panels menu
	* Select the teleop panel
	* Enter `/cmd_vel` as the output topic of the teleop panel
	* Drag within the telop panel


example.launch is an example launch file for spawning simulated robots from urdf
files in gazebo (if already running).  specify arguments with roslaunch:
  urdf  Path to URDF file
  robot Name of robot, used to find control configuration file, etc.

e.g.:

  roslaunch example.launch urdf:=../description/urdf/pioneer-lx.urdf.xacro robot:=pioneer-lx

If not specified, defaults to pioneer3dx.


example-pioneer3at-terrainworld.launch and example-pioneer3at-moonworld.launch run Gazebo
in example environments defined by a heightmap.  For the moon enivironment to work you
may need to copy the apollo11_landing_site_1000x1000 model to your ~/.gazebo/models
directory, especially for older versions of Gazebo.  Note that gravity is moon-scale
in the moon environment, so behavior of the robot may be unusual.

If you have already launched Gazebo with a desired world and just want to create robots
plus other neccesary nodes (such as robot_state_publisher) for use with ROS, you can use
the `spawn-pioneer3at.launch`, `spawn-pioneer3dx.launch`, etc files, or use spawn.launch
but specify a `urdf` argument with the path to a URDF file for the robot to create.

