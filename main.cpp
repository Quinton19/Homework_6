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
#include <FL/Fl_Radio_Round_Button.H>
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
void Open_Robot_Model_DialogCB(Fl_Widget* w, void* p);
void Selected_HeadCB(Fl_Widget* w, void* p);
class Robot_Part_Dialog;
class Robot_Model_Dialog;

Fl_Window *window;
Shop *shop;
Robot_Part_Dialog *robot_part_dlg;
Robot_Model_Dialog *robot_model_dlg;


//-------------------------------------------------------------------------------------------------------------------------------------------
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
        
        shop = new Shop();

		dialog = new Fl_Window(340, 270, "Add a Robot Part");

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

		//Locomotor's and Arm's extra field
		pwr_consumed_in = new Fl_Float_Input(x, y, w, h, "Power consumed: [W]");
		pwr_consumed_in->align(FL_ALIGN_LEFT);
		pwr_consumed_in->hide();
        
        //Locomotor's 2nd extra field
		speed_in = new Fl_Int_Input(x, y + y_incr, w, h, "Speed: [mph]");
		speed_in->align(FL_ALIGN_LEFT);
		speed_in->hide();

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
        dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + 30);
        create->position(create->x(), create->y() + 30);
        cancel->position(cancel->x(), cancel->y() + 30);
		batt_compartments_in->show();
	}
	void show_locomotor_extras()
	{
		hide_extras();
        dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + 60);
        create->position(create->x(), create->y() + 60);
        cancel->position(cancel->x(), cancel->y() + 60);
        pwr_consumed_in->show();
        speed_in->show();
	}
	void show_battery_extras()
	{
		hide_extras();
        dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + 30);
        create->position(create->x(), create->y() + 30);
        cancel->position(cancel->x(), cancel->y() + 30);
        energy_in->show();
	}
	void show_arm_extras()
	{
		hide_extras();
        dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + 30);
        create->position(create->x(), create->y() + 30);
        cancel->position(cancel->x(), cancel->y() + 30);
        pwr_consumed_in->show();
	}
	void hide()
	{
		dialog->hide(); 
	}
	void hide_extras()
	{
        if (chose_type && (batt_compartments_in->visible() != 0 || speed_in->visible() != 0 || pwr_consumed_in->visible() != 0 || energy_in->visible() != 0) )
        {
            if(speed_in->visible() != 0)
            {
                dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - 60);
                create->position(create->x(), create->y() - 60);
                cancel->position(cancel->x(), cancel->y() - 60);
            }
            else
            {
                dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - 30);
                create->position(create->x(), create->y() - 30);
                cancel->position(cancel->x(), cancel->y() - 30);
            }
        }
		batt_compartments_in->hide();
		speed_in->hide();
		pwr_consumed_in->hide();
		energy_in->hide();
        
	}
	string name()
	{
		return name_in->value(); 
	}
	int part_num()
	{
		return atoi(part_num_in->value()); 
	}
	Component_type type()
	{
		if (type_in->value() == 0)
			return Component_type::Head;
		else if (type_in->value() == 1)
			return Component_type::Torso;
		else if (type_in->value() == 2)
			return Component_type::Locomotor;
		else if (type_in->value() == 3)
			return Component_type::Battery;
		else if (type_in->value() == 4)
			return Component_type::Arm;
	}
	double weight()
	{
		return atof(weight_in->value()); 
	}
	double cost()
	{
		return atof(cost_in->value()); 
	}
	string description()
	{
		return description_in->value();
	}
	int num_compartments()
    {
        return (batt_compartments_in->value() + 1);
    }
    int speed()
    {
        return atoi(speed_in->value());
    }
    double power_consumed()
    {
        return atof(pwr_consumed_in->value());
    }
    double energy()
    {
        return atof(energy_in->value());
    }
	bool has_empty_fields()
	{
		bool is_empty = false;

		if (strcmp(name_in->value(), "") == 0)
			is_empty = true;
		else if(strcmp(part_num_in->value(), "") == 0)
            is_empty = true;
        else if(strcmp(weight_in->value(), "") == 0)
            is_empty = true;
        else if(strcmp(cost_in->value(), "") == 0)
            is_empty = true;
        else if(strcmp(description_in->value(), "") == 0)
            is_empty = true;
        else if(!chose_type)
            is_empty = true;
        else if(batt_compartments_in->visible() != 0 && !chose_compartment_num)
            is_empty = true;
        else if(speed_in->visible() != 0 && strcmp(speed_in->value(), "") == 0)
            is_empty = true;
        else if(pwr_consumed_in->visible() != 0 && strcmp(pwr_consumed_in->value(), "") == 0)
            is_empty = true;
        else if(energy_in->visible() != 0 && strcmp(energy_in->value(), "") == 0)
            is_empty = true;
        
        return is_empty;
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
//-------------------------------------------------------------------------------------------------------------------------------------------

class Robot_Model_Dialog
{
public:
    Robot_Model_Dialog()
    {
        int x = 120;
		int y = 10;
		int w = 210;
		int h = 25;
		int y_incr = 30;
        
        dialog = new Fl_Window(340, 270, "Add a Robot Model");
        
        name_in = new Fl_Input(x, y, w, h, "Name:"); y += y_incr;
        name_in->align(FL_ALIGN_LEFT);
        
        model_num_in = new Fl_Int_Input(x, y, w, h, "Model Number:"); y += y_incr;
        model_num_in->align(FL_ALIGN_LEFT);
        cout << "test1\n";
        head_choice = new Fl_Choice(x, y, w, h, "Head:"); y += y_incr;
        head_choice->align(FL_ALIGN_LEFT);
        cout<< "test2\n";
        head_choice->callback(Selected_HeadCB, NULL);
        vector<Head> shop_heads = shop->get_available_heads();
        for( Head h : shop_heads )
        {
            cout << "test3\n";
            head_choice->add((h.get_name() + " - Part #" + Str_conversion::to_string(h.get_part_num())).c_str());
        }
        /*
        torso_choice = new Fl_Choice(x, y, w, h, "Torso:"); y += y_incr;
        head_choice->align(FL_ALIGN_LEFT);
        
        head_choice->callback(Selected_HeadCB, NULL);
        vector<Head> shop_heads = shop->get_available_heads();
        for( Head h : shop_heads )
        {
            head_choice->add((h.get_name() + " - Part #" + h.get_part_num()).c_str());
        }
        */
        
        dialog->end();
		dialog->set_non_modal();
    }
    void show()
    {
        dialog->show();
    }
private:
    Fl_Window* dialog;
    Fl_Input* name_in;
    Fl_Int_Input* model_num_in;
    Fl_Choice* head_choice;
    Fl_Choice* torso_choice;
    Fl_Choice* locomotor_choice;
    Fl_Choice* arm_choices[2];
    Fl_Choice* battery_choices[3];
    Fl_Radio_Round_Button* yes_options[3];
    Fl_Radio_Round_Button* no_options[3];
    Fl_Group* radio_button_groups[3];
    Fl_Group* part_cost_display;
    Fl_Float_Input* price_in;
    
    Fl_Return_Button* create;
    Fl_Button* cancel;
    
    double total_cost;
    bool chose_head = false;
    bool chose_torso = false;
    bool chose_locomotor = false;
    bool chose_arm[2] = { false, false };
    bool chose_battery[3] = { false, false, false };
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
			{"&Robot Model",0, (Fl_Callback*)Open_Robot_Model_DialogCB },
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
    if(robot_part_dlg->has_empty_fields())
    {
        fl_alert("ERROR:\nNot enough information to create a robot part");
        fl_beep(FL_BEEP_DEFAULT);
    }
    else
    {
        string name = robot_part_dlg->name();
        int part_num = robot_part_dlg->part_num();
        double weight = robot_part_dlg->weight();
        double cost = robot_part_dlg->cost();
        string description = robot_part_dlg->description();
        Head* head;
        Torso* torso;
        Locomotor* locomotor;
        Battery* battery;
        Arm* arm;
        
        if(robot_part_dlg->type() == Component_type::Head)
        {
            head = new Head(name, part_num, weight, cost, description);
            int correct = fl_ask(("Is this correct?\n" + head->to_string()).c_str());
            if(correct == 1) //Yes
            {
                try
                {
                    shop->add(*head);
                    fl_message((name + " was successfully added.").c_str());
                    robot_part_dlg->hide();
                }
                catch(Part_Num_Exists& e)
                {
                    fl_alert("ERROR:\nThat part number already exists!");
                    fl_beep(FL_BEEP_DEFAULT);
                }
            }
        }
        else if(robot_part_dlg->type() == Component_type::Torso)
        {
            int num_batt_compartments = robot_part_dlg->num_compartments();
            
            torso = new Torso(name, part_num, weight, cost, description, num_batt_compartments);
            int correct = fl_ask(("Is this correct?\n" + torso->to_string()).c_str());
            if(correct == 1) //Yes
            {
                try
                {
                    shop->add(*torso);
                    fl_message((name + " was successfully added.").c_str());
                    robot_part_dlg->hide();
                }
                catch(Part_Num_Exists& e)
                {
                    fl_alert("ERROR:\nThat part number already exists!");
                    fl_beep(FL_BEEP_DEFAULT);
                }
            }
        }
        else if(robot_part_dlg->type() == Component_type::Locomotor)
        {
            double pwr_consumed = robot_part_dlg->power_consumed();
            int speed = robot_part_dlg->speed();
            
            locomotor = new Locomotor(name, part_num, weight, cost, description, speed, pwr_consumed);
            int correct = fl_ask(("Is this correct?\n" + locomotor->to_string()).c_str());
            if(correct == 1) //Yes
            {
                try
                {
                    shop->add(*locomotor);
                    fl_message((name + " was successfully added.").c_str());
                    robot_part_dlg->hide();
                }
                catch(Part_Num_Exists& e)
                {
                    fl_alert("ERROR:\nThat part number already exists!");
                    fl_beep(FL_BEEP_DEFAULT);
                }
            }
        }
        else if(robot_part_dlg->type() == Component_type::Battery)
        {
            double energy = robot_part_dlg->energy();
            
            battery = new Battery(name, part_num, weight, cost, description, energy);
            int correct = fl_ask(("Is this correct?\n" + battery->to_string()).c_str());
            if(correct == 1) //Yes
            {
                try
                {
                    shop->add(*battery);
                    fl_message((name + " was successfully added.").c_str());
                    robot_part_dlg->hide();
                }
                catch(Part_Num_Exists& e)
                {
                    fl_alert("ERROR:\nThat part number already exists!");
                    fl_beep(FL_BEEP_DEFAULT);
                }
            }
        }
        else if(robot_part_dlg->type() == Component_type::Arm)
        {
            double pwr_consumed = robot_part_dlg->power_consumed();
            
            arm = new Arm(name, part_num, weight, cost, description, pwr_consumed);
            int correct = fl_ask(("Is this correct?\n" + arm->to_string()).c_str());
            if(correct == 1) //Yes
            {
                try
                {
                    shop->add(*arm);
                    fl_message((name + " was successfully added.").c_str());
                    robot_part_dlg->hide();
                }
                catch(Part_Num_Exists& e)
                {
                    fl_alert("ERROR:\nThat part number already exists!");
                    fl_beep(FL_BEEP_DEFAULT);
                }
            }
        }
    }
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
	if (robot_part_dlg->type() == Component_type::Torso)
		robot_part_dlg->show_torso_extras();
	else if (robot_part_dlg->type() == Component_type::Locomotor)
        robot_part_dlg->show_locomotor_extras();
    else if (robot_part_dlg->type() == Component_type::Battery)
        robot_part_dlg->show_battery_extras();
    else if (robot_part_dlg->type() == Component_type::Arm)
        robot_part_dlg->show_arm_extras();
    else
        robot_part_dlg->hide_extras();
    
    robot_part_dlg->type_chosen();
}

void Selected_CompartmentsCB(Fl_Widget* w, void* p)
{
    robot_part_dlg->compartment_num_chosen();
}

void Open_Robot_Model_DialogCB(Fl_Widget* w, void* p)
{
    if (shop->get_available_heads().size() == 0 || shop->get_available_torsos().size() == 0 || shop->get_available_locomotors().size() == 0
		|| shop->get_available_arms().size() == 0 || shop->get_available_batteries().size() == 0)
	{
		fl_alert("ERROR:\nThere are not enough parts registered to create a robot model.\nPlease add more parts and try again.");
        fl_beep(FL_BEEP_DEFAULT);
	}
	else
        robot_model_dlg->show();
}

void Selected_HeadCB(Fl_Widget* w, void* p)
{
    
}
