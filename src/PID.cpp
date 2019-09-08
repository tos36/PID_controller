#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  count = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  if(count==0){
    cte_prev = cte;
  }
  p_error = cte;
  d_error = cte - cte_prev;
  i_error += cte;
  
  cte_prev = cte;
  count += 1;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return Kp * p_error + Kd * d_error + Ki * i_error;  // TODO: Add your total error calc here!
}