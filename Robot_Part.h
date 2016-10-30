#ifndef STDLIBFAC
#define STDLIBFAC 20
#include "helper_functions.h"

enum class Component_type { Head = 1, Locomotor, Torso, Battery, Arm };

class Robot_Part
{
private:
	string name;
	int part_num;
	double weight;
	double cost;
	string description;
	Component_type type;
public:
	Robot_Part(string n, int pn, double w, double c, string d, Component_type t);
	Robot_Part();
	string get_name();
	int get_part_num();
	double get_weight();
	double get_cost();
	string get_description();
	Component_type get_component_type();
	string get_component_type_str();
	virtual string to_string();
};
#endif