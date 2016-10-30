#include "Controller.h"

int main()
{
	Shop shop;
	Controller controller(shop);
	controller.cli();
	return 1;
}