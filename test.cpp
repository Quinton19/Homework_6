#include "Shop.h"
#include <string>

int main()
{
	bool pass = true;
	string fail_messages = "";

	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Str_conversion
	if (Str_conversion::to_string(913).compare("913") != 0)
	{
		pass = false;
		fail_messages += ".to_string(int) in class Str_conversion failed\n";
	}

	if (Str_conversion::to_string(123.456).compare("123.456") != 0)
	{
		pass = false;
		fail_messages += ".to_string(double) in class Str_conversion failed\n";
	}


	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Robot_Part
	Robot_Part rp("Test Robot Part", 123456789, 23.36664289109, 500.00, "This is simply a test to ensure that the program creates robot parts correctly.", Component_type::Locomotor);
	if (rp.get_name().compare("Test Robot Part") != 0)
	{
		pass = false;
		fail_messages += ".get_name() in class Robot_Part failed\n";
	}

	if (rp.get_part_num() != 123456789)
	{
		pass = false;
		fail_messages += ".get_part_num() in class Robot_Part failed\n";
	}

	if (rp.get_weight() != 23.36664289109)
	{
		pass = false;
		fail_messages += ".get_weight() in class Robot_Part failed\n";
	}

	if (rp.get_cost() != 500.00)
	{
		pass = false;
		fail_messages += ".get_cost() in class Robot_Part failed\n";
	}

	if (rp.get_description().compare("This is simply a test to ensure that the program creates robot parts correctly.") != 0)
	{
		pass = false;
		fail_messages += ".get_description() in class Robot_Part failed\n";
	}

	if (rp.get_component_type() != Component_type::Locomotor)
	{
		pass = false;
		fail_messages += ".get_component_type() in class Robot_Part failed\n";
	}

	if (rp.get_component_type_str().compare("locomotor") != 0)
	{
		pass = false;
		fail_messages += ".get_component_type_str() in class Robot_Part failed\n";
	}

	if (rp.to_string().compare("Name: " + rp.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(rp.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(rp.get_weight()) + " lb\n"
							+ "Cost: $" + Str_conversion::to_string(rp.get_cost()) + "\n"
							+ "Description: " + rp.get_description() + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Robot_Part failed\n";
	}


	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Arm
	Arm a("Test Arm", 999999, 11.1, 45.99, "This is simply a test to ensure that the program creates arms correctly.", 20);
	if (a.get_power_consumed() != 20.0)
	{
		pass = false;
		fail_messages += ".get_power_consumed() in class Arm failed\n";
	}

	if (a.to_string().compare("Name: " + a.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(a.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(a.get_weight()) + " lb\n"
							+ "Cost: $" + Str_conversion::to_string(a.get_cost()) + "\n"
							+ "Description: " + a.get_description() + "\n"
							+ "Power consumed: " + Str_conversion::to_string(a.get_power_consumed()) + " W\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Arm failed\n";
	}


	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Battery
	Battery b("Test Battery", -222, 50, 400, "This is simply a test to ensure that the program creates batteries correctly.", 0);
	if (b.get_energy_contained() != 0.0)
	{
		pass = false;
		fail_messages += ".get_energy_contained() in class Battery failed\n";
	}

	if (b.to_string().compare("Name: " + b.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(b.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(b.get_weight()) + " lb\n"
							+ "Cost: $" + Str_conversion::to_string(b.get_cost()) + "\n"
							+ "Description: " + b.get_description() + "\n"
							+ "Energy contained: " + Str_conversion::to_string(b.get_energy_contained()) + " kWh\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Battery failed\n";
	}


	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Head
	Head h("Test Head", 1, 5000000.000001, 999999.02, "This is simply a test to ensure that the program creates heads correctly.");
	if (h.to_string().compare("Name: " + h.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(h.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(h.get_weight()) + " lb\n"
							+ "Cost: $" + Str_conversion::to_string(h.get_cost()) + "\n"
							+ "Description: " + h.get_description() + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Head failed\n";
	}


	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Torso
	Torso* t;
	try
	{
		t = new Torso("Test Torso", 00001101, 749673, 555, "This is simply a test to ensure that the program creates torsos correctly.", 3);
	}
	catch(Compartment_Limit& limit_c)
	{
		pass = false;
		fail_messages += "exceeded Compartment_Limit in Torso constructor\n";
	}

	if (t->get_battery_compartments() != 3)
	{
		pass = false;
		fail_messages += ".get_battery_compartments() in class Torso failed\n";
	}

	if (t->to_string().compare("Name: " + t->get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(t->get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(t->get_weight()) + " lb\n"
							+ "Cost: $" + Str_conversion::to_string(t->get_cost()) + "\n"
							+ "Description: " + t->get_description() + "\n"
							+ "Number of battery compartments: " + Str_conversion::to_string(t->get_battery_compartments()) + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Torso failed\n";
	}

	try
	{
		Torso bad_t("Bad Test Torso", -666, 666.666, 666.67, "This is a test of a bad construction of a Torso object, as there are no battery compartments.", 0);
		pass = false;
		fail_messages += "failed to catch Compartment_Limit when there were no battery compartments in Torso constructor\n";
	}
	catch(Compartment_Limit& limit_c)
	{ }

	try
	{
		Torso bad_t("Bad Test Torso", -666, 666.666, 666.67, "This is a test of a bad construction of a Torso object, as there are too many battery compartments.", 100);
		pass = false;
		fail_messages += "failed to catch Compartment_Limit when there were too many battery compartments in Torso constructor\n";
	}
	catch(Compartment_Limit& limit_c)
	{ }


	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Locomotor
	Locomotor l("Test Locomotor", 5639272, 0.9, 0.99, "This is simply a test to ensure that the program creates locomotors correctly.", 88, 1.21);
	if (l.get_max_speed() != 88)
	{
		pass = false;
		fail_messages += ".get_max_speed() in class Locomotor failed\n";
	}

	if (l.get_power_consumed() != 1.21)
	{
		pass = false;
		fail_messages += ".get_power_consumed() in class Locomotor failed\n";
	}

	if (l.to_string().compare("Name: " + l.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(l.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(l.get_weight()) + " lb\n"
							+ "Cost: $" + Str_conversion::to_string(l.get_cost()) + "\n"
							+ "Description: " + l.get_description() + "\n"
							+ "Max speed: " + Str_conversion::to_string(l.get_max_speed()) + " mph\n"
							+ "Power consumed: " + Str_conversion::to_string(l.get_power_consumed()) + " W\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Locomotor failed\n";
	}


	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Robot_Model
	Torso t2("Test Torso", 00001101, 749673, 555, "This is simply a test to ensure that the program creates torsos correctly.", 3);
	Arm a2("2nd Test Arm", 1000, 1000, 1000, "This is the 2nd test arm. It is being created to test the Robot_Model class.", 1000);
	Battery b2("2nd Test Battery", 963, 1, 1, "This is the 2nd test battery. It is being created to test the Robot_Model class.", 1);
	Battery b3("3rd Test Battery", 852, 1, 1, "This is the 3rd test battery. It is being created to test the Robot_Model class.", 1);
	vector<Arm> arms;
	arms.push_back(a);
	arms.push_back(a2);
	vector<Battery> batteries;
	batteries.push_back(b);
	batteries.push_back(b2);
	batteries.push_back(b3);
	Robot_Model *r;
	try
	{
		r = new Robot_Model("Test Robot Model 1", 1, 1000000, h, t2, l, &arms, batteries, "");
	}
	catch (Arm_Limit& limit_a)
	{
		pass = false;
		fail_messages += "exceeded Arm_Limit in Robot_Model 1 constructor\n";
	}
	catch (Battery_Limit& limit_b)
	{
		pass = false;
		fail_messages += "exceeded Battery_Limit in Robot_Model 1 constructor\n";
	}

	vector<Arm> bad_arms;
	vector<Battery> bad_batteries;
	try
	{
		Robot_Model r("Test Robot Model 2", 2, 0, h, t2, l, &bad_arms, batteries, "");
		pass = false;
		fail_messages += "failed to catch Arm_Limit exception when there was no arms\n";
	}
	catch (Arm_Limit& limit_a)
	{ }

	bad_arms.push_back(a);
	bad_arms.push_back(a);
	bad_arms.push_back(a);
	try
	{
		Robot_Model r("Test Robot Model 2", 2, 0, h, t2, l, &bad_arms, batteries, "");
		pass = false;
		fail_messages += "failed to catch Arm_Limit exception when there was too many arms\n";
	}
	catch(Arm_Limit& limit_a)
	{ }

	try
	{
		Robot_Model r("Test Robot Model 2", 2, 0, h, t2, l, &arms, bad_batteries, "");
		pass = false;
		fail_messages += "failed to catch Batteries_Limit exception when there was no batteries\n";
	}
	catch(Battery_Limit& limit_b)
	{ }

	bad_batteries.push_back(b);
	bad_batteries.push_back(b);
	bad_batteries.push_back(b);
	bad_batteries.push_back(b);
	try
	{
		Robot_Model r("Test Robot Model 2", 2, 0, h, t2, l, &arms, bad_batteries, "");
		pass = false;
		fail_messages += "failed to catch Batteries_Limit exception when there was too many batteries\n";
	}
	catch(Battery_Limit& limit_b)
	{ }

	
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Shop
	Shop s;
	try
	{
		s.add(h);
		s.add(t2); 
		s.add(l); 
		for (Arm arm : arms)
			s.add(arm);
		for (Battery batt : batteries)
			s.add(batt);
	}
	catch (Part_Num_Exists& e)
	{
		pass = false;
		fail_messages += "adding parts to Shop failed\n";
	}

	try
	{
		s.add(h);
		pass = false;
		fail_messages += "failed to catch Part_Num_Exists error while adding duplicate Head\n";
	}
	catch(Part_Num_Exists& e)
	{ }

	vector<Head> heads;
	vector<Torso> torsos;
	vector<Locomotor> locomotors;
	vector<Arm> shop_arms;
	vector<Battery> shop_batteries;
	heads = s.get_available_heads();
	torsos = s.get_available_torsos();
	locomotors = s.get_available_locomotors();
	shop_arms = s.get_available_arms();
	shop_batteries = s.get_available_batteries();
	if (heads.size() != 1 || heads[0].get_part_num() != h.get_part_num())
	{
		pass = false;
		fail_messages += ".get_available_heads() failed\n";
	}

	if (torsos.size() != 1 || torsos[0].get_part_num() != t2.get_part_num())
	{
		pass = false;
		fail_messages += ".get_available_torsos() failed\n";
	}

	if (locomotors.size() != 1 || locomotors[0].get_part_num() != l.get_part_num())
	{
		pass = false;
		fail_messages += ".get_available_locomotors() failed\n";
	}

	if (shop_arms.size() != arms.size())
	{
		pass = false;
		fail_messages += ".get_available_arms() failed in size\n";
	}
	else
	{
		for (int i = 0; i < arms.size(); i++)
		{
			if (shop_arms[i].get_part_num() != arms[i].get_part_num())
			{
				pass = false;
				fail_messages += ".get_available_arms() failed in part by part comparison\n";
				break;
			}
		}
	}

	if (shop_batteries.size() != batteries.size())
	{
		pass = false;
		fail_messages += ".get_available_batteries() failed in size\n";
	}
	else
	{
		for (int i = 0; i < batteries.size(); i++)
		{
			if (shop_batteries[i].get_part_num() != batteries[i].get_part_num())
			{
				pass = false;
				fail_messages += ".get_available_batteries() failed in part by part comparison\n";
				break;
			}
		}
	}

	try
	{
		s.add(*r);
	}
	//catch (Invalid_Model& e)
	//{
	//	pass = false;
	//	fail_messages += ".add(Robot_Model) failed\n";
	//}
	catch (Model_Num_Exists& e)
	{
		pass = false;
		fail_messages += ".add(Robot_Model) failed\n";
	}

	try
	{
		s.add(*r);
		pass = false;
		fail_messages += "failed to catch Model_Num_Exists error while adding existing model\n";
	}
	catch(Model_Num_Exists& e)
	{ }
	/*
	catch (Invalid_Model& e)
	{
		pass = false;
		fail_messages += "failed, as Invalid_Model error was thrown, and Model_Num_Exists error should have been thrown first\n";
	}
	
	Head h2("Test Head w/ PN: 314259", 314159, 5000000.000001, 999999.02, "This Head exists to test the error handling of .add(Robot_Model) in class Shop.");
	Robot_Model r2("Test Robot Model 2.0", 100, 1000000, h2, t2, l, &arms, batteries);
	try {
		s.add(r2);
		pass = false;
		fail_messages += "failed to catch Invalid_Model error while adding Robot_Model with a Head not registered in Shop\n";
	}
	catch (Model_Num_Exists& e)
	{
		pass = false;
		fail_messages += "failed, as Model_Num_Exists error was thrown when there was no conflict in model numbers\n";
	}
	catch(Invalid_Model& e)
	{ }
	
	try
	{
		s.add(h2);
		s.remove(h2);
	}
	catch (Part_Num_Exists& e)
	{
		pass = false;
		fail_messages += "failed, as Part_Num_Exists error was thrown when there was no conflict in part numbers\n";
	}
	catch (Part_Num_DNE& e)
	{
		pass = false;
		fail_messages += "failed, as Part_Num_DNE error was thrown when the part number did exist\n";
	}
	
	try
	{
		s.remove(h2);
		pass = false;
		fail_messages += "failed to catch Part_Num_DNE when the part number did not exist\n";
	}
	catch(Part_Num_DNE& e)
	{ }
	
	heads = s.get_available_heads();
	if (heads.size() != 0)
	{
		pass = false;
		fail_messages += ".get_available_heads() failed, as it contained Head objects when it shouldn't\n";
	}
	*/
	s.create_rand_part();
	heads = s.get_available_heads();
	torsos = s.get_available_torsos();
	locomotors = s.get_available_locomotors();
	shop_arms = s.get_available_arms();
	shop_batteries = s.get_available_batteries();
	int num_items = 0;
	if (heads.size() != 1)
	{
		num_items++;
	}
	if (torsos.size() != 1)
	{
		num_items++;
	}
	if (locomotors.size() != 1)
	{
		num_items++;
	}
	if (shop_arms.size() != arms.size())
	{
		num_items++;
	}
	if (shop_batteries.size() != batteries.size())
	{
		num_items++;
	}

	if(num_items == 0)
	{
		pass = false;
		fail_messages += ".create_rand_part() failed to add a part\n";
	}
	else if (num_items > 1)
	{
		pass = false;
		fail_messages += ".create_rand_part() failed, as it created more than 1 part\n";
	}
	
	s.create_rand_model();
	vector<Robot_Model> models = s.get_models();
	if (models.size() != 2)
	{
		pass = false;
		fail_messages += ".create_rand_model() failed\n";
	}
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Testing Address
	Address test_address(1234, "Fake St.", "Imaginary", "QK", "77777-7777");
    if(test_address.get_street_num() != 1234)
    {
        pass = false;
        fail_messages += ".get_street_num() failed in class Address\n";
    }
    if(test_address.get_street_name().compare("Fake St.") != 0)
    {
        pass = false;
        fail_messages += ".get_street_name() failed in class Address\n";
    }
    if(test_address.get_city().compare("Imaginary") != 0)
    {
        pass = false;
        fail_messages += ".get_city() failed in class Address\n";
    }
    if(test_address.get_state().compare("QK") != 0)
    {
        pass = false;
        fail_messages += ".get_state() failed in class Address\n";
    }
    if(test_address.get_zip_code().compare("77777-7777") != 0)
    {
        pass = false;
        fail_messages += ".get_zip_code() failed in class Address\n";
    }
    if(test_address.to_string().compare("1234 Fake St.\nImaginary, QK 77777-7777\n") != 0)
    {
        pass = false;
        fail_messages += ".to_string() failed in class Address\n";
    }
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Testing Apt_Address
    Apt_Address test_address2(5678, "Faux Dr.", "Pretend", "SM", "00000-0000", 91011);
    if(test_address2.get_apt_num() != 91011)
    {
        pass = false;
        fail_messages += ".get_apt_num() failed in class Apt_Address\n";
    }
    if(test_address2.to_string().compare("5678 Faux Dr. Apt. 91011\nPretend, SM 00000-0000\n") != 0)
    {
        pass = false;
        fail_messages += ".to_string() failed in class Apt_Address\n";
    }
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Testing PO_Box_Address
    PO_Box_Address test_address3(1213, "Synthetic", "FS", "10101-0101");
    if(test_address3.get_po_box_num() != 1213)
    {
        pass = false;
        fail_messages += ".get_po_box_num() failed in class PO_Box_Address\n";
    }
    if(test_address3.to_string().compare("P.O. Box 1213\nSynthetic, FS 10101-0101\n") != 0)
    {
        pass = false;
        fail_messages += ".to_string() failed in class PO_Box_Address\n";
    }
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Testing Customer
    Customer test_customer("John Smith", test_address3, "(000)000-0000", "not_real@bmail.com");
    if(test_customer.get_name().compare("John Smith") != 0)
    {
        pass = false;
        fail_messages += ".get_name() failed in class Customer\n";
    }
    if(test_customer.get_phone_num().compare("(000)000-0000") != 0)
    {
        pass = false;
        fail_messages += ".get_name() failed in class Customer\n";
    }
    if(test_customer.get_email_address().compare("not_real@bmail.com") != 0)
    {
        pass = false;
        fail_messages += ".get_email_address() failed in class Customer\n";
    }
    if(test_customer.get_address_ref().get().to_string().compare(test_address3.to_string()) != 0)
    {
        pass = false;
        fail_messages += ".get_address() failed in class Customer\n";
    }
    if(test_customer.to_string().compare("Name: John Smith\n"
                                        + (string)"Phone Number: (000)000-0000\n"
                                        + "Email: not_real@bmail.com\n"
                                        + "Address:\n" + test_customer.get_address_ref().get().to_string() + "\n") != 0)
    {
        pass = false;
        fail_messages += ".to_string() failed in class Customer\n";
    }
    if(!(test_customer == test_customer))
    {
        pass = false;
        fail_messages += "the operator == failed in class Customer\n";
    }
    if(test_customer != test_customer)
    {
        pass = false;
        fail_messages += "the operator != failed in class Customer\n";
    }
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Testing Sales_Associate
    Sales_Associate test_associate("Johnathan Smithy", 123456);
    if(test_associate.get_name().compare("Johnathan Smithy") != 0)
    {
        pass = false;
        fail_messages += ".get_name() failed in class Sales_Associate\n";
    }
    if(test_associate.get_employee_num() != 123456)
    {
        pass = false;
        fail_messages += ".get_employee_num() failed in class Sales_Associate\n";
    }
    if(test_associate.to_string().compare("Name: Johnathan Smithy\nEmployee #123456\n") != 0)
    {
        pass = false;
        fail_messages += ".to_string() failed in class Sales_Associate\n";
    }
    if(!(test_associate == test_associate))
    {
        pass = false;
        fail_messages += "the operator == failed in class Sales_Associate\n";
    }
    if(test_associate != test_associate)
    {
        pass = false;
        fail_messages += "the operator != failed in class Sales_Associate\n";
    }
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Testing Robot_Order
    Robot_Order test_order(*r, 10, test_associate, test_customer);
    if(test_order.get_model().to_string().compare(r->to_string()) != 0)
    {
        pass = false;
        fail_messages += ".get_model() failed in class Robot_Order\n";
    }
    if(test_order.get_quantity() != 10)
    {
        pass = false;
        fail_messages += ".get_quantity() failed in class Robot_Order\n";
    }
    if(test_order.get_total_cost() != (r->get_price() * 10))
    {
        pass = false;
        fail_messages += ".get_total_cost() failed in class Robot_Order\n";
    }
    if(test_order.get_orderer() != test_associate)
    {
        pass = false;
        fail_messages += ".get_orderer() failed in class Robot_Order\n";
    }
    if(test_order.get_customer() != test_customer)
    {
        pass = false;
        fail_messages += ".get_customer() failed in class Robot_Order\n";
    }
    if(test_order.to_string().compare("Date: " + test_order.get_order_time() + "\n"
                                    + "Robot Model Ordered: " + r->get_name() + " -- #" + Str_conversion::to_string(r->get_model_num()) + "\n"
                                    + "Amount ordered: 10\n"
                                    + "Total amount due: $" + Str_conversion::to_string(r->get_price() * 10) + "\n"
                                    + "Sales Associate ID: 123456\n"
                                    + "Customer Name: John Smith\n") != 0)
    {
        pass = false;
        fail_messages += ".to_string() failed in class Robot_Order\n";
    }
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//end of tests
	if (!pass)
	{
		cerr << fail_messages;
		cout << "fail\n";
	}
	else
	{
		cout << "pass\n";
	}

	return 1;
}
