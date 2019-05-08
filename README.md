# CarND-Controls-PID

---
## Introduction
This project is to use PID control concept to keep the car staying on the track on the simulator by testing my sollution codes. The codes contains buidling PID controller (PID.h, PID.cpp, and main.cpp) and tuning PID hyperparamters. The output of the PID controller in this project is the steering angle. The car is controlled to steer in proportion to the Cross Trackk Error (CTE).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Algorithms and Tuning Parameters
The cross track error, cte, is the current y position of the robot along the x-axis. To get the steering value, it is to multiply the tau parameter with the cte. The car moves based on the speed and controlled steer values. 

It includes PID but does not include twiddle as manual tuning is enough for completing the first run. The final values of the P.I.D. control parameter are:
Kp_= 0.2, the proportional term,
Ki_ = 0.00, the integral term, and
Kd_ = 3.0, the differential term.
The purpose of the integral term is to track of all the previous CTEs. The int_cte is initialized to zero and the current cte term is added to the count int_cte += cte. The differental term is the difference between the current CTE and previous CTE. Finally the steering value was updated by -tau_p * cte - tau_d * diff_cte - tau_i * int_cte. 

Kp may be big, resulting in more oscillation shown in the video but this is the best result for this scenario. Ki is the systematic bias and set to zero. The integral term is to compensate for biases and this system is assumed without bias. Kd is to prevent from a big CTE. 

The final control parameters managed to have the car finish the first track after tuning each individually starting from zero. It is also found that large values can cause extremely high steering angles, leading to crash while small values cause failure of the car in the large or shapr turn of the track or the car off the track.

The result video is being placed at: https://youtu.be/1VrCAPzAoQY


