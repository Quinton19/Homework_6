#include "Battery.h"

Battery::Battery(string n, int pn, double w, double c, string d, double e) : Robot_Part(n, pn, w, c, d, Component_type::Battery)
{
	energy = e;
}

double Battery::get_energy_contained()
{
	return energy;
}

string Battery::to_string()
{
	string result;
	result = Robot_Part::to_string() + "Energy contained: " + Str_conversion::to_string(get_energy_contained()) + " kWh\n";
	return result;
}