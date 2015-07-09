
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

You will need to install liburdfdom-tools to get `check_urdf`:
  
  sudo apt-get install liburdfdom-tools

There is a Makefile in the urdf directory that converts all xacro files
to plain-xml urdf and also runs `check_urdf` on them:

    cd src/amr-ros-config/description/urdf
    make

Display URDF visually in rviz:

    roslaunch urdf/display.launch urdf:=urdf/pioneer-lx.urdf

(Note that this is the URDF model only, there is no robot control
interface and no robot data available including `tf` data.)

Display URDF in bare bones empty gazebo world: (with no control interface yet)

    roslaunch urdf/gazebo.launch urdf:=urdf/pioneer-lx.urdf robot:=pioneer-lx

Note: Make sure to reference the plain-XML URDF files (".urdf"), not the Xacro
files (".xacro").  If you reference the Xacro, tools may be able to parse 
part of the description but won't find any results of Xacro inclusions or macros
resulting in errors about missing elements.

