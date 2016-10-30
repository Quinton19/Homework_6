#include "Robot_Part.h"


Robot_Part::Robot_Part(string n, int pn, double w, double c, string d, Component_type t)
{
	name = n;
	part_num = pn;
	weight = w;
	cost = c;
	description = d;
	type = t;
}

Robot_Part::Robot_Part() {}

string Robot_Part::get_name()
{
	return name;
}

int Robot_Part::get_part_num()
{
	return part_num;
}

double Robot_Part::get_weight()
{
	return weight;
}

double Robot_Part::get_cost()
{
	return cost;
}

string Robot_Part::get_description()
{
	return description;
}

Component_type Robot_Part::get_component_type()
{
	return type;
}

string Robot_Part::get_component_type_str()
{
	if (type == Component_type::Head)
		return "head";
	else if (type == Component_type::Locomotor)
		return "locomotor";
	else if (type == Component_type::Torso)
		return "torso";
	else if (type == Component_type::Battery)
		return "battery";
	else if (type == Component_type::Arm)
		return "arm";
}

string Robot_Part::to_string()
{
	string result;
	result = "Name: " + get_name() + "\n"
		+ "Part Number: " + Str_conversion::to_string(part_num) + "\n"
		+ "Weight: " + Str_conversion::to_string(get_weight()) + " lb\n"
		+ "Cost: $" + Str_conversion::to_string(get_cost()) + "\n"
		+ "Description: " + get_description() + "\n";
	return result;
}