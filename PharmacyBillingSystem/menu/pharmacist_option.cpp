#include <iostream>
#include "pharmacist_option.hpp"
#include "is_menu_choice_valid.hpp"

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