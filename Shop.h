#include "Robot_Model.h"
#include "Customer.h"
#include "Sales_Associate.h"
#include "Robot_Order.h"

class Part_Num_Exists {};
class Model_Num_Exists {};
class Missing_Parts {};
class Customer_Exists {};
class Sales_Associate_Exists {};
/*
class Part_Num_DNE {};
class Invalid_Model {};
*/

class Shop
{
private:
	vector<Robot_Model> models;
	vector<Head> heads;
	vector<Torso> torsos;
	vector<Locomotor> locomotors;
	vector<Arm> arms;
	vector<Battery> batteries;
	vector<Customer> customers;
	vector<Sales_Associate> sales_associates;
	vector<Robot_Order> orders;
	static int num_rand_heads;
	static int num_rand_torsos;
	static int num_rand_locomotors;
	static int num_rand_arms;
	static int num_rand_batteries;
	static int num_rand_models;
public:
	Shop();
	void add(Head h);
	void add(Torso t);
	void add(Locomotor l);
	void add(Arm a);
	void add(Battery b);
	void add(Robot_Model model);
	void add(Customer new_customer);
	void add(Sales_Associate new_associate);
	void add(Robot_Order new_order);
	vector<Robot_Model> get_models();
	void create_rand_part(); //for testing purposes only
	void create_rand_model(); //for testing purposes only
	vector<Head> get_available_heads();
	vector<Torso> get_available_torsos();
	vector<Locomotor> get_available_locomotors();
	vector<Arm> get_available_arms();
	vector<Battery> get_available_batteries();
	vector<Customer> get_customers();
	vector<Sales_Associate> get_sales_associates();
	vector<Robot_Order> get_orders();
	/*
	void remove(Head h);
	void remove(Torso t);
	void remove(Locomotor l);
	void remove(Arm a);
	void remove(Battery b);
	*/
};