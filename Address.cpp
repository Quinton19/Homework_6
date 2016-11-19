#include "Address.h"
#include "helper_functions.h"
#include<iostream>

#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

Address::Address(int st_num, string st_name, string city_, string state_, string zip)
{
	street_num = st_num;
	street_name = st_name;
	city = city_;
	state = state_;
	zip_code = zip;
}

int Address::get_street_num()
{
	return street_num;
}

string Address::get_street_name()
{
	return street_name;
}

string Address::get_city()
{
	return city;
}

string Address::get_state()
{
	return state;
}

string Address::get_zip_code()
{
	return zip_code;
}

string Address::to_string()
{
	string result;
	
	result = Str_conversion::to_string(get_street_num()) + " " + get_street_name() + "\n"
		+ get_city() + ", " + get_state() + " " + get_zip_code() + "\n";

	return result;
}