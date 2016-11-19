#include "Apt_Address.h"

int Apt_Address::get_apt_num()
{
	return apt_num;
}

string to_string()
{
	string result;

	result = Str_conversion::to_string(get_street_num()) + " " + get_street_name() + "Apt. " + Str_conversion::to_string(get_apt_num()) + "\n"
		+ get_city() + ", " + get_state() + " " + get_zip_code() + "\n";

	return result;
}