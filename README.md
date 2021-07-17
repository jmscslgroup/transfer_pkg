<img src="https://raw.githubusercontent.com/jmscslgroup/transfer_pkg/main/assets/transfer_package.png" alt="Transfer Package" align="center" width=500/>

# Transfer Package

ROS package for hosting launch files, etc to facilitate automation of transfer test

# Testing controllers in SWIL

Testing controllers in SWIL requires Simulated vehicles. We use Steer package for vehicle simulation. In addition to that, we will need a few more packages.
Clone following repositories in the `src` directory of your catkin workspace. For this instruction, I am assuming, your catkin workspace is the directory `~/catkin_ws` but you should modify the instruction as per your situation.


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
