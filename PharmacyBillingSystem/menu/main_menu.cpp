#include "menu/main_menu.hpp"
#include "menu/sign_in.hpp"
#include "menu/pharmacist_menu.hpp"
#include "create/person utils/add_person.hpp"
#include "create/create_person_type.hpp"
#include "create/create_person_type.hpp"
#include "sql/queries/person_create_query.hpp"
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
		std::cout << "                                  1.Sign in" << std::endl;
		std::cout << "                                  2.Sign up" << std::endl;
		std::cout << "                                  3.Exit";
		std::cin >> choice;
	}
	return choice;
}

// Evaluates the choice from the main menu input 
// and navigates the flow of execution
void menuOutput(unsigned short choice)
{    
	system("cls");
	personType = pharmacist;

	if (choice != 1 && choice != 2)
		return;

	if (choice == 1)
	{
		int pharmacistId = signIn(personType);
		pharmacistOptionOutput(pharmacistId, pharmacistOption());
	}

	if (choice == 2)
	{
		addPerson(personType);
		menuOutput(choice = 1);
	}
}