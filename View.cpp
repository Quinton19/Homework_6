#include "View.h"
#include <chrono>
#include <ctime>

void View::view_part_info(Robot_Part p)
{
	cout << p.to_string();
}

void View::display_menu()
{
	cout<< "=================================================\n"
		<< "----------Robbie Robot Shop - Main Menu----------\n"
		<< "=================================================\n"
		<< "1) Add new robot part\n"
		<< "2) Add new robot model\n"
		<< "3) Browse robot model catalog\n"
		<< "4) Order robot models\n"
		<< "9) Get help on how to use the system\n"
		<< "0) Exit\n";
}

void View::display_heads_list()
{
	vector<Head> shop_heads = shop.get_available_heads();
	for (int i = 0; i < shop_heads.size(); i++)
	{
		cout << i+1 << ") " << shop_heads[i].to_string() << "\n";
	}
}

void View::display_torsos_list()
{
	vector<Torso> shop_torsos = shop.get_available_torsos();
	for (int i = 0; i < shop_torsos.size(); i++)
	{
		cout << i + 1 << ") " << shop_torsos[i].to_string() << "\n";
	}
}

void View::display_locomotors_list()
{
	vector<Locomotor> shop_locomotors = shop.get_available_locomotors();
	for (int i = 0; i < shop_locomotors.size(); i++)
	{
		cout << i + 1 << ") " << shop_locomotors[i].to_string() << "\n";
	}
}

void View::display_arms_list()
{
	vector<Arm> shop_arms = shop.get_available_arms();
	for (int i = 0; i < shop_arms.size(); i++)
	{
		cout << i + 1 << ") " << shop_arms[i].to_string() << "\n";
	}
}

void View::display_batteries_list()
{
	vector<Battery> shop_batteries = shop.get_available_batteries();
	for (int i = 0; i < shop_batteries.size(); i++)
	{
		cout << i + 1 << ") " << shop_batteries[i].to_string() << "\n";
	}
}

void View::display_robot_models()
{
	vector<Robot_Model> shop_models = shop.get_models();
	for (int i = 0; i < shop_models.size(); i++)
	{
		cout << i + 1 << ") " << shop_models[i].to_string() << "\n";
	}
}

void View::help()
{
	cout << "Type a number into the computer and press ENTER to select the corresponding option on the menu.\n"
		<< "See the Robbie Robot Shop Manager user manual for more information on how the system works.\n\n";
}

void View::display_receipt_header()
{/*
	chrono::time_point<chrono::system_clock> now;
	now = chrono::system_clock::now();
	time_t time = chrono::system_clock::to_time_t(now);
	cout << "-------------------------------------------------\n"
		<< "          Robbie Robot Shop Model Order          \n"
		<< "-------------------------------------------------\n"
		<< "Date: " << ctime(&time) << "\n"
		<< "Order:\n";*/
}
