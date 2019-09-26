#include <iostream>
#include "menu/pharmacist_menu.hpp"
#include "validations/menu_validation.hpp"

unsigned short pharmacistOption()
{
	unsigned short choice = 0;

	while (!isMenuChoiceValid(choice))
	{
		system("cls");
		std::cout << "                             1.Purchase:" << std::endl 
		          << "                             2.Add new product" << std::endl
	              << "                             3.Add new customer";
		std::cin >> choice;
	}
	return choice;
}