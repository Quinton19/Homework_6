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
#include <FL/Fl_Box.H>
#include <FL/Fl_Counter.H>
#include <string>
#include <iostream>
#include <sstream>
#include <limits>
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
void Selected_TorsoCB(Fl_Widget* w, void* p);
void Selected_LocomotorCB(Fl_Widget* w, void* p);
void Selected_BatteryCB(Fl_Widget* w, void* p);
void Selected_ArmCB(Fl_Widget* w, void* p);

void Debug_Generate_PartsCB(Fl_Widget* w, void* p);
void Debug_Generate_ModelsCB(Fl_Widget* w, void* p);

void Yes_Another_BatteryCB(Fl_Widget* w, void* p);
void No_Another_BatteryCB(Fl_Widget* w, void* p);
void Yes_Another_ArmCB(Fl_Widget* w, void* p);
void No_Another_ArmCB(Fl_Widget* w, void* p);

void Create_Robot_ModelCB(Fl_Widget* w, void* p);
void Cancel_Robot_ModelCB(Fl_Widget* w, void* p);

void Open_List_Models_DialogCB(Fl_Widget* w, void* p);
void Next_PageCB(Fl_Widget* w, void* p);
void DoneCB(Fl_Widget* w, void* p);

void Debug_Generate_One_ModelCB(Fl_Widget* w, void* p);

void Expand_InfoCB(Fl_Widget* w, void* p);

void Open_Customer_DialogCB(Fl_Widget* w, void* p);
void Cancel_CustomerCB(Fl_Widget* w, void* p);
void Apartment_AddressCB(Fl_Widget* w, void* p);
void PO_Box_AddressCB(Fl_Widget* w, void* p);
void Regular_AddressCB(Fl_Widget* w, void* p);
void Create_CustomerCB(Fl_Widget* w, void* p);

void Open_Sales_Associate_DialogCB(Fl_Widget* w, void* p);
void Cancel_Sales_AssociateCB(Fl_Widget* w, void* p);
void Create_Sales_AssociateCB(Fl_Widget* w, void* p);

class Robot_Part_Dialog;
class Robot_Model_Dialog;
class List_Models_Dialog;
class Customer_Dialog;
class Sales_Associate_Dialog;

Fl_Window *window;
Shop *shop;
Robot_Part_Dialog *robot_part_dlg;
Robot_Model_Dialog *robot_model_dlg;
List_Models_Dialog *list_models_dlg;
Customer_Dialog *customer_dlg;
Sales_Associate_Dialog *sales_assoc_dlg;


//===============================================================================================================================================================
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
	string get_name()
	{
		return name_in->value(); 
	}
	int get_part_num()
	{
		return atoi(part_num_in->value()); 
	}
	Component_type get_type()
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
	double get_weight()
	{
		return atof(weight_in->value()); 
	}
	double get_cost()
	{
		return atof(cost_in->value()); 
	}
	string get_description()
	{
		return description_in->value();
	}
	int get_num_compartments()
    {
        return (batt_compartments_in->value() + 1);
    }
    int get_speed()
    {
        return atoi(speed_in->value());
    }
    double get_power_consumed()
    {
        return atof(pwr_consumed_in->value());
    }
    double get_energy()
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
//===============================================================================================================================================================

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
        
        dialog = new Fl_Window(340, 400, "Add a Robot Model");
        
        name_in = new Fl_Input(x, y, w, h, "Name:"); y += y_incr;
        name_in->align(FL_ALIGN_LEFT);
        
        model_num_in = new Fl_Int_Input(x, y, w, h, "Model Number:"); y += y_incr;
        model_num_in->align(FL_ALIGN_LEFT);

        head_choice = new Fl_Choice(x, y, w, h, "Head:"); y += y_incr;
        head_choice->align(FL_ALIGN_LEFT);
        head_choice->callback(Selected_HeadCB, NULL);
        
        torso_choice = new Fl_Choice(x, y, w, h, "Torso:"); y += y_incr;
        torso_choice->align(FL_ALIGN_LEFT);
        torso_choice->callback(Selected_TorsoCB, NULL);

		locomotor_choice = new Fl_Choice(x, y, w, h, "Locomotor:"); y += y_incr;
		locomotor_choice->align(FL_ALIGN_LEFT);
		locomotor_choice->callback(Selected_LocomotorCB, NULL);

		for (int i = 0; i < 3; i++, y += y_incr)
		{
			battery_choices.push_back(new Fl_Choice(x, y, w, h, "Battery:")); y += y_incr;
			dialog->add(battery_choices[i]);
			battery_choices[i]->align(FL_ALIGN_LEFT);
			battery_choices[i]->callback(Selected_BatteryCB, (void*)(i));

			if (i < 2)
			{
				radio_groups.push_back(new Fl_Group(0, y + 15, 340, 75)); y += 15;
				radio_groups[i]->label("Would you like to add another battery?");
				radio_groups[i]->draw_label(x, y, w, h, FL_ALIGN_TOP | FL_ALIGN_CENTER);

				radio_groups[i]->begin();
				yes_options.push_back(new Fl_Radio_Round_Button(x + 20, y, 50, h, "Yes"));
				radio_groups[i]->add(yes_options[i]);
				yes_options[i]->callback(Yes_Another_BatteryCB, (void*)(i + 1));

				no_options.push_back(new Fl_Radio_Round_Button(x + 70, y, 40, h, "No"));
				radio_groups[i]->add(no_options[i]);
				no_options[i]->callback(No_Another_BatteryCB, (void*)(i + 1));

				radio_groups[i]->end();
				if (i > 0)
					radio_groups[i]->hide();
			}
			if (i > 0)
			{
				battery_choices[i]->hide();
			}
		}

		y -= 45;
		y -= (3 * y_incr);

		arm_choices.push_back(new Fl_Choice(x, y, w, h, "Arm:")); y += y_incr;
		dialog->add(arm_choices[0]);
		arm_choices[0]->align(FL_ALIGN_LEFT);
		arm_choices[0]->callback(Selected_ArmCB, (void*)0);

		radio_groups.push_back(new Fl_Group(0, y + 15, 340, 75)); y += 15;
		radio_groups[2]->label("Would you like to add another arm?");
		radio_groups[2]->draw_label(x, y, w, h, FL_ALIGN_TOP | FL_ALIGN_CENTER);
		//radio_groups[2]->box(FL_ROUNDED_BOX);
		radio_groups[2]->begin();
		yes_options.push_back(new Fl_Radio_Round_Button(x + 20, y, 50, h, "Yes"));
		radio_groups[2]->add(yes_options[2]);
		yes_options[2]->callback(Yes_Another_ArmCB);

		no_options.push_back(new Fl_Radio_Round_Button(x + 70, y, 40, h, "No"));
		radio_groups[2]->add(no_options[2]);
		no_options[2]->callback(No_Another_ArmCB);
		radio_groups[2]->end();

		y += y_incr;
		arm_choices.push_back(new Fl_Choice(x, y, w, h, "Arm:")); 
		dialog->add(arm_choices[1]);
		arm_choices[1]->align(FL_ALIGN_LEFT);
		arm_choices[1]->callback(Selected_ArmCB, (void*)1);
		arm_choices[1]->hide();

		part_cost_display = new Fl_Box(300, y, w, h, part_cost_display_label.c_str()); y += y_incr;
		part_cost_display->align(FL_ALIGN_LEFT);

		price_in = new Fl_Float_Input(x, y, w, h, "Price:"); y += y_incr;
		price_in->align(FL_ALIGN_LEFT);

		create = new Fl_Return_Button(145, y, 120, 25, "Create");
		create->callback((Fl_Callback *)Create_Robot_ModelCB, 0);

		cancel = new Fl_Button(270, y, 60, 25, "Cancel");
		cancel->callback((Fl_Callback *)Cancel_Robot_ModelCB, 0);

        dialog->end();
		dialog->set_non_modal();
    }
    void show()
    {
        dialog->show();
    }
	void hide()
	{
		dialog->hide();
	}
	void update_parts()
	{
		shop_heads = shop->get_available_heads();
		head_choice->clear();
		for (Head h : shop_heads)
		{
			head_choice->add((h.get_name() + " -- #" + Str_conversion::to_string(h.get_part_num())).c_str());
		}

		shop_torsos = shop->get_available_torsos();
		torso_choice->clear();
		for (Torso t : shop_torsos)
		{
			torso_choice->add((t.get_name() + " -- #" + Str_conversion::to_string(t.get_part_num())).c_str());
		}

		shop_locomotors = shop->get_available_locomotors();
		locomotor_choice->clear();
		for (Locomotor l : shop_locomotors)
		{
			locomotor_choice->add((l.get_name() + " -- #" + Str_conversion::to_string(l.get_part_num())).c_str());
		}
		
		shop_batteries = shop->get_available_batteries();
		for (int i = 0; i < battery_choices.size(); i++)
		{
			battery_choices[i]->clear();
			for (Battery b : shop_batteries)
			{
				battery_choices[i]->add((b.get_name() + " -- #" + Str_conversion::to_string(b.get_part_num())).c_str());
			}
		}

		shop_arms = shop->get_available_arms();
		for (int i = 0; i < arm_choices.size(); i++)
		{
			arm_choices[i]->clear();
			for (Arm a : shop_arms)
			{
				arm_choices[i]->add((a.get_name() + " -- #" + Str_conversion::to_string(a.get_part_num())).c_str());
			}
		}
	}
	void update_cost()
	{
		double cost = 0;

		if (chose_head)
			cost += shop_heads[head_choice->value()].get_cost();
		if (chose_torso)
			cost += shop_torsos[torso_choice->value()].get_cost();
		if (chose_locomotor)
			cost += shop_locomotors[locomotor_choice->value()].get_cost();
		if (chose_battery[0])
			cost += shop_batteries[battery_choices[0]->value()].get_cost();
		if (battery_choices[1]->visible() != 0 && chose_battery[1])
			cost += shop_batteries[battery_choices[1]->value()].get_cost();
		if (battery_choices[2]->visible() != 0 && chose_battery[2])
			cost += shop_batteries[battery_choices[2]->value()].get_cost();
		if (chose_arm[0])
			cost += shop_arms[arm_choices[0]->value()].get_cost();
		if (arm_choices[1]->visible() != 0 && chose_battery[1])
			cost += shop_arms[arm_choices[1]->value()].get_cost();

		part_cost_display_label = "Total cost of components: $" + Str_conversion::to_string(cost);
		part_cost_display->label(part_cost_display_label.c_str());
	}
	void add_another_battery()
	{
		int y_incr;

		if (battery_choices[1]->visible() == 0) // if the second battery field is invisible
		{
			y_incr = 70;
			
			battery_choices[1]->show();
			radio_groups[1]->show();
		}
		else
		{
			y_incr = 40;

			battery_choices[2]->show();
		}

		dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + y_incr);
		create->position(create->x(), create->y() + y_incr);
		cancel->position(cancel->x(), cancel->y() + y_incr);
		arm_choices[0]->position(arm_choices[0]->x(), arm_choices[0]->y() + y_incr);
		arm_choices[1]->position(arm_choices[1]->x(), arm_choices[1]->y() + y_incr);
		radio_groups[2]->position(radio_groups[2]->x(), radio_groups[2]->y() + y_incr);
		part_cost_display->position(part_cost_display->x(), part_cost_display->y() + y_incr);
		price_in->resize(price_in->x(), price_in->y() + y_incr, price_in->w(), price_in->h());
		update_cost();
	}
	void hide_extra_battery(int position)
	{
		int y_decr;

		switch (position)
		{
		case 1: // The first battery's "no" option was chosen
			if (battery_choices[1]->visible() != 0)
			{
				y_decr = 70;

				dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - y_decr);
				create->position(create->x(), create->y() - y_decr);
				cancel->position(cancel->x(), cancel->y() - y_decr);
				arm_choices[0]->position(arm_choices[0]->x(), arm_choices[0]->y() - y_decr);
				arm_choices[1]->position(arm_choices[1]->x(), arm_choices[1]->y() - y_decr);
				radio_groups[2]->position(radio_groups[2]->x(), radio_groups[2]->y() - y_decr);
				part_cost_display->position(part_cost_display->x(), part_cost_display->y() - y_decr);
				price_in->resize(price_in->x(), price_in->y() - y_decr, price_in->w(), price_in->h());

				battery_choices[1]->hide();
				radio_groups[1]->hide();
			}
		case 2:
			if (battery_choices[2]->visible() != 0)
			{
				y_decr = 40;

				dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - y_decr);
				create->position(create->x(), create->y() - y_decr);
				cancel->position(cancel->x(), cancel->y() - y_decr);
				arm_choices[0]->position(arm_choices[0]->x(), arm_choices[0]->y() - y_decr);
				arm_choices[1]->position(arm_choices[1]->x(), arm_choices[1]->y() - y_decr);
				radio_groups[2]->position(radio_groups[2]->x(), radio_groups[2]->y() - y_decr);
				part_cost_display->position(part_cost_display->x(), part_cost_display->y() - y_decr);
				price_in->resize(price_in->x(), price_in->y() - y_decr, price_in->w(), price_in->h());

				yes_options[1]->value(0);

				battery_choices[2]->hide();
			}
		default:
			update_cost();
			break;
		}
	}
	void add_another_arm()
	{
		int y_incr = 30;

		dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + y_incr);
		create->position(create->x(), create->y() + y_incr);
		cancel->position(cancel->x(), cancel->y() + y_incr);
		part_cost_display->position(part_cost_display->x(), part_cost_display->y() + y_incr);
		price_in->resize(price_in->x(), price_in->y() + y_incr, price_in->w(), price_in->h());

		arm_choices[1]->show();
		update_cost();
	}
	void hide_extra_arm()
	{
		if (arm_choices[1]->visible() != 0)
		{
			int y_decr = 30;

			dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - y_decr);
			create->position(create->x(), create->y() - y_decr);
			cancel->position(cancel->x(), cancel->y() - y_decr);
			part_cost_display->position(part_cost_display->x(), part_cost_display->y() - y_decr);
			price_in->resize(price_in->x(), price_in->y() - y_decr, price_in->w(), price_in->h());

			arm_choices[1]->hide();
			update_cost();
		}
	}

	void head_chosen()
	{
		chose_head = true;
	}
	void torso_chosen()
	{
		chose_torso = true;
		if (shop_torsos[torso_choice->value()].get_battery_compartments() == 1)
		{
			hide_extra_battery(1);
			yes_options[0]->deactivate();
			yes_options[0]->value(0);
			no_options[0]->deactivate();
			no_options[0]->value(0);
		}
		else if (shop_torsos[torso_choice->value()].get_battery_compartments() == 2)
		{
			hide_extra_battery(2);
			yes_options[0]->activate();
			no_options[0]->activate();
			yes_options[1]->deactivate();
			yes_options[1]->value(0);
			no_options[1]->deactivate();
			no_options[1]->value(0);
		}
		else
		{
			yes_options[0]->activate();
			no_options[0]->activate();
			yes_options[1]->activate();
			no_options[1]->activate();
		}
	}
	void locomotor_chosen()
	{
		chose_locomotor = true;
	}
	void battery_chosen(int index)
	{
		chose_battery[index] = true;
	}
	void arm_chosen(int index)
	{
		chose_arm[index] = true;
	}

	string get_name()
	{
		return name_in->value();
	}
	int get_model_num()
	{
		return atoi(model_num_in->value());
	}
	Head get_head()
	{
		return shop_heads[head_choice->value()];
	}
	Torso get_torso()
	{
		return shop_torsos[torso_choice->value()];
	}
	Locomotor get_locomotor()
	{
		return shop_locomotors[locomotor_choice->value()];
	}
	vector<Battery> get_batteries()
	{
		vector<Battery> model_batteries;

		model_batteries.push_back(shop_batteries[battery_choices[0]->value()]);
		if (battery_choices[1]->visible() != 0)
			model_batteries.push_back(shop_batteries[battery_choices[1]->value()]);
		if (battery_choices[2]->visible() != 0)
			model_batteries.push_back(shop_batteries[battery_choices[2]->value()]);

		return model_batteries;
	}
	vector<Arm> get_arms()
	{
		vector<Arm> model_arms;

		model_arms.push_back(shop_arms[arm_choices[0]->value()]);
		if (arm_choices[1]->visible() != 0)
			model_arms.push_back(shop_arms[arm_choices[1]->value()]);

		return model_arms;
	}
	double get_price()
	{
		return atof(price_in->value());
	}

	bool has_empty_fields()
	{
		bool is_empty = false;

		if (strcmp(name_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(model_num_in->value(), "") == 0)
			is_empty = true;
		else if (!chose_head)
			is_empty = true;
		else if (!chose_torso)
			is_empty = true;
		else if (!chose_locomotor)
			is_empty = true;
		else if (!chose_battery[0])
			is_empty = true;
		else if (battery_choices[1]->visible() != 0 && !chose_battery[1])
			is_empty = true;
		else if (battery_choices[2]->visible() != 0 && !chose_battery[2])
			is_empty = true;
		else if (!chose_arm[0])
			is_empty = true;
		else if (arm_choices[1]->visible() != 0 && !chose_arm[1])
			is_empty = true;
		else if (strcmp(price_in->value(), "") == 0)
			is_empty = true;

		return is_empty;
	}
private:
    Fl_Window* dialog;
    Fl_Input* name_in;
    Fl_Int_Input* model_num_in;
    Fl_Choice* head_choice;
    Fl_Choice* torso_choice;
    Fl_Choice* locomotor_choice;
    vector<Fl_Choice*> arm_choices;
    vector<Fl_Choice*> battery_choices;
    vector<Fl_Radio_Round_Button*> yes_options;
    vector<Fl_Radio_Round_Button*> no_options;
    vector<Fl_Group*> radio_groups;
    Fl_Box* part_cost_display;
    Fl_Float_Input* price_in;
    
    Fl_Return_Button* create;
    Fl_Button* cancel;
    
	string part_cost_display_label = "Total cost of components: $0.00";

    double total_cost;
    bool chose_head = false;
    bool chose_torso = false;
    bool chose_locomotor = false;
    vector<bool> chose_arm = { false, false };
    vector<bool> chose_battery = { false, false, false };

	vector<Head> shop_heads;
	vector<Torso> shop_torsos;
	vector<Locomotor> shop_locomotors;
	vector<Battery> shop_batteries;
	vector<Arm> shop_arms;
};
//===============================================================================================================================================================

class List_Models_Dialog
{
public:
	List_Models_Dialog()
	{
		int y = 35;
		int y_incr = 185;

		dialog = new Fl_Window(500, 900, "List of Current Robot Models");

		page_number = new Fl_Counter((dialog->w() / 2) - 75, y, 150, 25, "Page Number");
		page_number->align(FL_ALIGN_CENTER | FL_ALIGN_BOTTOM);
		page_number->precision(0);
		page_number->step(1);
		page_number->lstep(page_number->maximum());
		page_number->value(1);
		page_number->callback(Next_PageCB);
		page_number->when(FL_WHEN_CHANGED);

		done = new Fl_Return_Button(390, y, 100, 25, "Done");
		done->callback(DoneCB);

		dialog->end();
		dialog->set_non_modal();
	}
	void show()
	{
		update_models();
		construct_list(1);
		page_number->value(1);
		dialog->show();
	}
	void hide()
	{
		dialog->hide();
	}
	void update_models()
	{
		for (int i = 0; i < model_displays.size(); i++)
		{
			model_displays[i]->hide();
			if (dialog->contains(model_displays[i]) == 1)
				dialog->remove(model_displays[i]);

			expand_info[i]->hide();
			if (dialog->contains(expand_info[i]) == 1)
				dialog->remove(expand_info[i]);
		}

		shop_models = shop->get_models();
		model_displays.clear();
		expand_info.clear();
		for (int i = 0; i < shop_models.size(); i++)
		{
			model_displays.push_back(new Fl_Multiline_Output(x, 0, w, h));

			string label = Str_conversion::to_string(i + 1) + ".";
			model_displays[i]->copy_label(label.c_str());
			model_displays[i]->align(FL_ALIGN_LEFT_TOP);

			model_displays[i]->insert(shop_models[i].to_string().c_str());
			model_displays[i]->cut(model_displays[i]->position() - 1, model_displays[i]->position()); //deletes the \n at the end of the model's .to_string()

			model_displays[i]->hide();

			expand_info.push_back(new Fl_Button(265, 0, 125, 25, "Additional Info @+"));
			expand_info[i]->hide();
			expand_info[i]->callback(Expand_InfoCB, (void*)i);
		}
		if (model_displays.size() % 4 == 0)
			page_number->bounds(1, (model_displays.size() / 4));
		else
			page_number->bounds(1, (model_displays.size() / 4) + 1);
	}
	void construct_list(int page)
	{
		int y = 15;
		int y_incr = 180;
		int max = page * 4;
		int min = (page - 1) * 4;

		for (int i = 0; i < model_displays.size(); i++)
		{
			model_displays[i]->hide();
			if (dialog->contains(model_displays[i]) == 1)
				dialog->remove(model_displays[i]);

			expand_info[i]->hide();
			if (dialog->contains(expand_info[i]) == 1)
				dialog->remove(expand_info[i]);
		}

		int i;
		for (i = min; i < max && i < model_displays.size(); i++)
		{			
			model_displays[i]->resize(x, y, w, h);
			y += y_incr;			
			model_displays[i]->show();
			dialog->add(model_displays[i]);

			expand_info[i]->resize(expand_info[i]->x(), y, expand_info[i]->w(), expand_info[i]->h());
			y += 30;
			expand_info[i]->show();
			dialog->add(expand_info[i]);
		}

		page_number->resize(page_number->x(), y, page_number->w(), page_number->h());
		done->resize(done->x(), y, done->w(), done->h());

		if (i != max)
		{
			int num_missing = max - model_displays.size();

			dialog->resize(dialog->x(), dialog->y(), dialog->w(), 900 - (num_missing * (y_incr + 30)));

			string new_title;

			if (num_missing == 3)
				new_title = "List of Current Robot Models: " + Str_conversion::to_string(min + 1);
			else
				new_title = "List of Current Robot Models: " + Str_conversion::to_string(min + 1) + " - " + Str_conversion::to_string(min + (4 - num_missing));

			dialog->copy_label(new_title.c_str());
		}
		else
		{
			dialog->resize(dialog->x(), dialog->y(), dialog->w(), 900);
			string new_title = "List of Current Robot Models: " + Str_conversion::to_string(min + 1) + " - " + Str_conversion::to_string(max);
			dialog->copy_label(new_title.c_str());
		}
	}
private:
	Fl_Window* dialog;
	Fl_Counter* page_number;
	Fl_Return_Button* done;

	vector<Fl_Multiline_Output*> model_displays;
	vector<Fl_Button*> expand_info;
	vector<Robot_Model> shop_models;

	const int x = 90;
	const int w = 300;
	const int h = 175;
};
//===============================================================================================================================================================

class Customer_Dialog
{
public:
	Customer_Dialog()
	{
		int x = 120;
		int y = 10;
		int w = 210;
		int h = 25;
		int y_incr = 30;

		dialog = new Fl_Window(340, 330, "Add a New Customer");

		name_in = new Fl_Input(x, y, w, h, "Name:"); y += y_incr;
		name_in->align(FL_ALIGN_LEFT);

		phone_num_in = new Fl_Input(x, y, w, h, "Phone Number:"); y += y_incr;
		phone_num_in->align(FL_ALIGN_LEFT);

		email_in = new Fl_Input(x, y, w, h, "Email Address:"); y += y_incr;
		email_in->align(FL_ALIGN_LEFT);

		y += 20;

		apt_po_choices = new Fl_Group(0, y, dialog->w(), h, "Is this address a PO box or an apartment address?");
		apt_po_choices->align(FL_ALIGN_TOP | FL_ALIGN_CENTER);
		is_apt = new Fl_Radio_Round_Button(40, y, 40, h, "Apartment");
		is_apt->callback(Apartment_AddressCB);
		is_po = new Fl_Radio_Round_Button(150, y, 40, h, "PO Box");
		is_po->callback(PO_Box_AddressCB);
		neither = new Fl_Radio_Round_Button(250, y, 40, h, "Neither");
		neither->callback(Regular_AddressCB);
		apt_po_choices->end();
		
		y += y_incr;

		st_num_in = new Fl_Int_Input(x, y, w, h, "House/Building\nNumber:"); y += y_incr;
		st_num_in->align(FL_ALIGN_LEFT);

		st_name_in = new Fl_Input(x, y, w, h, "Street Name:"); y += y_incr;
		st_name_in->align(FL_ALIGN_LEFT);

		apt_num_in = new Fl_Int_Input(x, y, w, h, "Apartment\nNumber:");
		apt_num_in->align(FL_ALIGN_LEFT);
		apt_num_in->hide();

		city_in = new Fl_Input(x, y, w, h, "City:"); y += y_incr;
		city_in->align(FL_ALIGN_LEFT);

		state_in = new Fl_Input(x, y, w, h, "State:"); y += y_incr;
		state_in->align(FL_ALIGN_LEFT);

		zip_in = new Fl_Input(x, y, w, h, "ZIP Code:"); y += y_incr;
		zip_in->align(FL_ALIGN_LEFT);

		create = new Fl_Return_Button(120, y, 100, h, "Add");
		create->callback(Create_CustomerCB);

		cancel = new Fl_Button(230, y, 100, h, "Cancel");
		cancel->callback(Cancel_CustomerCB);
		//dialog->resizable(dialog);
		dialog->end();
		dialog->set_non_modal();
	}
	void show()
	{
		dialog->show();
	}
	void hide()
	{
		dialog->hide();
	}
	void apt_address()
	{
		int y_incr = 30;

		regular_address();

		apt_num_in->show();
		city_in->resize(city_in->x(), city_in->y() + y_incr, city_in->w(), city_in->h());
		state_in->resize(state_in->x(), state_in->y() + y_incr, state_in->w(), state_in->h());
		zip_in->resize(zip_in->x(), zip_in->y() + y_incr, zip_in->w(), zip_in->h());
		create->resize(create->x(), create->y() + y_incr, create->w(), create->h());
		cancel->resize(cancel->x(), cancel->y() + y_incr, cancel->w(), cancel->h());
		dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + y_incr);
	}
	void po_box_address()
	{
		int y_decr = 30;

		regular_address();

		st_num_in->label("PO Box Num:");
		st_name_in->hide();
		city_in->resize(city_in->x(), city_in->y() - y_decr, city_in->w(), city_in->h());
		state_in->resize(state_in->x(), state_in->y() - y_decr, state_in->w(), state_in->h());
		zip_in->resize(zip_in->x(), zip_in->y() - y_decr, zip_in->w(), zip_in->h());
		create->resize(create->x(), create->y() - y_decr, create->w(), create->h());
		cancel->resize(cancel->x(), cancel->y() - y_decr, cancel->w(), cancel->h());
		dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - y_decr);
	}
	void regular_address()
	{
		int y_decr = 30;
		int y_incr = 30;

		if (apt_num_in->visible() != 0) //if the field for the apartment number input is visible
		{
			apt_num_in->hide();
			city_in->resize(city_in->x(), city_in->y() - y_decr, city_in->w(), city_in->h());
			state_in->resize(state_in->x(), state_in->y() - y_decr, state_in->w(), state_in->h());
			zip_in->resize(zip_in->x(), zip_in->y() - y_decr, zip_in->w(), zip_in->h());
			create->resize(create->x(), create->y() - y_decr, create->w(), create->h());
			cancel->resize(cancel->x(), cancel->y() - y_decr, cancel->w(), cancel->h());
			dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() - y_decr);
		}
		else if (st_name_in->visible() == 0) //if the field for the street name input is invisible
		{
			st_name_in->show();
			city_in->resize(city_in->x(), city_in->y() + y_incr, city_in->w(), city_in->h());
			state_in->resize(state_in->x(), state_in->y() + y_incr, state_in->w(), state_in->h());
			zip_in->resize(zip_in->x(), zip_in->y() + y_incr, zip_in->w(), zip_in->h());
			create->resize(create->x(), create->y() + y_incr, create->w(), create->h());
			cancel->resize(cancel->x(), cancel->y() + y_incr, cancel->w(), cancel->h());
			dialog->resize(dialog->x(), dialog->y(), dialog->w(), dialog->h() + y_incr);
			st_num_in->label("House/Building\nNumber:");
		}
	}

	string get_name()
	{
		return name_in->value();
	}
	string get_phone_num()
	{
		return phone_num_in->value();
	}
	string get_email_address()
	{
		return email_in->value();
	}
	reference_wrapper<Address> get_address_ref()
	{
		string city = city_in->value();
		string state = state_in->value();
		string zip = zip_in->value();

		if (is_apt->value() == 1)  //selected apartment address option
		{
			int st_num = atoi(st_num_in->value());
			string st_name = st_name_in->value();
			int apt_num = atoi(apt_num_in->value());

			Apt_Address* address = new Apt_Address(st_num, st_name, city, state, zip, apt_num);
			reference_wrapper<Address> address_ref{ *address };
			return address_ref;
		}
		else if (is_po->value() == 1)  //selected po box address option
		{
			int po_box_num = atoi(st_num_in->value());

			PO_Box_Address* address = new PO_Box_Address(po_box_num, city, state, zip);
			reference_wrapper<Address> address_ref{ *address };
			return address_ref;
		}
		else
		{
			int st_num = atoi(st_num_in->value());
			string st_name = st_name_in->value();

			Address* address = new Address(st_num, st_name, city, state, zip);
			reference_wrapper<Address> address_ref{ *address };
			return address_ref;
		}
	}

	bool has_empty_fields()
	{
		bool is_empty = false;

		if (strcmp(name_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(phone_num_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(email_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(st_num_in->value(), "") == 0)
			is_empty = true;
		else if (is_po->value() == 0 && strcmp(st_name_in->value(), "") == 0)
			is_empty = true;
		else if (is_apt->value() == 1 && strcmp(apt_num_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(city_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(state_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(zip_in->value(), "") == 0)
			is_empty = true;

		return is_empty;
	}
private:
	Fl_Window* dialog;
	Fl_Input* name_in;
	Fl_Input* phone_num_in;
	Fl_Input* email_in;
	Fl_Int_Input* st_num_in;
	Fl_Input* st_name_in;
	Fl_Input* city_in;
	Fl_Input* state_in;
	Fl_Input* zip_in;

	Fl_Group* apt_po_choices;
	Fl_Radio_Round_Button* is_apt;
	Fl_Radio_Round_Button* is_po;
	Fl_Radio_Round_Button* neither;

	Fl_Int_Input* apt_num_in;

	Fl_Return_Button* create;
	Fl_Button* cancel;
};
//===============================================================================================================================================================

class Sales_Associate_Dialog
{
public:
	Sales_Associate_Dialog()
	{
		int x = 130;
		int y = 10;
		int w = 210;
		int h = 25;
		int y_incr = 30;

		dialog = new Fl_Window(350, 100, "Add a Sales Associate");

		name_in = new Fl_Input(x, y, w, h, "Name:"); y += y_incr;
		name_in->align(FL_ALIGN_LEFT);

		emp_num_in = new Fl_Int_Input(x, y, w, h, "Employee Number:"); y += y_incr;
		emp_num_in->align(FL_ALIGN_LEFT);

		create = new Fl_Return_Button(x + 20, y, 100, h, "Add");
		create->callback(Create_Sales_AssociateCB);

		cancel = new Fl_Button(x + 135, y, 75, h, "Cancel");
		cancel->callback(Cancel_Sales_AssociateCB);

		dialog->end();
		dialog->set_non_modal();
	}
	void show()
	{
		dialog->show();
	}
	void hide()
	{
		dialog->hide();
	}

	string get_name()
	{
		return name_in->value();
	}
	int get_employee_num()
	{
		return atoi(emp_num_in->value());
	}

	bool has_empty_fields()
	{
		bool is_empty = false;

		if (strcmp(name_in->value(), "") == 0)
			is_empty = true;
		else if (strcmp(emp_num_in->value(), "") == 0)
			is_empty = true;

		return is_empty;
	}
private:
	Fl_Window* dialog;
	Fl_Input* name_in;
	Fl_Int_Input* emp_num_in;
	Fl_Return_Button* create;
	Fl_Button* cancel;
};
//===============================================================================================================================================================
int main()
{
	const int X = 500;
	const int Y = 500;

	robot_part_dlg = new Robot_Part_Dialog();
	robot_model_dlg = new Robot_Model_Dialog();
	list_models_dlg = new List_Models_Dialog();
	customer_dlg = new Customer_Dialog();
	sales_assoc_dlg = new Sales_Associate_Dialog();
	window = new Fl_Window(X, Y);
	
	Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, X, 30);

	Fl_Menu_Item menuitems[] = {
		{"&New", 0, 0, 0, FL_SUBMENU },
			{"Robot &Part", 0, (Fl_Callback*)Open_Robot_Part_DialogCB },
			{"Robot &Model",0, (Fl_Callback*)Open_Robot_Model_DialogCB },
			{"&Customer", 0, (Fl_Callback*)Open_Customer_DialogCB},
			{"&Sales Associate", 0, (Fl_Callback*)Open_Sales_Associate_DialogCB},
			{ 0 },
		{"&Report", 0, 0, 0, FL_SUBMENU },
			{"&All Robot Models", 0, (Fl_Callback*)Open_List_Models_DialogCB},
			{ 0 },
		{"Debug", 0, 0, 0, FL_SUBMENU },
			{"Generate Parts", 0, (Fl_Callback*)Debug_Generate_PartsCB },
			{"Generate Models", 0, (Fl_Callback*)Debug_Generate_ModelsCB },
			{"Generate One Model", 0, (Fl_Callback*)Debug_Generate_One_ModelCB},
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
//================================================================================================================================================================

void Create_Robot_PartCB(Fl_Widget* w, void* p)
{
    if(robot_part_dlg->has_empty_fields())
    {
		fl_beep(FL_BEEP_DEFAULT);
        fl_alert("ERROR:\nNot enough information to create a robot part");
    }
    else
    {
        string name = robot_part_dlg->get_name();
        int part_num = robot_part_dlg->get_part_num();
        double weight = robot_part_dlg->get_weight();
        double cost = robot_part_dlg->get_cost();
        string description = robot_part_dlg->get_description();
        Head* head;
        Torso* torso;
        Locomotor* locomotor;
        Battery* battery;
        Arm* arm;
        
        if(robot_part_dlg->get_type() == Component_type::Head)
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
					fl_beep(FL_BEEP_DEFAULT);
                    fl_alert("ERROR:\nThat part number already exists!");
                }
            }
        }
        else if(robot_part_dlg->get_type() == Component_type::Torso)
        {
            int num_batt_compartments = robot_part_dlg->get_num_compartments();
            
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
					fl_beep(FL_BEEP_DEFAULT);
                    fl_alert("ERROR:\nThat part number already exists!");
                }
            }
        }
        else if(robot_part_dlg->get_type() == Component_type::Locomotor)
        {
            double pwr_consumed = robot_part_dlg->get_power_consumed();
            int speed = robot_part_dlg->get_speed();
            
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
					fl_beep(FL_BEEP_DEFAULT);
                    fl_alert("ERROR:\nThat part number already exists!");
                }
            }
        }
        else if(robot_part_dlg->get_type() == Component_type::Battery)
        {
            double energy = robot_part_dlg->get_energy();
            
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
					fl_beep(FL_BEEP_DEFAULT);
                    fl_alert("ERROR:\nThat part number already exists!");
                }
            }
        }
        else if(robot_part_dlg->get_type() == Component_type::Arm)
        {
            double pwr_consumed = robot_part_dlg->get_power_consumed();
            
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
					fl_beep(FL_BEEP_DEFAULT);
                    fl_alert("ERROR:\nThat part number already exists!");
                }
            }
        }

		robot_model_dlg->update_parts();
    }
}

void Open_Robot_Part_DialogCB(Fl_Widget * w, void * p)
{
	robot_part_dlg->show();
}

void CloseCB(Fl_Widget* w, void* p)
{
	int choice = fl_ask("Are you sure you want to quit?\nAll your data will be lost.");
	if(choice == 1) //Yes
		window->hide();
}

void Cancel_Robot_PartCB(Fl_Widget* w, void* p)
{
	robot_part_dlg->hide();
}

void Selected_Part_TypeCB(Fl_Widget * w, void * p)
{
	if (robot_part_dlg->get_type() == Component_type::Torso)
		robot_part_dlg->show_torso_extras();
	else if (robot_part_dlg->get_type() == Component_type::Locomotor)
        robot_part_dlg->show_locomotor_extras();
    else if (robot_part_dlg->get_type() == Component_type::Battery)
        robot_part_dlg->show_battery_extras();
    else if (robot_part_dlg->get_type() == Component_type::Arm)
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
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nThere are not enough parts registered to create a robot model.\nPlease add more parts and try again.");
	}
	else
        robot_model_dlg->show();
}

void Selected_HeadCB(Fl_Widget* w, void* p)
{
	robot_model_dlg->head_chosen();
	robot_model_dlg->update_cost();
}

void Selected_TorsoCB(Fl_Widget * w, void * p)
{
	robot_model_dlg->torso_chosen();
	robot_model_dlg->update_cost();
}

void Selected_LocomotorCB(Fl_Widget * w, void * p)
{
	robot_model_dlg->locomotor_chosen();
	robot_model_dlg->update_cost();
}

void Selected_BatteryCB(Fl_Widget * w, void * p)
{
	int num = (int)p;
	robot_model_dlg->battery_chosen(num);
	robot_model_dlg->update_cost();
}

void Selected_ArmCB(Fl_Widget * w, void * p)
{
	int num = (int)p;
	robot_model_dlg->arm_chosen(num);
	robot_model_dlg->update_cost();
}

void Debug_Generate_PartsCB(Fl_Widget * w, void * p)
{
	for (int i = 0; i < 40; i++)
	{
		try
		{
			shop->create_rand_part();
		}
		catch (Part_Num_Exists& e)
		{
		}
	}
	fl_message("DEBUG: Random parts created.");
	robot_model_dlg->update_parts();
}

void Debug_Generate_ModelsCB(Fl_Widget * w, void * p)
{
	try
	{
		for (int i = 0; i < 10; i++)
		{
			try
			{
				shop->create_rand_model();
			}
			catch (Model_Num_Exists& e)
			{
				fl_beep(FL_BEEP_DEFAULT);
				fl_alert("ERROR:\nThat part number already exists!");
			}
		}
		fl_message("DEBUG: Random models created.");
	}
	catch (Missing_Parts& e)
	{
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nThere are not enough parts registered to create a robot model.");
	}
}

void Yes_Another_BatteryCB(Fl_Widget * w, void * p)
{
	robot_model_dlg->add_another_battery();
}

void No_Another_BatteryCB(Fl_Widget * w, void * p)
{
	int num = (int)p;
	robot_model_dlg->hide_extra_battery(num);
}

void Yes_Another_ArmCB(Fl_Widget * w, void * p)
{
	robot_model_dlg->add_another_arm();
}

void No_Another_ArmCB(Fl_Widget * w, void * p)
{
	robot_model_dlg->hide_extra_arm();
}

void Create_Robot_ModelCB(Fl_Widget * w, void * p)
{
	if (robot_model_dlg->has_empty_fields())
	{
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nNot enough information to create a robot model.");
	}
	else
	{
		string name = robot_model_dlg->get_name();
		int model_num = robot_model_dlg->get_model_num();
		Head head = robot_model_dlg->get_head();
		Torso torso = robot_model_dlg->get_torso();
		Locomotor locomotor = robot_model_dlg->get_locomotor();
		vector<Battery> batteries = robot_model_dlg->get_batteries();
		vector<Arm> arms = robot_model_dlg->get_arms();
		double price = robot_model_dlg->get_price();

		Robot_Model* new_model = new Robot_Model(name, model_num, price, head, torso, locomotor, &arms, batteries);
		int correct = fl_ask(("Is this correct?\n" + new_model->to_string()).c_str());
		if (correct == 1) //Yes
		{
			try
			{
				shop->add(*new_model);
				fl_message((name + " was successfully added.").c_str());
				robot_model_dlg->hide();
			}
			catch (Model_Num_Exists& e)
			{
				fl_beep(FL_BEEP_DEFAULT);
				fl_alert("ERROR:\nThat model number already exists!");
			}
		}
	}
}

void Cancel_Robot_ModelCB(Fl_Widget * w, void * p)
{
	robot_model_dlg->hide();
}

void Open_List_Models_DialogCB(Fl_Widget * w, void * p)
{
	if (shop->get_models().size() > 0)
	{
		list_models_dlg->show();
	}
	else
	{
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nThere are no models to list.");
	}
}

void Next_PageCB(Fl_Widget * w, void * p)
{
	Fl_Counter* page = (Fl_Counter*)w;
	list_models_dlg->construct_list(page->value());
}

void DoneCB(Fl_Widget * w, void * p)
{
	list_models_dlg->hide();
}

void Debug_Generate_One_ModelCB(Fl_Widget * w, void * p)
{
	try
	{
		try
		{
			shop->create_rand_model();
		}
		catch (Model_Num_Exists& e)
		{
			fl_beep(FL_BEEP_DEFAULT);
			fl_alert("ERROR:\nThat model number already exists!");
		}
		fl_message("DEBUG: One random model created.");
	}
	catch (Missing_Parts& e)
	{
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nThere are not enough parts registered to create a robot model.");
	}
}

void Expand_InfoCB(Fl_Widget * w, void * p)
{
	int index = (int)p;
	vector<Robot_Model> shop_models = shop->get_models();

	string result;
	result = "Head:\n" + shop_models[index].get_head().to_string()
		+ "\nTorso:\n" + shop_models[index].get_torso().to_string()
		+ "\nLocomotor:\n" + shop_models[index].get_locomotor().to_string();

	if(shop_models[index].get_batteries().size() + shop_models[index].get_arms().size() > 3)
	{
		if (shop_models[index].get_batteries().size() == 3)
		{
			for (int i = 0; i < shop_models[index].get_batteries().size(); i++)
				result += "\nBattery " + Str_conversion::to_string(i + 1) + ":\n" + shop_models[index].get_batteries()[i].to_string();
			fl_message(result.c_str());

			result = "";
			for (int i = 0; i < shop_models[index].get_arms().size(); i++)
				result += "\nArm " + Str_conversion::to_string(i + 1) + ":\n" + shop_models[index].get_arms()[i].to_string();
			fl_message(result.c_str());
		}
		else if(shop_models[index].get_batteries().size() == 2)
		{
			for (int i = 0; i < shop_models[index].get_batteries().size(); i++)
				result += "\nBattery " + Str_conversion::to_string(i + 1) + ":\n" + shop_models[index].get_batteries()[i].to_string();
			result += "\nArm 1:\n" + shop_models[index].get_arms()[0].to_string();
			fl_message(result.c_str());

			result = "Arm 2:\n" + shop_models[index].get_arms()[1].to_string();
			fl_message(result.c_str());
		}
	}
	else
	{
		for (int i = 0; i < shop_models[index].get_batteries().size(); i++)
			result += "\nBattery " + Str_conversion::to_string(i + 1) + ":\n" + shop_models[index].get_batteries()[i].to_string();
		for (int i = 0; i < shop_models[index].get_arms().size(); i++)
			result += "\nArm " + Str_conversion::to_string(i + 1) + ":\n" + shop_models[index].get_arms()[i].to_string();
		fl_message(result.c_str());
	}
}

void Open_Customer_DialogCB(Fl_Widget * w, void * p)
{
	customer_dlg->show();
}

void Cancel_CustomerCB(Fl_Widget * w, void * p)
{
	customer_dlg->hide();
}

void Apartment_AddressCB(Fl_Widget * w, void * p)
{
	customer_dlg->apt_address();
}

void PO_Box_AddressCB(Fl_Widget * w, void * p)
{
	customer_dlg->po_box_address();
}

void Regular_AddressCB(Fl_Widget * w, void * p)
{
	customer_dlg->regular_address();
}

void Create_CustomerCB(Fl_Widget * w, void * p)
{
	if (customer_dlg->has_empty_fields())
	{
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nNot enough information to create a customer.");
	}
	else
	{
		string name = customer_dlg->get_name();
		string phone_num = customer_dlg->get_phone_num();
		string email_address = customer_dlg->get_email_address();
		reference_wrapper<Address> address_ref = customer_dlg->get_address_ref();

		Customer* new_customer = new Customer(name, address_ref, phone_num, email_address);
		
		// Note: This section is for properly formatting the customer's .to_string() output. If the 2nd @ symbol is not added, then FLTK will stop printing once it reaches it.
		// This section also checks to make sure any entered email address has one and only one @ symbol.
		stringstream adding_at;
		string result;
		bool found_at = false;
		bool found_2nd_at = false;
		adding_at << new_customer->to_string();
		while (adding_at)
		{
			char current = adding_at.get();
			if (current == '@')
			{
				if (found_at)
				{
					fl_beep(FL_BEEP_DEFAULT);
					fl_alert("ERROR:\nThe entered email is invalid!");
					found_2nd_at = true;
				}
				else
					found_at = true;

				int pos = adding_at.tellg();
				result = adding_at.str().insert(pos, 1, '@');
				adding_at.unget();
				adding_at.ignore();
			}
			else
			{
				adding_at.unget();
				adding_at.ignore();
			}
			
		}

		if (found_at && !found_2nd_at)
		{
			int correct = fl_ask(("Is this correct?\n" + result).c_str());
			if (correct == 1) //Yes
			{
				try
				{
					shop->add(*new_customer);
					fl_message((name + " was successfully added.").c_str());
					customer_dlg->hide();
				}
				catch (Customer_Exists& e)
				{
					fl_beep(FL_BEEP_DEFAULT);
					fl_alert("ERROR:\nThat customer already exists!");
				}
			}
		}
		else if (!found_at)
		{
			fl_beep(FL_BEEP_DEFAULT);
			fl_alert("ERROR:\nThe entered email is invalid!");
		}

	}
}

void Open_Sales_Associate_DialogCB(Fl_Widget * w, void * p)
{
	sales_assoc_dlg->show();
}

void Cancel_Sales_AssociateCB(Fl_Widget * w, void * p)
{
	sales_assoc_dlg->hide();
}

void Create_Sales_AssociateCB(Fl_Widget * w, void * p)
{
	if (sales_assoc_dlg->has_empty_fields())
	{
		fl_beep(FL_BEEP_DEFAULT);
		fl_alert("ERROR:\nNot enough information to create a sales associate.");
	}
	else
	{
		string name = sales_assoc_dlg->get_name();
		int employee_num = sales_assoc_dlg->get_employee_num();

		Sales_Associate* new_associate = new Sales_Associate(name, employee_num);
		int correct = fl_ask(("Is this correct?\n" + new_associate->to_string()).c_str());
		if (correct == 1) //Yes
		{
			try
			{
				shop->add(*new_associate);
				fl_message((name + " was successfully added.").c_str());
				sales_assoc_dlg->hide();
			}
			catch (Sales_Associate_Exists& e)
			{
				fl_beep(FL_BEEP_DEFAULT);
				fl_alert("ERROR:\nThat employee number already exists!");
			}
		}
	}
}
