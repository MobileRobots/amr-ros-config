
This directory contains URDF model descriptions of some AMR robots.

urdf    Contains URDF descriptions (xacro and URDF xml formats) as well as some launch
        files that display them in rviz.

model   Contains visual models

meshes  Contains lower resolution meshes for simulation, collision, etc.

src     Contains some urdf publisher source code (not normally needed, since 
        robot_state_publisher can usually be used, or some ROS tools such as
        rviz can load the URDF directly)



Display URDF visually in rviz
-----------------------------

    roslaunch urdf/display.launch urdf:=urdf/pioneer-lx.urdf

(Note that this is the URDF model only, there is no robot control
interface and no robot data available including `tf` data.)

Display URDF in bare bones empty gazebo world: (with no control interface yet)

    roslaunch urdf/gazebo.launch urdf:=urdf/pioneer-lx.urdf robot:=pioneer-lx

Note: Make sure to reference the plain-XML URDF files (".urdf"), not the Xacro
files (".xacro").  If you reference the Xacro, tools may be able to parse 
part of the description but won't find any results of Xacro inclusions or macros
resulting in errors about missing elements.

Available Models
----------------

Please submit bug reports and any patches, pull requests, or any feedback to https://github.com/MobileRobots (use issue tracker and pull requests)

### Pioneer3 DX ###

URDF file: urdf/pioneer3dx.urdf

Not working correctly in Gazebo.  Joint relationships and correct tf broadcast may not be working yet.

No accessory configurations available yet.

### Pioneer3 AT ###

URDF file: urdf/pioneer3at.urdf

Mostly working OK in Gazebo.

No accessory configurations available yet.

### Pioneer LX ###

URDF file: urdf/pioneer-lx.urdf

Not working correctly yet in Gazebo.  Joint relationships and correct tf broadcast probably working.  Wheels, casters, and wheel suspensions not modelled yet.  Needs better visual color.

Accessory configurations: Pioneer Manipulator with Jaco2 arms available as pioneer-lx-devil.urdf.


### Seekur Jr. ###

URDF file: urdf/seekur-jr.urdf

Still a major work in progress. Help needed!

### Powerbot ###

URDF file: urdf/powerbot.urdf

Barely there, just a big yellow box! Help needed!

### AmigoBot ###

Not started. Help needed!


### Seekur ###

Not started. Help needed!



How to compile URDF from XACRO files
------------------------------------

If you modify any XACRO files, the you must
re-generate the plain-XML URDF file from it.
You can use the Makefile in the urdf directory,
or do it manually using xacro.py.

Manually convert XACRO file to plain-XML URDF file:

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


