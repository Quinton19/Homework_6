#include "PO_Box_Address.h"
#include "Apt_Address.h"
#include "Address.h"
#include <string>
#include <functional>

#ifndef CUSTOMER_
#define CUSTOMER_ 101010
class Customer
{
public:
	Customer(string name_, Address& address_, string phone, string email);
	string get_name() const;
	reference_wrapper<Address> get_address_ref() const;
	string get_phone_num() const;
	string get_email_address() const;
	string to_string();
	bool operator==(const Customer& other);
	bool operator!=(const Customer& other);
private:
	string name;
	string email_address;
	string phone_num;
	reference_wrapper<Address>* address;
};
#endif