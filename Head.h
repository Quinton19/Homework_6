#include "Robot_Part.h"

class Head : public Robot_Part
{
private:
public:
	Head(string n, int pn, double w, double c, string d);
	Head();
	string to_string();
};
