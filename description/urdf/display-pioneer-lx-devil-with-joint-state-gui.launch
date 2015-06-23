<launch>
	<arg name="urdf" value="pioneer-lx-devil.urdf" />
	<arg name="joint_state_gui" default="true" />
	<param name="robot_description" textfile="$(arg urdf)" />
	<param name="use_gui" value="$(arg joint_state_gui)"/>
	<node name="joint_state_publisher" pkg="joint_state_publisher" type="joint_state_publisher" />
	<node name="robot_state_publisher" pkg="robot_state_publisher" type="state_publisher" />
	<node name="rviz" pkg="rviz" type="rviz" args="-d $(find amr_robots_description)/urdf/display_urdf.rviz" required="true" />
</launch>
