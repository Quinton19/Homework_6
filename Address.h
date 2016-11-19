#include<string>
using namespace std;
#ifndef ADDRESS_
#define ADDRESS_ 4320

class Address
{
public:
	Address(int st_num, string st_name, string city_, string state_, string zip);
	int get_street_num();
	string get_street_name();
	string get_city();
	string get_state();
	string get_zip_code();
	virtual string to_string();
private:
	int street_num;
	string street_name;
	string city;
	string state;
	string zip_code;
};
#endif