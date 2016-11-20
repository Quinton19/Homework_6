#include <string>
#include <ctime>
#include "Robot_Model.h"
#include "Sales_Associate.h"
#include "Customer.h"

using namespace std;

class Robot_Order
{
public:
	Robot_Order(Robot_Model& model_, int quantity_, Sales_Associate& associate, Customer& customer_);
	Robot_Model get_model();
	int get_quantity();
	double get_total_cost();
	Sales_Associate get_orderer();
	Customer get_customer();
	string get_order_time();
	string to_string();
private:
	Robot_Model* model;
	int quantity;
	time_t order_time;
	Sales_Associate* orderer;
	Customer* customer;
};