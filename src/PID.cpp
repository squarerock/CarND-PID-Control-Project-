#include "PID.h"
// #define N 100
// #include <uWS/uWS.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	double steerValue = Kp*p_error + Ki*i_error + Kd*d_error;
	// Steer Value is expected to be between [-1, 1]
	steerValue = steerValue > 1 ? 1 : steerValue;
	steerValue = steerValue < -1 ? -1 : steerValue;
	return steerValue;
}

