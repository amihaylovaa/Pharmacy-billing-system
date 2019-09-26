#include <iostream>
#include "menu/sign_in.hpp"
#include "sql/queries/sign_in_query.hpp"
#include "sql/queries/execute_query.hpp"
#include "validations/authentication.hpp"

unsigned int signIn(personType typeOfPerson)
{
	unsigned int id;

	std::cout << "                                Please, enter id:";
	std::cin >> id;

	executeQuery(signInQuery(typeOfPerson, id));

	authentication(id, typeOfPerson);
	
	return id;
}