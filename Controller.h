#include "View.h"

class Controller
{
private:
	View view;
	Shop& shop;
public:
	Controller(Shop& s) : shop(s), view(View(s)) { }
	void cli();
	void execute_cmd(int cmd);
	void add_new_part();
	void add_new_model();
	void list_all_models();
	void order_robot_models();
};
