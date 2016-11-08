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
#include <FL/fl_ask.H>
#include <string>
#include <iostream>

using namespace std;

#include "Controller.h"

void Create_Robot_PartCB(Fl_Widget* w, void* p);
void CloseCB(Fl_Widget* w, void* p);
void head_cb(Fl_Widget* w, void* p);
void torso_cb(Fl_Widget* w, void* p);
void locomotor_cb(Fl_Widget* w, void* p);
void battery_cb(Fl_Widget* w, void* p);
void arm_cb(Fl_Widget* w, void* p);

Fl_Window *window;
Fl_Window *create_robot_part;

int main()
{
	Shop shop;

	int t = 2;

	const int X = 500;
	const int Y = 500;

	window = new Fl_Window(X, Y);
	Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, X, 30);

	Fl_Menu_Item menuitems[] = {
		{"&Create", 0, 0, 0, FL_SUBMENU },
			{"&Robot Part", 0, (Fl_Callback*)Create_Robot_PartCB },
			{ 0 },
		{"&Quit", 0, (Fl_Callback*)CloseCB },
		{ 0 }
	};

	menubar->menu(menuitems);

	window->callback(Create_Robot_PartCB, window);
	window->callback(CloseCB, &t);
    
    {
        const int X = 20;
        int Y = 20;
        const int W = 250;
        const int H = 35;
        string* choice;
        choice = new string{"Select the part type"};
        
        create_robot_part = new Fl_Window(500, 600, "Create a Robot Part");
        
        Fl_Menu_Button* part_choice = new Fl_Menu_Button(X, Y, W, H, choice->c_str());
        Y += H + 35;
        
        Fl_Menu_Item part_types[] = {
            {"Head", 0, (Fl_Callback*)head_cb },
            {"Torso", 0, (Fl_Callback*)torso_cb },
            {"Locomotor", 0, (Fl_Callback*)locomotor_cb },
            {"Battery", 0, (Fl_Callback*)battery_cb },
            {"Arm", 0, (Fl_Callback*)arm_cb },
            { 0 }
        };
        
        part_choice->menu(part_types);
        
        create_robot_part->callback(head_cb, choice);
        create_robot_part->callback(torso_cb, choice);
        create_robot_part->callback(locomotor_cb, choice);
        create_robot_part->callback(battery_cb, choice);
        create_robot_part->callback(arm_cb, choice);
        
        
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
        
        create_robot_part->resizable(create_robot_part);
        create_robot_part->end();
    }
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
    create_robot_part->show();
}

void CloseCB(Fl_Widget* w, void* p)
{
	window->hide();
}

void head_cb(Fl_Widget* w, void* p)
{
    string* chosen_option = (string*)p;
    chosen_option = new string{"Head"};
    cout << (*chosen_option);
}
void torso_cb(Fl_Widget* w, void* p)
{
    string* chosen_option = (string*)p;
    chosen_option = new string{"Torso"};
}
void locomotor_cb(Fl_Widget* w, void* p)
{
    string* chosen_option = (string*)p;
    chosen_option = new string{"Locomotor"};
}
void battery_cb(Fl_Widget* w, void* p)
{
    string* chosen_option = (string*)p;
    chosen_option = new string{"Battery"};
}
void arm_cb(Fl_Widget* w, void* p)
{
    string* chosen_option = (string*)p;
    chosen_option = new string{"Arm"};
}
