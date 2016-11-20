#include "Robot_Part.h"

#ifndef TORSO_
#define TORSO_ 727119
class Compartment_Limit{};

class Torso : public Robot_Part
{
private:
	int battery_compartments;
public:
	Torso(string n, int pn, double w, double c, string d, int bc);
	Torso();
	int get_battery_compartments();
	string to_string();
};
#endif