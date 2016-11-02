#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>

#include "Controller.h"

int main()
{
	Shop shop;

	Fl_Window *win = new Fl_Window(340, 180);

	//shop.create_rand_part();

	Head *h;
	Torso *t, *t2;
	Locomotor *l;
	Battery *b;
	Arm *a;

	t = new Torso("Test torso", 123456, 12.5, 12.7, "Testing, testing, 1, 2, 3", 2);
	shop.add(*t);

	if (shop.get_available_heads().size() != 0)
	{
		*h = shop.get_available_heads()[0];
		fl_choice(("Random head created:\n" + h->to_string()).c_str(), "OK");
	}
	else if (shop.get_available_torsos().size() != 0)
	{
		*t2 = shop.get_available_torsos()[0];
		string cpp_str_out = "Random torso created:\n" + t2->to_string();
		char* c_str_out = cpp_str_out.c_str();
		fl_choice(c_str_out, "OK", 0, 0);
	}
	else if (shop.get_available_locomotors().size() != 0)
	{
		*l = shop.get_available_locomotors()[0];
		fl_choice(("Random locomotor created:\n" + l->to_string()).c_str(), "OK");
	}
	else if (shop.get_available_batteries().size() != 0)
	{
		*b = shop.get_available_batteries()[0];
		fl_choice(("Random battery created:\n" + b->to_string()).c_str(), "OK");
	}
	else
	{
		*a = shop.get_available_arms()[0];
		fl_choice(("Random arm created:\n" + h->to_string()).c_str(), "OK");
	}

	win->end();
	win->show();

	return(Fl::run());
}