#include "Robot_Order.h"
#include "helper_functions.h"

Robot_Order::Robot_Order(Robot_Model & model_, int quantity_, Sales_Associate & associate, Customer & customer_)
{
	model = new Robot_Model(model_);
	quantity = quantity_;
	orderer = new Sales_Associate(associate);
	customer = new Customer(customer_);
	time(&order_time);
}

Robot_Model Robot_Order::get_model()
{
	return *model;
}

int Robot_Order::get_quantity()
{
	return quantity;
}

double Robot_Order::get_total_cost()
{
	return get_model().get_price() * quantity;
}

Sales_Associate Robot_Order::get_orderer()
{
	return *orderer;
}

Customer Robot_Order::get_customer()
{
	return *customer;
}

string Robot_Order::get_order_time()
{
	return ctime(&order_time);
}

string Robot_Order::to_string()
{
	string result;

	result = "Date: " + get_order_time() + "\n"
		+ "Robot Model Ordered:\n" + get_model().get_name() + " -- #" + Str_conversion::to_string(get_model().get_model_num()) + "\n"
		+ "Amount ordered: " + Str_conversion::to_string(get_quantity()) + "\n"
		+ "Total amount due: $" + Str_conversion::to_string(get_total_cost()) + "\n"
		+ "Sales Associate ID: " + Str_conversion::to_string(get_orderer().get_employee_num()) + "\n"
		+ "Customer Name: " + get_customer().get_name() + "\n";

	return result;
}
