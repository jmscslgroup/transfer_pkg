<img src="https://raw.githubusercontent.com/jmscslgroup/transfer_pkg/main/assets/transfer_package.png" alt="Transfer Package" align="center" width=500/>

# Transfer Package

ROS package for hosting launch files, etc to facilitate automation of transfer test.


## Installing libpanda
The first prerequisite for the transfer test of the controller is `libpanda`. See the following instructions to install libpanda:

Clone the libpanda in your /opt folder
```
sudo apt-get install libusb-1.0-0-dev
cd /opt
sudo git clone https://github.com/jmscslgroup/libpanda
cd libpanda
sudo mkdir build
cd build
sudo cmake ..
sudo make

```

Testing controllers in SWIL requires Simulated vehicles. We use Steer package for vehicle simulation. In addition to that, we will need a few more packages.
Clone following repositories in the `src` directory of your catkin workspace. These packages are also common for HWIL testing. For this instruction, I am assuming, your catkin workspace is the directory `~/catkin_ws` but you should modify the instruction as per your situation.


```
cd ~/catkin_ws/src
git clone https://github.com/jmscslgroup/steer
git clone https://github.com/jmscslgroup/hoffmansubsystem
git clone https://github.com/jmscslgroup/throttle_control
git clone https://github.com/jmscslgroup/followerstoppermax4rl
git clone https://github.com/jmscslgroup/followerstoppermax
git clone https://github.com/jmscslgroup/followerstopperth
git clone https://github.com/jmscslgroup/micromodel
git clone https://github.com/jmscslgroup/trajectory_07_05_2021_real
git clone https://github.com/jmscslgroup/velocity_controller
git clone https://github.com/jmscslgroup/integrator
git clone https://github.com/jmscslgroup/margin
git clone https://github.com/jmscslgroup/can_to_ros
git clone https://github.com/jmscslgroup/transfer_pkg

```

Once you clone your package you need to compile them. If you already have them cloned, do the `git pull` to make sure you have the lates version of each packages.

```
cd ~/catkin_ws/
catkin_make
```


## Testing controllers in SWIL
There are a number of controllers that can be tested. The available controllers to be tested are enumerated below. They will be updated as we have more controllers to be tested:

1. **followerstopperth**
2. **followerstopperth_margin**
3. **followerstoppermax**
4. **followerstoppermax_margin**
5. **micromodel**
6. **mocromodel_margin**
7. **rl0705**
8. **rl0705_margin**
9. **rl0705_fs** = rl controller with followerstopperth
10. **rl0705_margin_fs** = rl controller with margin and followerstopperth


Following steps can be taken to test the available controller:

_**Terminal 1:**_
```
roslaunch transfer_pkg default_swil.launch bagfile:=start_at_0mph.bag
```
`default_swil.launch` starts ROS-Gazebo simulation with two vehicle separated at 30 m (minus the lenght of vehicle) apart. A LiDAR mounted on the front bumper of the ego car measures its current distance from the leader vehicle at the rate of 20 Hz. Bag files are used to impart velocity profile to the leader car. The list of available bag files are available at https://github.com/jmscslgroup/transfer_pkg. Only the filename of the bag file needs to be supplied and **NOT** the full path. If you need to add more bagfiles, place them in the launch subdirectory of `transfer_pkg`. 

_**Terminal 2: **_

```
roslaunch transfer_pkg test.launch test:=followerstopperth
```

or
 
```
roslaunch transfer_pkg test.launch test:=1
```

The test can be chosed from the enumerated list given above. You can either pass the number as value of the argument `test` or its name, for example `rl0705`. The `test.launch` will start launch files corresponding the test ID or test name provided through the roslaunch commandline argument. The `test.launch` also starts `rosbag record` to record ros messages in a time-stamped subdirectory of the directory ~/.ros/ along with a csv file that contains all values ros parameters. 

_**Terminal 3:**_
```
gzclient
```
You can launch gazebo client to visualize the simulation.


Once you are done with the test, you can terminate the test by pressing Ctrl-C in each of the three terminals mentioned above. The bagfile and csvfile for this test will be availble in a time-stamped subdirectory of the directory `~/.ros`.







