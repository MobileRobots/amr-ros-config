
This directory contains URDF model descriptions of some AMR robots.

urdf    Contains URDF descriptions (xacro/xml formats) as well as some launch
        files that display them in rviz.

model   Contains visual models

meshes  Contains lower resolution meshes for simulation, collision, etc.

src     Contains some urdf publisher source code


Things to try
-------------

Convert XACRO file to plain-XML URDF file:

  rosrun xacro xacro.py file.urdf.xacro >file.urdf

Validate URDF file syntax:

  check_urdf <urdffile>

e.g.:

  check_urdf urdf/pioneer-lx.urdf.xacro

There is a Makefile in the urdf directory that converts all xacro files
to plain-xml urdf and runs `check_urdf` on it.

Display URDF visually in rviz:

  roslaunch urdf/display.launch urdf:=urdf/pioneer-lx.urdf.xacro

(Note that this is the URDF model only, there is no robot control
interface and no robot data available including `tf` data.)

Display URDF in bare bones empty gazebo world: (with no control interface yet)

  roslaunch urdf/gazebo.launch urdf:=urdf/pioneer-lx.urdf.xacro robot:=pioneer-lx

