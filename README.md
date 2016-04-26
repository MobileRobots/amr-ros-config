amr-ros-config
==============

URDF, launch files, and other ROS configuration for AMR robots.

This directory should be in your ROS package path. Either append it 
to the ROS_PACKAGE_PATH environment variable[1], or place it in the
"src" subdirectory of your catkin workspace[2].

URDF
----

URDF robot model descriptions can be found in the `description` subdirectory. This
directory contains a ROS package named `amr_robots_description`.
The Pioneer 3 DX and Pioneer 3 AT are
based on various sources including` p2os_urdf` from the allenh1 `p2os` package (Allen Hunter/Vanderbuilt
version), Dereck Wonnacott, the
original `p2os` package, and others.  Other URDF models have been added
by Adept MobileRobots.  Some URDF files might be useable as models
in Gazebo (see Gazebo below).

This repository has been started by MobileRobots as a single easy to find and maintain location,
but is also a collaborative effort among the user community, please submit any fixes and improvements using the
issue tracker or pull request.

Launch files
------------

Some example launch files have been included in the `launch`
subdirectory.   This directory contains a ROS package named
`amr_robots_launchfiles`.

These launch files are intended to be copied and modified 
for your specific projects and robot configuration.

The `rosaria.launch` and `rosaria+rviz.launch` launch files
are the simplest, which provide the `rosaria` node (connects
to the robot), robot state publishers, URDF robot 
description (loaded from specified URDF file), and in 
the case of `rosaria+rviz.launch`, also run `rviz`.

To launch `rosaria` plus joint state publishers and description, run:

    roslaunch rosaria.launch

Then use ROS command-line tools (`rostopic`, `rosservice`, etc.) 
or `rqt` to interact.  An example `rqt` configuration is provided
in `launch/rosaria_rqt_example.perspective`.  Install `rqt-rviz` 
to get the robot model visualization plugin for `rqt` (For
ROS indigo, install via `apt-get install ros-indigo-rqt-rviz`. For
ROS hydro, install via `apt-get install ros-hydro-rqt-rviz`).

The launch files are generic for all types of robots,
so most require giving a `urdf` argument referencing a URDF
for a specific robot.   Inside the launch XML file, an
`<arg>` element declares this argument, and `$(arg urdf)`
appears where the name of the URDF file is used.  Therefore
you can either replace `$(arg urdf)` with the URDF file
for your specific robot type, or you can add a `default`
attribute to the `<arg>` element for `urdf` specifying
your robot's URDF file, so you can override it if needed.
If `urdf` is not specified, a Pioneer 3 DX model is used by
default.

Some launch files also take other arguments, such as
`joint_state_gui` (boolean) to display the joint state
publisher GUI window. 


Gazebo
------

Some example Gazebo configuration can be found in the `gazebo`
directory. This directory contains a ROS package named
`amr_robots_gazebo` which can be used to reference files contained
within it from other launch files, etc.  

See gazebo/README.md for more information about using the 
Gazebo simulator.

See <http://wiki.ros.org/Robots/Pioneer> for more discussion
about the differences between using Gazebo and other ROS simulators , or 
rosaria with MobileSim or a real robot.



[1]: http://wiki.ros.org/ROS/EnvironmentVariables#ROS_PACKAGE_PATH
[2]: http://wiki.ros.org/catkin/Tutorials/create_a_workspace


