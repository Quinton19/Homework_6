#include "Shop.h"
#include <time.h>

int Shop::num_rand_models = 0;
int Shop::num_rand_heads = 0;
int Shop::num_rand_torsos = 0;
int Shop::num_rand_locomotors = 0;
int Shop::num_rand_arms = 0;
int Shop::num_rand_batteries = 0;
int Shop::num_rand_customers = 0;
int Shop::num_rand_associates = 0;

Shop::Shop()
{
	srand(time(NULL));
}

void Shop::add(Head h)
{
	for (Head head : heads)
	{
		if (head.get_part_num() == h.get_part_num())
			throw Part_Num_Exists{};
	}
	heads.push_back(h);
}

void Shop::add(Torso t)
{
	for (Torso torso : torsos)
	{
		if (torso.get_part_num() == t.get_part_num())
			throw Part_Num_Exists{};
	}
	torsos.push_back(t);
}

void Shop::add(Locomotor l)
{
	for (Locomotor locomotor : locomotors)
	{
		if (locomotor.get_part_num() == l.get_part_num())
			throw Part_Num_Exists{};
	}
	locomotors.push_back(l);
}

void Shop::add(Arm a)
{
	for (Arm arm : arms)
	{
		if (arm.get_part_num() == a.get_part_num())
			throw Part_Num_Exists{};
	}
	arms.push_back(a);
}

void Shop::add(Battery b)
{
	for (Battery battery : batteries)
	{
		if (battery.get_part_num() == b.get_part_num())
			throw Part_Num_Exists{};
	}
	batteries.push_back(b);
}

void Shop::add(Robot_Model model)
{
	for (Robot_Model rm : models)
	{
		if (rm.get_model_num() == model.get_model_num())
			throw Model_Num_Exists{};
	}
	models.push_back(model);
	/*
	try
	{
		remove(model.get_head());
		remove(model.get_torso());
		remove(model.get_locomotor());
		for (Arm arm : model.get_arms())
			remove(arm);
		for (Battery battery : model.get_batteries())
			remove(battery);
	}
	catch (Part_Num_DNE& e)
	{
		models.pop_back();
		throw Invalid_Model{};
	}
	*/
}

void Shop::add(Customer new_customer)
{
	for (Customer c : customers)
	{
		if (new_customer == c)
			throw Customer_Exists{};
	}
	customers.push_back(new_customer);
}

void Shop::add(Sales_Associate new_associate)
{
	for (Sales_Associate s : sales_associates)
	{
		if (new_associate == s)
			throw Sales_Associate_Exists{};
	}
	sales_associates.push_back(new_associate);
}

void Shop::add(Robot_Order new_order)
{
	orders.push_back(new_order);
}

vector<Robot_Model> Shop::get_models()
{
	return models;
}

void Shop::create_rand_part() //for testing purposes only
{
	Head *h;
	Locomotor *l;
	Torso *t;
	Battery *b;
	Arm *a;
	int rand_num = (rand() % 5) + 1;

	switch (rand_num)
	{
	case 1:
		num_rand_heads++;
		h = new Head("Random Head " + Str_conversion::to_string(num_rand_heads), (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random head.");
		try
		{
			add(*h);
		}
		catch (Part_Num_Exists& e)
		{
			num_rand_heads--;
			throw Part_Num_Exists{};
		}
		break;
	case 2:
		num_rand_locomotors++;
		l = new Locomotor("Random Locomotor " + Str_conversion::to_string(num_rand_locomotors), (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random locomotor.", (rand() % 100), (rand() % 100000)/100.0);
		try
		{
			add(*l);
		}
		catch (Part_Num_Exists& e)
		{
			num_rand_locomotors--;
			throw Part_Num_Exists{};
		}
		break;
	case 3:
		num_rand_torsos++;
		t = new Torso("Random Torso " + Str_conversion::to_string(num_rand_torsos), (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random torso.", (rand() % 3) + 1);
		try
		{
			add(*t);
		}
		catch (Part_Num_Exists& e)
		{
			num_rand_torsos--;
			throw Part_Num_Exists{};
		}
		break;
	case 4:
		num_rand_batteries++;
		b = new Battery("Random Battery" + Str_conversion::to_string(num_rand_batteries), (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random battery.", ((rand() % 100000000) / 100.0));
		try
		{
			add(*b);
		}
		catch (Part_Num_Exists& e)
		{
			num_rand_batteries--;
			throw Part_Num_Exists{};
		}
		break;
	case 5:
		num_rand_arms++;
		a = new Arm("Random Arm " + Str_conversion::to_string(num_rand_arms), (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random arm.", (rand() % 100000)/100.0);
		try
		{
			add(*a);
		}
		catch (Part_Num_Exists& e)
		{
			num_rand_arms--;
			throw Part_Num_Exists{};
		}
		break;
	}
}

void Shop::create_rand_model() //for testing purposes only
{
	if (get_available_heads().size() == 0 || get_available_torsos().size() == 0 || get_available_locomotors().size() == 0
		|| get_available_arms().size() == 0 || get_available_batteries().size() == 0)
	{
		throw Missing_Parts{};
	}

	int num_arms = (rand() % 2) + 1;
	if (get_available_arms().size() < num_arms)
		throw Missing_Parts{};

	int rand_index;

	rand_index = rand() % get_available_heads().size();
	Head head = get_available_heads()[rand_index];

	rand_index = rand() % get_available_torsos().size();
	Torso torso = get_available_torsos()[rand_index];

	rand_index = rand() % get_available_locomotors().size();
	Locomotor locomotor = get_available_locomotors()[rand_index];

	vector<Arm> arms;
	for (int i = 0; i < num_arms; i++)
	{
		rand_index = rand() % get_available_arms().size();
		arms.push_back(get_available_arms()[rand_index]);
	}

	vector<Battery> batteries;
	int num_batteries = (rand() % torso.get_battery_compartments()) + 1;
	for (int i = 0; i < num_batteries; i++)
	{
		rand_index = rand() % get_available_batteries().size();
		batteries.push_back(get_available_batteries()[rand_index]);
	}

	num_rand_models++;
	Robot_Model model("Random Robot Model " + Str_conversion::to_string(num_rand_models), (rand() % 10000000), ((rand() % 1000000) / 100.0), head, torso, locomotor, &arms, batteries);
	try
	{
		add(model);
	}
	catch (Model_Num_Exists& e)
	{
		num_rand_models--;
		throw Model_Num_Exists{};
	}
}

void Shop::create_rand_customer()
{
	int phone1 = rand() % 1000;
	int phone2 = rand() % 1000;
	int phone3 = rand() % 10000;
	int st_num = rand() % 10000;
	int zip1 = rand() % 100000;
	int zip2 = rand() % 10000;
	int rand_num = rand() % 10000000;

	num_rand_customers++;

	Address rand_address(st_num, "Random " + Str_conversion::to_string(num_rand_customers) + " St.", "Random City " + Str_conversion::to_string(num_rand_customers), "RS", Str_conversion::to_string(zip1) + "-" + Str_conversion::to_string(zip2));

	Customer customer("Random Customer " + Str_conversion::to_string(num_rand_customers), rand_address, "(" + Str_conversion::to_string(phone1) + ")" + Str_conversion::to_string(phone2) + "-" + Str_conversion::to_string(phone3), "random_email_" + Str_conversion::to_string(rand_num) + "@sbcrandom.net");
	try
	{
		add(customer);
	}
	catch (Customer_Exists& e)
	{
		num_rand_models--;
		throw Customer_Exists{};
	}
}

void Shop::create_rand_associate()
{
	num_rand_associates++;

	Sales_Associate associate("Random Sales Associate " + Str_conversion::to_string(num_rand_associates), rand() % 100000000);
	try
	{
		add(associate);
	}
	catch (Sales_Associate_Exists& e)
	{
		num_rand_associates--;
		throw Sales_Associate_Exists{};
	}
}

vector<Head> Shop::get_available_heads()
{
	return heads;
}

vector<Torso> Shop::get_available_torsos()
{
	return torsos;
}

vector<Locomotor> Shop::get_available_locomotors()
{
	return locomotors;
}

vector<Arm> Shop::get_available_arms()
{
	return arms;
}

vector<Battery> Shop::get_available_batteries()
{
	return batteries;
}
vector<Customer> Shop::get_customers()
{
	return customers;
}
vector<Sales_Associate> Shop::get_sales_associates()
{
	return sales_associates;
}
vector<Robot_Order> Shop::get_orders()
{
	return orders;
}
/*
void Shop::remove(Head h)
{
	bool found = false;
	vector<Head> new_heads;
	for (Head head : heads)
	{
		if (head.get_part_num() != h.get_part_num())
			new_heads.push_back(head);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		heads = new_heads;
}

void Shop::remove(Torso t)
{
	bool found = false;
	vector<Torso> new_torsos;
	for (Torso torso : torsos)
	{
		if (torso.get_part_num() != t.get_part_num())
			new_torsos.push_back(torso);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		torsos = new_torsos;
}

void Shop::remove(Locomotor l)
{
	bool found = false;
	vector<Locomotor> new_locomotors;
	for (Locomotor locomotor : locomotors)
	{
		if (locomotor.get_part_num() != l.get_part_num())
			new_locomotors.push_back(locomotor);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		locomotors = new_locomotors;
}

void Shop::remove(Arm a)
{
	bool found = false;
	vector<Arm> new_arms;
	for (Arm arm : arms)
	{
		if (arm.get_part_num() != a.get_part_num())
			new_arms.push_back(arm);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		arms = new_arms;
}

void Shop::remove(Battery b)
{
	bool found = false;
	vector<Battery> new_batteries;
	for (Battery battery : batteries)
	{
		if (battery.get_part_num() != b.get_part_num())
			new_batteries.push_back(battery);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		batteries = new_batteries;
}
*/