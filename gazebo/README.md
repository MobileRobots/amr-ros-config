

This directory contains some example launch files and other configuration that can
be used with the Gazebo simulator.

For more information about using Gazebo with ROS, start at <http://wiki.ros.org/gazebo_ros_pkgs>,
and also read the documentation at <http://gazebosim.org>, especially <http://gazebosim.org/tutorials?cat=connect_ros>


example-world.launch 
--------------------
An example roslaunch file that runs Gazebo with a simple empty world.
Use one of the "spawn" launch files (see below) to add robots.  Specify an alternate
world via `world` argument or modify the example world to add or change any of the objects (models) in the 
world.  Models can also be interactively added to a world from Gazebo: any models
found in ~/.gazebo/models, or installed on the system, or available from the 
gazebosim.world website will be listed in the "Models" list on the left panel in the
Gazbeo client GUi.

example-pioneer3at-world.launch 
-------------------------------
An example roslaunch file that runs Gazebo with an 
empty world (unless you specify a `world` argument), then
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


spawn.launch
------------
An example launch file for spawning simulated robots from urdf
files in gazebo if already running.  specify arguments with roslaunch:
  urdf  Path to URDF file
  name  Name of robot, only used an label in GUI

In addition to creating the robot in Gazebo, a `joint_state_publisher` and `robot_state_publisher` 
are launched as well.

e.g.:

  roslaunch spawn.launch urdf:=../description/urdf/pioneer-lx.urdf.xacro name:=pioneer-lx

If not specified, defaults to pioneer3dx robot model.

Other example launch files default to other robot models:
* `spawn-pioneer3at.launch`: Spawn a Pioneer 3-AT
* `spawn-pioneer3dx.launch`: Spawn a Pioneer 3-DX
* `spawn-pioneer-lx.launch`: Spawn a Pioneer LX
etc.


example-pioneer3at-terrainworld.launch and example-pioneer3at-moonworld.launch 
------------------------------------------------------------------------------
These roslaunch files run Gazebo
in example environments defined by a heightmap.  For the moon enivironment to work you
may need to copy the `apollo11_landing_site_1000x1000` model to your ~/.gazebo/models
directory, especially for older versions of Gazebo.  Note that gravity is moon-scale
in the moon environment, so behavior of the robot may be unusual.

If you have already launched Gazebo with a desired world and just want to create robots
plus other neccesary nodes (such as robot_state_publisher) for use with ROS, you can use
the `spawn-pioneer3at.launch`, `spawn-pioneer3dx.launch`, etc files, or use spawn.launch
but specify a `urdf` argument with the path to a URDF file for the robot to create.

