

example.launch is an example launch file for spawning simulated robots from urdf
files in gazebo.  specify arguments with roslaunch:
  urdf  Path to URDF file
  robot Name of robot, used to find control configuration file, etc.

e.g.:

  roslaunch example.launch urdf:=../description/urdf/pioneer-lx.urdf.xacro robot:=pioneer-lx

This will also assume pioneer-lx-control.yaml as the control configuration.

If not specified, defaults to pioneer3dx.
