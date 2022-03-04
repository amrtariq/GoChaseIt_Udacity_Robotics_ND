#include "ros/ros.h"

#include "std_msgs/Float64.h"
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"
   

ros::Publisher right_wheel_pub, left_wheel_pub, right_wheel_back_pub,  left_wheel_back_pub;
float wheel_radius =0.1;
float robot_radius=0.4472135955;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res)
{

    ROS_INFO("DriveToTarget received - linear_x:%1.2f, angular_z:%1.2f", (float)req.linear_x, (float)req.angular_z);

	
        // Set the arm joint angles
        std_msgs::Float64 right_wheel, left_wheel, zero;
        right_wheel.data = (req.linear_x/wheel_radius)+((req.angular_z*robot_radius/2)/wheel_radius);
        left_wheel.data =  (req.linear_x/wheel_radius)-((req.angular_z*robot_radius/2)/wheel_radius);
	zero.data=0;
        // Publish the arm joint angles
        right_wheel_pub.publish(right_wheel);
        left_wheel_pub.publish(left_wheel);
        right_wheel_back_pub.publish(right_wheel);
        left_wheel_back_pub.publish(left_wheel);


    // Wait 1 to make sure message sent
    //ros::Duration(1).sleep();

    // Return a response message
    res.msg_feedback = "Velocities set - linear_x: " + std::to_string(req.linear_x) + " , angular_z: " + std::to_string(req.angular_z);
    ROS_INFO_STREAM(res.msg_feedback);
    ROS_INFO_STREAM("R: "+std::to_string(req.linear_x+(req.angular_z/2))+"L: "+std::to_string(req.linear_x-(req.angular_z/2)));

    return true;
}

int main(int argc, char** argv)
{
	// Initialize a ROS node
    ros::init (argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Create a publisher that can publish a std_msgs::Float64 message on the /my_robot/right_wheel_hinge_velocity_controller/command topic
    right_wheel_pub = n.advertise<std_msgs::Float64>("/my_robot/right_wheel_hinge_velocity_controller/command", 10);
    // Create a publisher that can publish a std_msgs::Float64 message on the /my_robot/left_wheel_hinge_velocity_controller/command topic
    left_wheel_pub = n.advertise<std_msgs::Float64>("/my_robot/left_wheel_hinge_velocity_controller/command", 10);
    // Create a publisher that can publish a std_msgs::Float64 message on the /my_robot/right_wheel_back_hinge_velocity_controller/command topic
    right_wheel_back_pub = n.advertise<std_msgs::Float64>("/my_robot/right_wheel_back_hinge_velocity_controller/command", 10);
    // Create a publisher that can publish a std_msgs::Float64 message on the /my_robot/left_wheel_back_hinge_velocity_controller/command topic
    left_wheel_back_pub = n.advertise<std_msgs::Float64>("/my_robot/left_wheel_back_hinge_velocity_controller/command", 10);
    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
	    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);

    // TODO: Delete the loop, move the code to the inside of the callback function and make the necessary changes to publish the requested velocities instead of constant values

    // TODO: Handle ROS communication events
    ROS_INFO("Ready...");
    ros::spin();

    return 0;
}
