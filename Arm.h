#include "Robot_Part.h"

#ifndef ARM_
#define ARM_ 7
class Arm : public Robot_Part
{
private:
	double power_consumed;
public:
	Arm(string n, int pn, double w, double c, string d, double pc);
	double get_power_consumed(); //units: watts
	string to_string();
};
#endif