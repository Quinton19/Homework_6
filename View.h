#include "Shop.h"

class View
{
private:
	Shop& shop;
public:
	View(Shop& s) : shop(s) {}
	void view_part_info(Robot_Part p);
	void display_menu();
	void display_heads_list();
	void display_torsos_list();
	void display_locomotors_list();
	void display_arms_list();
	void display_batteries_list();
	void display_robot_models();
	void help();
	void display_receipt_header();
};
