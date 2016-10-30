#include "Head.h"

Head::Head(string n, int pn, double w, double c, string d) : Robot_Part(n, pn, w, c, d, Component_type::Head)
{}

Head::Head() : Robot_Part() {}

string Head::to_string()
{
	return Robot_Part::to_string();
}