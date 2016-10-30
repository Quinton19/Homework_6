#include "Arm.h"

Arm::Arm(string n, int pn, double w, double c, string d, double pc) : Robot_Part(n, pn, w, c, d, Component_type::Arm)
{
	power_consumed = pc;
}

double Arm::get_power_consumed()
{
	return power_consumed;
}

string Arm::to_string()
{
	string result;
	result = Robot_Part::to_string() + "Power consumed: " + Str_conversion::to_string(get_power_consumed()) + " W\n";
	return result;
}