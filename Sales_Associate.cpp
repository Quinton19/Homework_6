#include "Sales_Associate.h"

Sales_Associate::Sales_Associate(string name_, int emp_num)
{
	name = name_;
	employee_num = emp_num;
}

string Sales_Associate::get_name() const
{
	return name;
}

int Sales_Associate::get_employee_num() const
{
	return employee_num;
}

string Sales_Associate::to_string()
{
	string result;

	result = "Name: " + get_name() + "\n"
		+ "Employee #" + Str_conversion::to_string(get_employee_num()) + "\n";

	return result;
}

bool Sales_Associate::operator==(const Sales_Associate & other)
{
	return other.get_employee_num() == get_employee_num();
}

bool Sales_Associate::operator!=(const Sales_Associate & other)
{
	return !(*this == other);
}
