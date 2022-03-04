# Go Chase It Udacity Robotics ND

![image](https://github.com/amrtariq/GoChaseIt_Udacity_Robotics_ND/blob/main/GoChaseIt.gif)

- Build a robot in URDF.
- Add Camera to Robot.
- Use Gazebo Plugin to Move it.
- Make CPP Service to move robot.
- Make a node to find and track white ball.

## Structure
```
.Go Chase It Project
├── my_robot                       # my_robot package                   
│   ├── launch                     # launch folder for launch files   
│   │   ├── robot_description.launch
│   │   ├── world.launch
│   ├── meshes                     # meshes folder for sensors
│   │   ├── hokuyo.dae
│   ├── urdf                       # urdf folder for xarco files
│   │   ├── my_robot.gazebo
│   │   ├── my_robot.xacro
│   ├── world                      # world folder for world files
│   │   ├── <yourworld>.world
│   ├── CMakeLists.txt             # compiler instructions
│   ├── package.xml                # package info
├── ball_chaser                    # ball_chaser package                   
│   ├── launch                     # launch folder for launch files   
│   │   ├── ball_chaser.launch
│   ├── src                        # source folder for C++ scripts
│   │   ├── drive_bot.cpp
│   │   ├── process_images.cpp
│   ├── srv                        # service folder for ROS services
│   │   ├── DriveToTarget.srv
│   ├── CMakeLists.txt             # compiler instructions
│   ├── package.xml                # package info                  
└──                                                        
```
## Clone and Build
Step 1: Create new catkin_ws

Step 2: Clone the repo into /src folder

Step 3 : Create a build directory and compile the code
```
$ cd ~/catkin_ws
$ catkin_make
```
Step 4 : Launch myworld
```
$ cd (your catkin workspace dir)
$ source devel/setup.bash
$ roslaunch my_robot world.launch

```
Step 5: In new Terminal, Launch ball_chaser and drive_bot nodes
```
$ cd (your catkin workspace dir)
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

