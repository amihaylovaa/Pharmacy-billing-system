#include <iostream>
#include "validations/is_menu_choice_valid.hpp"

bool isMenuChoiceValid(unsigned short choice)
{
	system("cls");

	if (std::cin.fail())
	{
		std::cout << "                                Invalid input! Please, try again:";

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> choice;
		}
	}
	return (choice == 1 || choice == 2 || choice == 3);
}