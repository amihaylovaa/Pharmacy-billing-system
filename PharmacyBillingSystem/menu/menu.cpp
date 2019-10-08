#include <iostream>
#include "menu/menu.hpp"
#include "validations/menu_validation.hpp"

// Represents the main menu of the application.
// It is used to gurantee that
// only authenticated users can access the system
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