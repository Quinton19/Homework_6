#include "Torso.h"

Torso::Torso(string n, int pn, double w, double c, string d, int bc) : Robot_Part(n, pn, w, c, d, Component_type::Torso)
{
	if (bc > 3 || bc < 1)
		throw Compartment_Limit{};
	else
		battery_compartments = bc;
}

Torso::Torso() : Robot_Part() {}

int Torso::get_battery_compartments()
{
	return battery_compartments;
}

string Torso::to_string()
{
	string result;
	result = Robot_Part::to_string() + "Number of battery compartments: " + Str_conversion::to_string(get_battery_compartments()) + "\n";
	return result;
}