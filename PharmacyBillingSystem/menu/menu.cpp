#include <iostream>
#include "menu/menu.hpp"
#include "validations/is_menu_choice_valid.hpp"

unsigned short menu()
{
	unsigned short choice = 0;
		
		while (!isMenuChoiceValid(choice))
		{
			system("cls");
			std::cout << "                                      1.Sign in" << std::endl
				      << "                                      2.Sign up" << std::endl
			          << "                                      3.Exit";
			std::cin >> choice;
		}
		return choice;
}