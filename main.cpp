#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <string>
#include <iostream>
#include "Shop.h"
using namespace std;

void Create_Robot_PartCB(Fl_Widget* w, void* p);
void Open_Robot_Part_DialogCB(Fl_Widget* w, void* p);
void CloseCB(Fl_Widget* w, void* p);
void Cancel_Robot_PartCB(Fl_Widget* w, void* p);
void Selected_Part_TypeCB(Fl_Widget* w, void* p);
void Selected_CompartmentsCB(Fl_Widget* w, void* p);
class Robot_Part_Dialog;

Fl_Window *window;
Shop *shop;
Robot_Part_Dialog *robot_part_dlg;

class Robot_Part_Dialog
{
public:
	Robot_Part_Dialog() 
	{
		int x = 120;
		int y = 10;
		int w = 210;
		int h = 25;
		int y_incr = 30;

		dialog = new Fl_Window(340, 270, "Robot Part");

		name_in = new Fl_Input(x, y, w, h, "Name:"); y += y_incr;
		name_in->align(FL_ALIGN_LEFT);

		part_num_in = new Fl_Int_Input(x, y, w, h, "Part Number:"); y += y_incr;
		part_num_in->align(FL_ALIGN_LEFT);

		type_in = new Fl_Choice(x, y, w, h, "Type:"); y += y_incr;
		type_in->align(FL_ALIGN_LEFT);

		type_in->callback(Selected_Part_TypeCB, (void*)"Saxophone");
		type_in->add("Head");
		type_in->add("Torso");
		type_in->add("Locomotor");
		type_in->add("Battery");
		type_in->add("Arm");

		weight_in = new Fl_Float_Input(x, y, w, h, "Weight:"); y += y_incr;
		weight_in->align(FL_ALIGN_LEFT);

		cost_in = new Fl_Float_Input(x, y, w, h, "Cost:"); y += y_incr;
		cost_in->align(FL_ALIGN_LEFT);

		description_in = new Fl_Multiline_Input(x, y, w, 75, "Description:"); y += 80;
		description_in->align(FL_ALIGN_LEFT);

		create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		create->callback((Fl_Callback *)Create_Robot_PartCB, 0);

		cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		cancel->callback((Fl_Callback *)Cancel_Robot_PartCB, 0);

		//Torso's extra field
		batt_compartments_in = new Fl_Choice(x, y, w, h, "Number of Battery Compartments:"); 
		batt_compartments_in->align(FL_ALIGN_LEFT);

		batt_compartments_in->callback(Selected_CompartmentsCB, NULL);
		batt_compartments_in->add("1");
		batt_compartments_in->add("2");
		batt_compartments_in->add("3");
		batt_compartments_in->hide();

		//Locomotor's extra field
		speed_in = new Fl_Int_Input(x, y, w, h, "Speed: [mph]");
		speed_in->align(FL_ALIGN_LEFT);
		speed_in->hide();

		//Locomotor's and Arm's extra field
		pwr_consumed_in = new Fl_Float_Input(x, y + y_incr, w, h, "Power consumed: [W]");
		pwr_consumed_in->align(FL_ALIGN_LEFT);
		pwr_consumed_in->hide();

		//Battery's extra field
		energy_in = new Fl_Float_Input(x, y, w, h, "Energy contained: [kWh]");
		energy_in->align(FL_ALIGN_LEFT);
		energy_in->hide();

		dialog->end();
		dialog->set_non_modal();
	}
	void show()
	{ 
		dialog->show(); 
	}
	void show_torso_extras()
	{
		hide_extras();
		if (strcmp(part_num_in->value(), "") == 0)
			part_num_in->hide();
		batt_compartments_in->show();
	}
	void show_locomotor_extras()
	{
		hide_extras();
	}
	void show_battery_extras()
	{
		hide_extras();
	}
	void show_arm_extras()
	{
		hide_extras();
	}
	void hide()
	{
		dialog->hide(); 
	}
	void hide_extras()
	{
		batt_compartments_in->hide();
		speed_in->hide();
		pwr_consumed_in->hide();
		energy_in->hide();
	}
	string name()
	{
		return name_in->value(); 
	}
	string part_number()
	{
		return part_num_in->value(); 
	}
	string type()
	{
		if (type_in->value() == 0)
			return "Head";
		else if (type_in->value() == 1)
			return "Torso";
		else if (type_in->value() == 2)
			return "Locomotor";
		else if (type_in->value() == 3)
			return "Battery";
		else if (type_in->value() == 4)
			return "Arm";
		else
			return "ERROR: No choice has been made.";
	}
	string weight()
	{
		return weight_in->value(); 
	}
	string cost()
	{
		return cost_in->value(); 
	}
	string description()
	{
		return description_in->value();
	}
	bool has_empty_fields()
	{
		bool is_empty = false;

		if (strcmp(name_in->value(), "") == 0)
			is_empty = true;
		//else if()
	}
	void type_chosen()
	{
		chose_type = true;
	}
	void compartment_num_chosen()
	{
		chose_compartment_num = true;
	}
private:
	Fl_Window *dialog;
	Fl_Choice *type_in;
	Fl_Input *name_in;
	Fl_Int_Input *part_num_in;
	Fl_Float_Input *weight_in;
	Fl_Float_Input *cost_in;
	Fl_Multiline_Input *description_in;

	Fl_Return_Button *create;
	Fl_Button *cancel;

	Fl_Choice *batt_compartments_in;
	Fl_Int_Input *speed_in;
	Fl_Float_Input *pwr_consumed_in;
	Fl_Float_Input *energy_in;

	bool chose_type = false;
	bool chose_compartment_num = false;
};

int main()
{
	const int X = 500;
	const int Y = 500;

	robot_part_dlg = new Robot_Part_Dialog();
	window = new Fl_Window(X, Y);
	
	Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, X, 30);

	Fl_Menu_Item menuitems[] = {
		{"&Create", 0, 0, 0, FL_SUBMENU },
			{"&Robot Part", 0, (Fl_Callback*)Open_Robot_Part_DialogCB },
			{ 0 },
		{"&Quit", 0, (Fl_Callback*)CloseCB },
		{ 0 }
	};

	menubar->menu(menuitems);

	window->callback(Open_Robot_Part_DialogCB, window);
	window->callback(CloseCB, NULL);
    

	/*
	shop.create_rand_part();

	if (shop.get_available_heads().size() != 0)
	{
		Head h = shop.get_available_heads()[0];
		fl_choice(("Random head created:\n" + h.to_string()).c_str(), "OK", 0, 0);
	}
	else if (shop.get_available_torsos().size() != 0)
	{
		Torso t2 = shop.get_available_torsos()[0];cout<<"test5\n";
		string cpp_str_out = "Random torso created:\n" + t2.to_string();
		const char* c_str_out = cpp_str_out.c_str();cout << "test7\n";
		fl_choice(c_str_out, "OK", 0, 0);
	}
	else if (shop.get_available_locomotors().size() != 0)
	{
		Locomotor l = shop.get_available_locomotors()[0];
		fl_choice(("Random locomotor created:\n" + l.to_string()).c_str(), "OK", 0, 0);
	}
	else if (shop.get_available_batteries().size() != 0)
	{
		Battery b = shop.get_available_batteries()[0];
		fl_choice(("Random battery created:\n" + b.to_string()).c_str(), "OK", 0, 0);
	}
	else
	{
		Arm a = shop.get_available_arms()[0];
		fl_choice(("Random arm created:\n" + a.to_string()).c_str(), "OK", 0, 0);
	}
	*/
    
	window->resizable(window);

	window->end();
	window->show();

	return(Fl::run());
}

void Create_Robot_PartCB(Fl_Widget* w, void* p)
{
    
}

void Open_Robot_Part_DialogCB(Fl_Widget * w, void * p)
{
	robot_part_dlg->show();
}

void CloseCB(Fl_Widget* w, void* p)
{
	window->hide();
}

void Cancel_Robot_PartCB(Fl_Widget* w, void* p)
{
	robot_part_dlg->hide();
}

void Selected_Part_TypeCB(Fl_Widget * w, void * p)
{
	robot_part_dlg->type_chosen();
	if (robot_part_dlg->type().compare("Head") == 0)
		robot_part_dlg->hide_extras();
	else if (robot_part_dlg->type().compare("Torso") == 0)
		robot_part_dlg->show_torso_extras();
	else
		robot_part_dlg->hide_extras();
}

void Selected_CompartmentsCB(Fl_Widget * w, void * p)
{
	robot_part_dlg->compartment_num_chosen();
}
