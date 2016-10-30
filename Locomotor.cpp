#include "Locomotor.h"

Locomotor::Locomotor(string n, int pn, double w, double c, string d, int ms, double pc) : Robot_Part(n, pn, w, c, d, Component_type::Locomotor)
{
	max_speed = ms;
	power_consumed = pc;
}

Locomotor::Locomotor() : Robot_Part() {}

int Locomotor::get_max_speed()
{
	return max_speed;
}

double Locomotor::get_power_consumed()
{
	return power_consumed;
}

string Locomotor::to_string()
{
	string result;
	result = Robot_Part::to_string() + "Max speed: " + Str_conversion::to_string(get_max_speed()) + " mph\n"
		+ "Power consumed: " + Str_conversion::to_string(get_power_consumed()) + " W\n";
	return result;
}