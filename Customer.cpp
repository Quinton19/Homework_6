#include "Customer.h"

Customer::Customer(string name_, Address& address_, string phone, string email)
{
	name = name_;
	address = new reference_wrapper<Address>{ address_ };
	phone_num = phone;
	email_address = email;
}

string Customer::get_name() const
{
	return name;
}

reference_wrapper<Address> Customer::get_address_ref() const
{
	return *address;
}

string Customer::get_phone_num() const
{
	return phone_num;
}

string Customer::get_email_address() const
{
	return email_address;
}

string Customer::to_string()
{
	string result;

	result = "Name: " + get_name() + "\n"
		+ "Phone Number: " + get_phone_num() + "\n"
		+ "Email: " + get_email_address() + "\n"
		+ "Address:\n" + get_address_ref().get().to_string() + "\n";

	return result;
}

bool Customer::operator==(const Customer & other)
{
	bool is_equal = true;

	if (other.get_name().compare(get_name()) != 0)
		is_equal = false;
	if (other.get_address_ref().get().to_string().compare(get_address_ref().get().to_string()) != 0)
		is_equal = false;
	if (other.get_phone_num().compare(get_phone_num()) != 0)
		is_equal = false;
	if (other.get_email_address().compare(get_email_address()) != 0)
		is_equal = false;

	return is_equal;
}

bool Customer::operator!=(const Customer & other)
{
	return !(*this == other);
}
