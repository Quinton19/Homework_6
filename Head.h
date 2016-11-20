#include "Robot_Part.h"

#ifndef HEAD_
#define HEAD_ 112216
class Head : public Robot_Part
{
private:
public:
	Head(string n, int pn, double w, double c, string d);
	Head();
	string to_string();
};
#endif
