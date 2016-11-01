
default: check

#xacro_files=$(shell find . -name \*.urdf.xacro)
xacro_files=\
  pioneer-lx.urdf.xacro \
  pioneer3dx.urdf.xacro \
  pioneer3at.urdf.xacro \
  powerbot.urdf.xacro \
  terabot-arm.urdf.xacro \
  seekurjr.urdf.xacro \
  pioneer3dx-lms200.urdf.xacro

urdf_files=$(patsubst %.urdf.xacro,%.urdf,$(xacro_files))
sdf_files=$(patsubst %.urdf,../../gazebo/%.sdf,$(urdf_files))

check: $(urdf_files)
	if ! test -x /usr/bin/check_urdf; then echo "The check_urdf tool is required. Install liburdfdom-tools."; exit 1; fi 
	for f in $(urdf_files); do echo ; echo $$f:; check_urdf $$f; done

check-%.urdf: %.urdf
	check_urdf $<

display-%: %.urdf
	roslaunch display-with-robotstate.launch urdf:=$<

display-%.urdf: %.urdf
	roslaunch display-with-robotstate.launch urdf:=$<

displayjs-%: %.urdf
	roslaunch display-with-joint-state-gui.launch urdf:=$<

%.urdf: %.urdf.xacro
	-mv $@ $@.bak
	rosrun xacro xacro --inorder $< >$@ || mv $@.bak $@ || rm @0

#%.urdf: %.xacro
#	mv $@ $@.bak; rosrun xacro xacro.py $< >$@ || mv $@.bak $@

%.sdf: %.urdf
	gz sdf --print $< >$@

../../gazebo/%.sdf: %.urdf
	gz sdf --print $< >$@

gazebo: $(sdf_files)

info:
	echo xacro_files=$(xacro_files)
	echo urdf_files=$(urdf_files)
	echo sdf_files=$(sdf_files)

.DUMMY: check info gazebo
