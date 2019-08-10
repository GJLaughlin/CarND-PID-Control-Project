#include "PID.h"
#include <numeric> 

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  prev_cte = 0;
  diff_cte = 0;
  int_cte = 0;
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
  diff_cte = cte - prev_cte;
  int_cte += cte;
  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
   return -Kp * prev_cte - Kd * diff_cte - Ki * int_cte;
}