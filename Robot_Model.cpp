#include "Robot_Model.h"

Robot_Model::Robot_Model(string n, int mn, double p, Head h, Torso t, Locomotor l, vector<Arm>* a, vector<Battery> b)
{
	name = n;
	model_num = mn;
	price = p;
	head = h;
	torso = t;
	locomotor = l;
	if (a->size() > 2 || a->size() < 1)
	{
		throw Arm_Limit{};
	}
	else
	{
		arms = *a;
	}
	if (b.size() < 1 || b.size() > torso.get_battery_compartments())
	{
		throw Battery_Limit{};
	}
	else
	{
		batteries = b;
	}
}

string Robot_Model::get_name()
{
	return name;
}

int Robot_Model::get_model_num()
{
	return model_num;
}

double Robot_Model::get_price()
{
	return price;
}

Head Robot_Model::get_head()
{
	return head;
}

Torso Robot_Model::get_torso()
{
	return torso;
}

Locomotor Robot_Model::get_locomotor()
{
	return locomotor;
}

vector<Arm> Robot_Model::get_arms()
{
	return arms;
}

vector<Battery> Robot_Model::get_batteries()
{
	return batteries;
}

void Robot_Model::set_price(double p)
{
	price = p;
}

void Robot_Model::add_arm(Arm a)
{
	if (arms.size() == 2)
		throw Arm_Limit{};
	else
		arms.push_back(a);
}

void Robot_Model::add_battery(Battery b)
{
	if (batteries.size() == torso.get_battery_compartments())
		throw Battery_Limit{};
	else
		batteries.push_back(b);
}

string Robot_Model::to_string()
{
	string result;
	result = "Model name: " + get_name() + "\n"
		+ "Model Number: " + Str_conversion::to_string(get_model_num()) + "\n"
		+ "Price: $" + Str_conversion::to_string(get_price()) + "\n";
	return result;
}

double Robot_Model::get_component_cost()
{
	double total;
	total = head.get_cost() + torso.get_cost() + locomotor.get_cost();
	for (Arm a : arms)
		total += a.get_cost();
	for (Battery b : batteries)
		total += b.get_cost();
	return total;
}