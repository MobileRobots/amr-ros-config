
This directory contains URDF model descriptions of some AMR robots.

urdf    Contains URDF descriptions (xacro/xml formats) as well as some launch
        files that display them in rviz.

model   Contains visual models

meshes  Contains lower resolution meshes for simulation, collision, etc.

src     Contains some urdf publisher source code


Things to try
-------------

Validate URDF file syntax:

  check_urdf <urdffile>

e.g.:

  check_urdf urdf/pioneer-lx.urdf.xacro

Display URDF visually in rviz:

  roslaunch urdf/display.launch model:=urdf/pioneer-lx.urdf.xacro

Display URDF in bare bones empty gazebo world, with no control:

  roslaunch urdf/gazebo.launch urdf:=urdf/pioneer-lx.urdf.xacro robot:=pioneer-lx

