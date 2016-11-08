#include "Controller.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>
/*
Fl_Window* win;

void head_cb(Fl_Widget* w, void* p)
{
    //string* chosen_option = (string*)p;
    //chosen_option = new string{"Head"};
}
void torso_cb(Fl_Widget* w, void* p)
{
    //string* chosen_option = (string*)p;
    //chosen_option = new string{"Torso"};
}
void locomotor_cb(Fl_Widget* w, void* p)
{
    //string* chosen_option = (string*)p;
    //chosen_option = new string{"Locomotor"};
}
void battery_cb(Fl_Widget* w, void* p)
{
    //string* chosen_option = (string*)p;
    //chosen_option = new string{"Battery"};
}
void arm_cb(Fl_Widget* w, void* p)
{
    //string* chosen_option = (string*)p;
    //chosen_option = new string{"Arm"};
}

void Create_Robot_PartCB1(Fl_Widget* w, void* p)
{
	//controller->Robot_Part_Dialog();
}

void CloseCB1(Fl_Widget* w, void* p)
{
	//win->hide();
}


void Controller::Robot_Part_Dialog()
{
	const int X = 20;
	int Y = 20;
	const int W = 250;
	const int H = 35;
    string* choice;

	win = new Fl_Window(500, 600, "Create a Robot Part");

	
	Y += H + 425;
    
    Fl_Menu_Item menuitems2[] = {
		{"&Create", 0, 0, 0, FL_SUBMENU },
			{"&Robot Part", 0, (Fl_Callback*)Create_Robot_PartCB1 },
			{ 0 },
		{"&Quit", 0, (Fl_Callback*)CloseCB1 },
		{ 0 }
	};
    //menitems2 = menuitems2;
    items = menuitems2;
    part_choice->menu(items);
    
    win->callback(head_cb, win);
    win->callback(torso_cb, win);
    win->callback(locomotor_cb, choice);
    win->callback(battery_cb, choice);
    win->callback(arm_cb, choice);
    /*
	Fl_Input* name_in = new Fl_Input(X, Y, W, H, "Part's Name:");
    name_in->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
	Y += H + 25;
	Fl_Int_Input* part_num_in = new Fl_Int_Input(X, Y, W, H, "Part Number:");
    part_num_in->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
	Y += H + 25;
	Fl_Float_Input* weight_in = new Fl_Float_Input(X, Y, W, H, "Part's Weight:");
    weight_in->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
	Y += H + 25;
	Fl_Float_Input* cost_in = new Fl_Float_Input(X, Y, W, H, "Part's cost:");
    cost_in->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
	Y += H + 25;
	Fl_Multiline_Input* description_in = new Fl_Multiline_Input(X, Y, W + H, W, "Part description:");
    description_in->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
    *//*
	win->resizable(win);
    win->end();
	win->show();
    //win->make_current();
}


*/
/*
void Controller::cli()
{
	int cmd;
	do
	{
		view.display_menu();
		cout << "Please enter a command: ";
		cin >> cmd;
		cin.ignore();
		cout << "-------------------------------------------------\n\n";

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cmd = -1;
		}
		else if (cmd == 0)
		{
			char check;
			cout << "Are you sure you want to quit? All your data will be lost. [y/n] ";
			cin >> check;
			cout << "\n";

			if (check == 'y')
				execute_cmd(cmd);
			else
				cmd = -1;
		}
		else
			execute_cmd(cmd);
	} while (cmd != 0);
}

void Controller::execute_cmd(int cmd)
{
	switch (cmd)
	{
		case 1:
			add_new_part();
			break;
		case 2:
			add_new_model();
			break;
		case 3:
			list_all_models();
			break;
		case 4:
			order_robot_models();
			break;
		case 9:
			view.help();
			break;
		case 0:
			cout << "Goodbye.\n";
			break;
		case 91396: //for testing purposes only
			for (int i = 0; i < 40; i++)
			{
				try
				{
					shop.create_rand_part();
				}
				catch (Part_Num_Exists& e)
				{ }
			}
			cout << "TESTING: Random parts created.\n\n";
			break;
		case 32803:
			try
			{
				for (int i = 0; i < 10; i++)
				{
					try
					{
						shop.create_rand_model();
					}
					catch (Model_Num_Exists& e)
					{ }
				}
				cout << "TESTING: Random models created.\n\n";
			}
			catch (Missing_Parts& e)
			{
				cerr << "ERROR: Not enough parts to create a model.\n\n";
			}
			break;
		default:
			cerr << "Invalid command. Please try again. (Type 9 for help)\n\n";
	}
}

void Controller::add_new_part()
{
	char correct;
	string name, description;
	int part_num, batt_compartments, speed, type_num;
	Component_type type;
	double weight, cost, pwr_consumed, energy;

	while (true)
	{
		do
		{
			cout << "1) Head\n"
				<< "2) Torso\n"
				<< "3) Locomotor\n"
				<< "4) Arm\n"
				<< "5) Battery\n"
				<< "Select the type of the robot part: ";
			cin >> type_num;
			cin.ignore();
			cout << "\n";

			if (!cin) 
			{
				cerr << "Invalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				type_num = -1;
			}
			else
			{
				switch (type_num)
				{
				case 1:
					type = Component_type::Head;
					break;
				case 2:
					type = Component_type::Torso;
					break;
				case 3:
					type = Component_type::Locomotor;
					break;
				case 4:
					type = Component_type::Arm;
					break;
				case 5:
					type = Component_type::Battery;
					break;
				default:
					cerr << "Invalid choice. Please try again.\n\n";
				}
			}
		} while (type_num < 1 || type_num > 5);

		cout << "Enter in the name of the part: ";
		getline(cin, name);

		while(true)
		{
			cout << "Enter in the part number: ";
			cin >> part_num;
			cin.ignore();
			if (!cin)
			{
				cerr << "\nInvalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
				break;
		}

		while (true)
		{
			cout << "Enter in the part's weight (in pounds [lb]): ";
			cin >> weight;
			cin.ignore();
			if (!cin)
			{
				cerr << "\nInvalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
				break;
		}

		while (true)
		{
			cout << "Enter in the part's cost (in US dollars): $";
			cin >> cost;
			cin.ignore();
			if (!cin)
			{
				cerr << "\nInvalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
				break;
		}

		cout << "Enter in a brief description of the part:\n";
		getline(cin, description);
		cout << "\n";

		switch (type)
		{
			case Component_type::Torso:
				do
				{
					cout << "Enter in the number of battery compartments within the torso: ";
					cin >> batt_compartments;
					cin.ignore();
					cout << "\n";
					
					if (!cin)
					{
						cerr << "\nInvalid entry. Please try again.\n\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						batt_compartments = -1;
					}
					else if (batt_compartments < 1 || batt_compartments > 3)
						cerr << "Invalid number. Please try again.\n\n";
				} while (batt_compartments < 1 || batt_compartments > 3);
				break;
			case Component_type::Locomotor:
				while (true)
				{
					cout << "Enter in the locomotor's maximum speed (in miles per hour [mph]): ";
					cin >> speed;
					cin.ignore();

					if (!cin)
					{
						cerr << "\nInvalid entry. Please try again.\n\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else
						break;
				}

				while (true)
				{
					cout << "Enter in the power consumed when the locomotor is in operation (in watts [W]): ";
					cin >> pwr_consumed;
					cin.ignore();

					if (!cin)
					{
						cerr << "\nInvalid entry. Please try again.\n\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else
						break;
				}
				cout << "\n";
				break;
			case Component_type::Arm:
				while (true)
				{
					cout << "Enter in the power consumed when the arm is in operation (in watts [W]): ";
					cin >> pwr_consumed;
					cin.ignore();

					if (!cin)
					{
						cerr << "\nInvalid entry. Please try again.\n\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else
						break;
				}
				cout << "\n";
				break;
			case Component_type::Battery:
				while (true)
				{
					cout << "Enter in the amount of energy contained within the battery (in kilowatt-hours [kWh]): ";
					cin >> energy;
					cin.ignore();

					if (!cin)
					{
						cerr << "\nInvalid entry. Please try again.\n\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else
						break;
				}
				cout << "\n";
				break;
		}

		Head* h;
		Torso* t;
		Locomotor* l;
		Arm* a;
		Battery* b;

		switch (type)
		{
			case Component_type::Head:
				h = new Head(name, part_num, weight, cost, description);

				cout << h->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try 
					{
						shop.add(*h);
						cout << "Head successfully added.\n\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Torso:
				try
				{
					t = new Torso(name, part_num, weight, cost, description, batt_compartments);
				}
				catch (Compartment_Limit& e)
				{
					cerr << "ERROR: Unexepected error encountered while trying to create torso. Please try again.\n";
					break;
				}

				cout << t->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*t);
						cout << "Torso successfully added.\n\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Locomotor:
				l = new Locomotor(name, part_num, weight, cost, description, speed, pwr_consumed);

				cout << l->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*l);
						cout << "Locomotor successfully added.\n\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Arm:
				a = new Arm(name, part_num, weight, cost, description, pwr_consumed);

				cout << a->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*a);
						cout << "Arm successfully added.\n\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Battery:
				b = new Battery(name, part_num, weight, cost, description, energy);

				cout << b->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*b);
						cout << "Battery successfully added.\n\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
		}
	}
}

void Controller::add_new_model()
{
	string name;
	int model_num, choice;
	double price;
	char another_part = 'q', correct;
	Head head;
	Torso torso;
	Locomotor locomotor;
	vector<Arm> arms;
	vector<Battery> batteries;

	if (shop.get_available_heads().size() == 0 || shop.get_available_torsos().size() == 0 || shop.get_available_locomotors().size() == 0
		|| shop.get_available_arms().size() == 0 || shop.get_available_batteries().size() == 0)
	{
		cerr << "ERROR: Not enough parts registered to create a model. Please add more parts and try again.\n\n";
		return;
	}

	cout << "Enter in the robot model's name: ";
	getline(cin, name);

	while (true)
	{
		cout << "Enter in the model number: ";
		cin >> model_num;
		cin.ignore();

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}

	do
	{
		view.display_heads_list();
		cout << "Select the head part to be used in this model: ";
		cin >> choice;

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		else if (choice < 1 || choice > shop.get_available_heads().size())
			cerr << "Invalid choice. Please try again.\n\n";
		else
		{
			vector<Head> shop_heads = shop.get_available_heads();
			head = shop_heads[choice - 1];
		}
	} while (choice < 1 || choice > shop.get_available_heads().size());

	do
	{
		view.display_torsos_list();
		cout << "Select the torso part to be used in this model: ";
		cin >> choice;

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		else if (choice < 1 || choice > shop.get_available_torsos().size())
			cerr << "Invalid choice. Please try again.\n\n";
		else
		{
			vector<Torso> shop_torsos = shop.get_available_torsos();
			torso = shop_torsos[choice - 1];
		}
	} while (choice < 1 || choice > shop.get_available_torsos().size());

	do
	{
		view.display_locomotors_list();
		cout << "Select the locomotor part to be used in this model: ";
		cin >> choice;

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		else if (choice < 1 || choice > shop.get_available_locomotors().size())
			cerr << "Invalid choice. Please try again.\n\n";
		else
		{
			vector<Locomotor> shop_locomotors = shop.get_available_locomotors();
			locomotor = shop_locomotors[choice - 1];
		}
	} while (choice < 1 || choice > shop.get_available_locomotors().size());

	for(int i = 0; i < 2; i++)
	{
		do
		{
			view.display_arms_list();
			cout << "Select an arm part to be used in this model: ";
			cin >> choice;

			if (!cin)
			{
				cerr << "Invalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = -1;
			}
			else if (choice < 1 || choice > shop.get_available_arms().size())
				cerr << "Invalid choice. Please try again.\n\n";
			else
			{
				vector<Arm> shop_arms = shop.get_available_arms();
				arms.push_back(shop_arms[choice - 1]);
			}
		} while (choice < 1 || choice > shop.get_available_arms().size());

		if ((i + 1) != 2)
		{
			cout << "Would you like to add another arm? [y/n] ";
			cin >> another_part;
			cin.ignore();

			if (another_part != 'y')
				break;
		}
	}

	for (int i = 0; i < torso.get_battery_compartments(); i++)
	{
		do
		{
			view.display_batteries_list();
			cout << "Select a battery part to be used in this model: ";
			cin >> choice;

			if (!cin)
			{
				cerr << "Invalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = -1;
			}
			else if (choice < 1 || choice > shop.get_available_batteries().size())
				cerr << "Invalid choice. Please try again.\n\n";
			else
			{
				vector<Battery> shop_batteries = shop.get_available_batteries();
				batteries.push_back(shop_batteries[choice - 1]);
			}
		} while (choice < 1 || choice > shop.get_available_batteries().size());

		if ((i + 1) == torso.get_battery_compartments())
			break;
		else
		{
			cout << "Would you like to add another battery? [y/n] ";
			cin >> another_part;
			cin.ignore();
		}

		if (another_part != 'y')
			break;
	}

	double total_cost = head.get_cost() + torso.get_cost() + locomotor.get_cost();
	for (Arm a : arms)
		total_cost += a.get_cost();
	for (Battery b : batteries)
		total_cost += b.get_cost();

	while (true)
	{
		cout << "The total cost of all the selected components is $" << total_cost << ".\n"
			<< "Enter in the price of the model: $";
		cin >> price;
		cin.ignore();

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}

	Robot_Model model(name, model_num, price, head, torso, locomotor, &arms, batteries);
	
	cout << model.to_string()
		<< "Parts: \n"
		<< "Head: " << head.get_name() << " - Part #" << head.get_part_num() << "\n"
		<< "Torso: " << torso.get_name() << " - Part #" << torso.get_part_num() << "\n"
		<< "Locomotor: " << locomotor.get_name() << " - Part #" << locomotor.get_part_num() << "\n";
	for (int i = 0; i < arms.size(); i++)
		cout << "Arm " << i + 1 << ": " << arms[i].get_name() << " - Part #" << arms[i].get_part_num() << "\n";
	for (int i = 0; i < batteries.size(); i++)
		cout << "Battery " << i + 1 << ": " << batteries[i].get_name() << " - Part #" << batteries[i].get_part_num() << "\n";

	cout << "\nIs this correct? [y/n] ";
	cin >> correct;
	cin.ignore();

	if (correct != 'y')
		add_new_model();
	else
	{
		try
		{
			shop.add(model);
			cout << "\nRobot model successfully added.\n";
		}
		catch (Model_Num_Exists& e)
		{
			cerr << "ERROR: That model number already exists. Please try again.\n";
			add_new_model();
		}
	}
}

void Controller::list_all_models()
{
	int choice;
	while(true)
	{
		if (shop.get_models().size() == 0)
		{
			cout << "There are no models to display.\n\n";
			break;
		}

		view.display_robot_models();
		cout << "Please select a model for more information (or select '0' to exit): ";
		cin >> choice;
		cin.ignore();
		cout << "\n";

		if (!cin)
		{
			cerr << "Invalid entry. Please try again.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		else if(choice == 0)
		{
			break;
		}
		else
		{
			vector<Robot_Model> shop_models = shop.get_models();

			if (choice > shop_models.size())
			{
				cerr << "Invalid entry. Please try again.\n\n";
			}
			else
			{
				cout << "Head Info:\n"
					<< shop_models[choice - 1].get_head().to_string()
					<< "\nTorso Info:\n"
					<< shop_models[choice - 1].get_torso().to_string()
					<< "\nLocomotor Info:\n"
					<< shop_models[choice - 1].get_locomotor().to_string();
				for (int i = 0; i < shop_models[choice - 1].get_arms().size(); i++)
				{
					cout << "\nArm " << i + 1 << " Info:\n"
						<< shop_models[choice - 1].get_arms()[i].to_string();
				}
				for (int i = 0; i < shop_models[choice - 1].get_batteries().size(); i++)
				{
					cout << "\nBattery " << i + 1 << " Info:\n"
						<< shop_models[choice - 1].get_batteries()[i].to_string();
				}
				cout << "\nPress ENTER when you are done with this information.";
				while (true)
				{
					if (cin.get() == '\n')
						break;
				}
			}
		}
	}
}

void Controller::order_robot_models()
{
	int choice, quantity;
	char correct;

	if (shop.get_models().size() == 0)
	{
		cerr << "ERROR: There are no robot models available to be ordered. Please add a model and try again.\n\n";
		return;
	}

	do
	{
		while (true)
		{
			view.display_robot_models();
			cout << "Please select a model to order: ";
			cin >> choice;
			cin.ignore();
			cout << "\n";

			if (!cin)
			{
				cerr << "Invalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = -1;
			}
			else if (choice > shop.get_models().size() || choice <= 0)
			{
				cerr << "Invalid entry. Please try again.\n\n";
			}
			else
				break;
		}

		while (true)
		{
			cout << "How many of the " << shop.get_models()[choice - 1].get_name() << " robot models would you like to order? ";
			cin >> quantity;
			cin.ignore();
			cout << "\n";

			if (!cin)
			{
				cerr << "Invalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if (quantity < 0)
			{
				cerr << "Invalid entry. Please try again.\n\n";
			}
			else
				break;
		}

		cout << shop.get_models()[choice - 1].to_string()
			<< "Quantity: " << quantity << "\n"
			<< "Total Price: $" << shop.get_models()[choice - 1].get_price() * quantity << "\n";
		cout << "Would you like to place this order? [y/n] ";
		cin >> correct;
		cout << "\n";
	} while (correct != 'y');

	view.display_receipt_header();
	cout << shop.get_models()[choice - 1].get_name() << "\n"
		<< "Model #" << shop.get_models()[choice - 1].get_model_num() << "\n"
		<< "Quantity: " << quantity << "\n\n"
		<< "Total: $" << shop.get_models()[choice - 1].get_price() * quantity << "\n"
		<< "-------------------------------------------------\n\n";
}
*/
