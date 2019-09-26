#include "menu/menu_output.hpp"
#include "menu/sign_in.hpp"
#include "menu/pharmacist_menu.hpp"
#include "menu/pharmacist_menu_output.hpp"
#include "create/person utils/add_person.hpp"
#include "create/create_person_type.hpp"
#include "create/create_person_type.hpp"
#include "sql/queries/person_create_query.hpp"

personType typePerson;

void menuOutput(unsigned short choice)
{    
	system("cls");
	typePerson = pharmacist;

	if (choice != 1 && choice != 2)
		return;

	if (choice == 1)
	{
		int pharmacistId = signIn(typePerson);
		pharmacistOptionOutput(pharmacistId, pharmacistOption());
	}

	if (choice == 2)
	{
		addPerson(typePerson);
		menuOutput(choice = 1);
	}
}