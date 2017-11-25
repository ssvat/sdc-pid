#include "PID.h"
#include <iostream>
#include <limits>
/*
 * Initialize PID control, update the cross-track error, update PID
 * coefficients, Twiddle, and calculate the total error (steering angle).
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /*
   * Initialize PID controller with the coefficients as the input values.
   * Note that the inputs to the function need different names than the
   * class variables or this will not work correctly.
   */
  //
  Kp = Kp_;  // Proportional term
  Ki = Ki_;  // Integral term
  Kd = Kd_;  // Differential term

  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {
  /*
   * Updates error values for calculating total error below.
   */

  // Difference between the current and previous CTE
  d_error = (cte - p_error);
  // Set to the new CTE
  p_error = cte;
  // Sum up CTEs to the integral term
  i_error += cte;

}

double PID::TotalError() {

  // Return the total error of each coefficient multiplied by the respective error
  // Steer in propotion to cross track error
  return -Kp * p_error - Kd * d_error - Ki * i_error;
  // Twiddle effect is not considered yet.
}
