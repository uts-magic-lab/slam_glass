# Real-time indoor SLAM with glass detection
This code is a modified version of glam code (v39).
We add a glass detection algorithm and integrated it with the existing SLAM algorithm to produce maps with detected glass panels marked as solid wall objects. We developed and tested our algorithm and code on an unmodified PR2 robot platform.

## Compile source code
Clone the repository in a working catkin workspace.
run ```./configure``` under ```gmapping_glass/gmapping_export``` directory, then do ```cd ..;make -f Makefile.gmapping```.
After the libraries is compiled, go back to catkin root directory and compile the application with ```catkin_make```.

## Launch slam_glass service
```
roslaunch slam_glass slam_glass_pr2.launch
```

## Test dataset
You can download our test dataset [here](https://drive.google.com/open?id=1hb-OgI7ufrEHHgHtiSz6EZ7LgohXNc4o) and run it against slam_glass service node. Simply extract the bag files from the compressed file and use ```rosplay``` to playback the data files. You should hopefully produce a map similar to the following figure.

<img src="https://cloud.githubusercontent.com/assets/6646691/10475396/f3016798-728e-11e5-9904-7eca19055e98.png" width="200">

**Figure 1. SLAM with glass detection.**

If the same dataset is run against the default SLAM ROS package, the generated map will be similar to Figure 2.

<img src="https://cloud.githubusercontent.com/assets/6646691/10475464/a62dc208-728f-11e5-902d-4d0dd8d1c263.png" width="200">

**Figure 2. Default SLAM without glass detection.**

## Visualisation
Detected glasses can be visualised using ```rviz``` program. You will need to turn on the visualisation feature by uncommenting line 80 in ```CMakeFiles.txt``` and recompile slam_glass source code. The detected glass is marked in green colour in the grid map (see Figure 3). You can also visualse the robot trajectory by adding a visual marker and subscribe to ```/slam_glass/robot_trajectory```.

<img src="https://cloud.githubusercontent.com/assets/6646691/14004879/b2d76b52-f1b1-11e5-9ea7-a1b7ed77d694.png" width="200">

**Figure 3. Visualise detected glass and robot trajectory.**

## Citing this work
If you use this code in your project, please cite the following reference.
```
@article{Wang201797,
title = "Detecting glass in Simultaneous Localisation and Mapping",
journal = "Robotics and Autonomous Systems",
volume = "88",
pages = "97 - 103",
year = "2017",
issn = "0921-8890",
doi = "http://dx.doi.org/10.1016/j.robot.2016.11.003",
author = "Xun Wang and JianGuo Wang"
}
```
