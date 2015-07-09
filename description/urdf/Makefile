
default: check

#xacro_files=$(shell find . -name \*.urdf.xacro)
xacro_files=pioneer-lx.urdf.xacro pioneer-lx-devil.urdf.xacro pioneer3dx.urdf.xacro pioneer3at.urdf.xacro powerbot.urdf.xacro
urdf_files=$(patsubst %.urdf.xacro,%.urdf,$(xacro_files))

check: $(urdf_files)
	if ! test -x /usr/bin/check_urdf; then echo "The check_urdf tool is required. Install liburdfdom-tools."; exit 1; fi 
	for f in $(urdf_files); do echo ; echo $$f:; check_urdf $$f; done

check-%.urdf: %.urdf
	check_urdf $<

display-%: %.urdf
	roslaunch display.launch urdf:=$<

display-%.urdf: %.urdf
	roslaunch display.launch urdf:=$<

%.urdf: %.urdf.xacro
	mv $@ $@.bak; rosrun xacro xacro.py $< >$@ || mv $@.bak $@

%.urdf: %.xacro
	mv $@ $@.bak; rosrun xacro xacro.py $< >$@ || mv $@.bak $@

info:
	echo xacro_files=$(xacro_files)
	echo urdf_files=$(urdf_files)

.DUMMY: check info
