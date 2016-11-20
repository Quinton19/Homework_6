#include <string>
#include "helper_functions.h"
using namespace std;

#ifndef SALESASSOCIATE_
#define SALESASSOCIATE_ 1011
class Sales_Associate
{
public:
	Sales_Associate(string name_, int emp_num);
	string get_name() const;
	int get_employee_num() const;
	string to_string();
	bool operator==(const Sales_Associate& other);
	bool operator!=(const Sales_Associate& other);
private:
	string name;
	int employee_num;
};
#endif