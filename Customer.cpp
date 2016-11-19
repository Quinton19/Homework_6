#include "Customer.h"

Customer::Customer(string name_, Address address_, string phone, string email)
{
	name = name_;
	address = new Address(address_.get_street_num(), address_.get_street_name, 
	phone_num = phone;
	email_address = email;
}

string Customer::get_name()
{
	return name;
}

Address Customer::get_address()
{
	return *address;
}

string Customer::get_phone_num()
{
	return phone_num;
}

string Customer::get_email_address()
{
	return email_address;
}

string Customer::to_string()
{

}