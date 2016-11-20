#include "Address.h"
#include <string>

#ifndef APTADDRESS_
#define APTADDRESS_ 328
class Apt_Address : public Address
{
public:
	Apt_Address(int st_num, string st_name, string city_, string state_, string zip, int apt) : Address(st_num, st_name, city_, state_, zip) { apt_num = apt; }
	int get_apt_num();
	string to_string() override;
private:
	int apt_num;
};
#endif