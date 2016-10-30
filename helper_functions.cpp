#include "helper_functions.h"
#include <sstream>

string Str_conversion::to_string(int n)
{
	string result;
	ostringstream convert;
	convert << n;
	result = convert.str();
	return result;
}

string Str_conversion::to_string(double d)
{
	string result;
	ostringstream convert;
	convert << d;
	result = convert.str();
	return result;
}