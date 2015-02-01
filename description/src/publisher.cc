/*
 * Software License Agreement (BSD License)
 *
 *  Hunter Allen <hunter.allen@vanderbilt.edu>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <kdl_parser/kdl_parser.hpp>

int main( int argc, char* argv[] )
{
  	ros::init(argc, argv, "state_publisher" );
  	ros::NodeHandle n;

  	ros::Publisher joint_state_publisher = n.advertise<sensor_msgs::JointState>("joint_states",1000);

 	tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(30);

    // message declarations
    geometry_msgs::TransformStamped odom_trans;
    sensor_msgs::JointState joint_state;
    //odom_trans.header.frame_id = "base_link";
    //odom_trans.child_frame_id = "";

  while (ros::ok())
  {
  	joint_state.header.stamp = ros::Time::now();
  	joint_state.name.resize(6); //Pioneer has 6 joint state definitions. 
  	joint_state.position.resize(6);

  	joint_state.name[0] = "base_top_joint";
  	joint_state.position[0] = 0;

  	joint_state.name[1] = "base_swivel_joint";
  	joint_state.position[1] = 0;

  	joint_state.name[2] = "swivel_hubcap_joint";
  	joint_state.position[2] = 0;

  	joint_state.name[3] = "center_wheel_joint";
  	joint_state.position[3] = 0; 

  	joint_state.name[4] = "base_front_joint";
  	joint_state.position[4] = 0;

  	joint_state.name[5] = "base_back_joint";
  	joint_state.position[5] = 0;

    //odom_trans.header.stamp = ros::Time::now();
  	//send the joint state information
  	joint_state_publisher.publish(joint_state);
    //broadcaster.sendTransform(odom_trans);

  	//adjust loop each iteration.
  	loop_rate.sleep();
  }//the things ros will do

  return 0; 
}//end main
