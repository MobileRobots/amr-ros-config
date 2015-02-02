amr-ros-config
==============

URDF, launch files, and other ROS configuration for AMR robots.

URDF
----

URDF descriptions can be found in the `description` subdirectory. 
The Pioneer 3 DX, Pioneer 3 AT and Pioneer 2 DX descriptions are
based on `p2os_urdf from Allen Hunter (Vanderbuilt) and from the
original `p2os` package.  The Pioneer LX URDF has been added
by Adept MobileRobots.

Launch files
------------

Some example launch files have been included in the `launch`
subdirectory.   

These launch files are intended to be copied and modified 
for your specific projects and robot configuration.

The `rosaria.launch` and `rosaria-rviz.launch` launch files
are the simplest, which provide the `rosaria` node (connects
to the robot), robot state publishers, URDF robot 
description (loaded from specified URDF file), and in 
the case of `rosaria-rviz.launch`, also run `rviz`.

Some of them have been adapted from launch files provided
by `p2os` packages.

They are generic for all types of robots,
so most require giving a `urdf` argument referencing a URDF
for a specific robot.   Inside the launch XML file, an
`<arg>` element declares this argument, and `$(arg urdf)`
appears where the name of the URDF file is used.  Therefore
you can either replace `$(arg urdf)` with the URDF file
for your specific robot type, or you can add a `default`
attribute to the `<arg>` element for `urdf` specifying
your robot's URDF file, so you can override it if needed.

Some launch files also take other arguments, such as
`joint_state_gui` (boolean) to display the joint state
publisher GUI window. 



