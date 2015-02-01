#!/bin/sh
set -x
set -e
test -n "$1"
rosrun xacro xacro.py $1 > tmp.urdf && check_urdf tmp.urdf && rm tmp.urdf
