#include "Robot_Model.h"

class Part_Num_Exists {};
class Model_Num_Exists {};
class Missing_Parts {};
/*
class Part_Num_DNE {};
class Invalid_Model {};
*/

class Shop
{
private:
	vector<Robot_Model> models;
	vector<Head> heads;
	vector<Torso> torsos;
	vector<Locomotor> locomotors;
	vector<Arm> arms;
	vector<Battery> batteries;
	static int num_rand_heads;
	static int num_rand_torsos;
	static int num_rand_locomotors;
	static int num_rand_arms;
	static int num_rand_batteries;
	static int num_rand_models;
public:
	Shop();
	void add(Head h);
	void add(Torso t);
	void add(Locomotor l);
	void add(Arm a);
	void add(Battery b);
	void add(Robot_Model model);
	vector<Robot_Model> get_models();
	void create_rand_part(); //for testing purposes only
	void create_rand_model(); //for testing purposes only
	vector<Head> get_available_heads();
	vector<Torso> get_available_torsos();
	vector<Locomotor> get_available_locomotors();
	vector<Arm> get_available_arms();
	vector<Battery> get_available_batteries();
	/*
	void remove(Head h);
	void remove(Torso t);
	void remove(Locomotor l);
	void remove(Arm a);
	void remove(Battery b);
	*/
};