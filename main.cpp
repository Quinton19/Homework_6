

#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>

#include "Controller.h"

void Create_Robot_PartCB(Fl_Widget* w, void* p);
void CloseCB(Fl_Widget* w, void* p);

Fl_Window *window;
Controller *controller;

int main()
{
	Shop shop;
	controller = new Controller(shop);

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

	window->callback(Create_Robot_PartCB, "replace later");
	window->callback(CloseCB, &t);
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
	controller->Robot_Part_Dialog();
}

void CloseCB(Fl_Widget* w, void* p)
{
	window->hide();
}