

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
	window->resizable();

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


/*
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Output.H>
//
// Simple 'wizard' using fltk's new Fl_Wizard widget
//
Fl_Window *G_win = 0;
Fl_Wizard *G_wiz = 0;

void back_cb(Fl_Widget*, void*) { G_wiz->prev(); }
void next_cb(Fl_Widget*, void*) { G_wiz->next(); }
void done_cb(Fl_Widget*, void*) { exit(0); }

int main(int argc, char **argv) {
	G_win = new Fl_Window(400, 300, "Example Wizard");
	G_wiz = new Fl_Wizard(0, 0, 400, 300);

	// Wizard: page 1
	{
		Fl_Group *g = new Fl_Group(0, 0, 400, 300);
		Fl_Button *next = new Fl_Button(290, 265, 100, 25, "Next @->"); next->callback(next_cb);
		Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 30, 400 - 20, 300 - 80, "Welcome");
		out->labelsize(20);
		out->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
		out->value("This is First page");
		g->end();
	}
	// Wizard: page 2
	{
		Fl_Group *g = new Fl_Group(0, 0, 400, 300);
		Fl_Button *next = new Fl_Button(290, 265, 100, 25, "Next @->"); next->callback(next_cb);
		Fl_Button *back = new Fl_Button(180, 265, 100, 25, "@<- Back"); back->callback(back_cb);
		Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 30, 400 - 20, 300 - 80, "Terms And Conditions");
		out->labelsize(20);
		out->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
		out->value("This is the Second page");
		g->end();
	}
	// Wizard: page 3
	{
		Fl_Group *g = new Fl_Group(0, 0, 400, 300);
		Fl_Button *done = new Fl_Button(290, 265, 100, 25, "Finish"); done->callback(done_cb);
		Fl_Button *back = new Fl_Button(180, 265, 100, 25, "@<- Back"); back->callback(back_cb);
		Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 30, 400 - 20, 300 - 80, "Finish");
		out->labelsize(20);
		out->align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
		out->value("This is the Last page");
		g->end();
	}
	G_wiz->end();
	G_win->end();
	G_win->show(argc, argv);
	return Fl::run();
}
*/