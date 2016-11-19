#include "PO_Box_Address.h"
#include "Apt_Address.h"
#include "Address.h"
#include <string>
#include <functional>

class Customer
{
public:
	Customer(string name_, Address& address_, string phone, string email);
	string get_name();
	reference_wrapper<Address> get_address();
	string get_phone_num();
	string get_email_address();
	string to_string();
private:
	string name;
	string email_address;
	string phone_num;
	reference_wrapper<Address>* address;
};
