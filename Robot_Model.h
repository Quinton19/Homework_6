#include "Arm.h"
#include "Battery.h"
#include "Head.h"
#include "Torso.h"
#include "Locomotor.h"

class Arm_Limit {};
class Battery_Limit {};

class Robot_Model
{
private:
	Head head;
	Torso torso;
	Locomotor locomotor;
	vector<Arm> arms;
	vector<Battery> batteries;
	string name;
	int model_num;
	double price;
public:
	Robot_Model(string n, int mn, double p, Head h, Torso t, Locomotor l, vector<Arm>* a, vector<Battery> b);
	string get_name();
	int get_model_num();
	double get_price();
	Head get_head();
	Torso get_torso();
	Locomotor get_locomotor();
	vector<Arm> get_arms();
	vector<Battery> get_batteries();
	void set_price(double p);
	void add_arm(Arm a);
	void add_battery(Battery b);
	string to_string();
	double get_component_cost();
};