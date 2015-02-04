
default: check

#xacro_files=$(shell find . -name \*.urdf.xacro)
xacro_files=pioneer-lx.urdf.xacro pioneer-lx-devil.urdf.xacro pioneer3dx.urdf.xacro pioneer3at.urdf.xacro
urdf_files=$(patsubst %.urdf.xacro,%.urdf,$(xacro_files))

check: $(urdf_files)
	for f in $(urdf_files); do echo ; echo $$f:; check_urdf $$f; done

check-%.urdf: %.urdf
	check_urdf $<

display-%: %.urdf
	roslaunch display.launch urdf:=$<

display-%.urdf: %.urdf
	roslaunch display.launch urdf:=$<

%.urdf: %.urdf.xacro
	rosrun xacro xacro.py $< >$@

%.urdf: %.xacro
	rosrun xacro xacro.py $< >$@

info:
	echo xacro_files=$(xacro_files)
	echo urdf_files=$(urdf_files)

.DUMMY: check info
