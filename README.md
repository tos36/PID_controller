# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Requirements

The vehicle must successfully drive a lap around the track. No tire may leave the drivable portion of the track surface. The car may not pop up onto ledges or roll over any surfaces that would otherwise be considered unsafe (if humans were in the vehicle).

## Reflection

### Effect of PID parameters

1. P parameter

     As p parameter get larger, the car reachs the target position sooner but this cause an overshoot. As p parameter get smaller, the overshoot calm down but response get slower.
 
2. D parameter

     D parameter helps the car to surpress an overshoot. However too high D parameter cause small hunting.

3. I parameter

      I parameter helps the car to surpress hunting or overshoot. However as this parameter get larger, the time to reach the target position get longer.

### How the final hyperparameters chosen

I chose the hyperparameters (P, I, D) as (0.17, 0.002, 1.5) with manual tuning. In this section I explain how I choose them.

1. P parameter tuning

     Firstly, I set I and D as 0 and change the P only to find enough p-gain. When P parameter exceed 0.1 the car start over shooting. The car completely overshoot whent P=0.2. I set P as 1.5 at this point.

2. D parameter tuning

     Then I introduce D parameter to surpress the overshooting. I set D as 0.8 at this point. The car can drive trough the course, but sometimes the responce is slow when it comes to a curve.

3. P & D parameter tuning

     Next, I tuned P & D simulteniouslly to make the car to responce more quicklly. I set P as 0.17 and D as 1.5 at this point. The car can drive a cureve more smoothly, but there was a hunting when the car drive a straight road.
 
4. I parameter tuning

     Finally, I introduced I parameter to surpress the hunting. I test with o.o1 and o.oo1. When I=0.01 the car get out of the road since the gain is too high. When I=0.001 the car drives nicely on the straight road. I set I parameter as 0.002 finally.
