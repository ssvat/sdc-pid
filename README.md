# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Introduction
This project is to use PID control concept to keep the car staying on the track. The output of the PID controller in this project is the steering angle.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Algorithms
It includes PID but does not include twiddle as manual tuning is enough for completing the first run. The P.I.D. control parameter final values are:
Kp_= 0.2, the proportional term
Ki_ = 0.00, the integral term
Kd_ = 3.0, the differential term
Kp may be big, resulting in more oscillation shown in the video but this is the best result for this scenario. Ki is the systematic bias and set to zero. Kd is preventing to cause a big CTE. 

The result is being placed at: https://youtu.be/1VrCAPzAoQY


