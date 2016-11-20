#include "Robot_Part.h"

#ifndef LOCOMOTOR_
#define LOCOMOTOR_ 122516
class Locomotor : public Robot_Part
{
private:
	int max_speed;
	double power_consumed;
public:
	Locomotor(string n, int pn, double w, double c, string d, int ms, double pc);
	Locomotor();
	int get_max_speed(); //units: mph
	double get_power_consumed(); //units: watts
	string to_string();
};
#endif