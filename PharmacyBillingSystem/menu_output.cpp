#include "menu_output.hpp"
#include "sign_in.hpp"
#include "pharmacist_option.hpp"
#include "add_person.hpp"
#include "pharmacist_output.hpp"
#include "pharmacist_option_output.hpp"
#include "person_create_query.hpp"
#include "type.hpp"

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