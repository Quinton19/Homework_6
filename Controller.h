#include "View.h"
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Menu_Item.H>
class Controller
{
private:
	Shop& shop;
    //Fl_Window* win;
    //Fl_Menu_Item *items;
public:
	Controller(Shop& s) : shop(s) { }
	//void Robot_Part_Dialog();
	/*
	void cli();
	void execute_cmd(int cmd);
	void add_new_part();
	void add_new_model();
	void list_all_models();
	void order_robot_models();
	*/
};
