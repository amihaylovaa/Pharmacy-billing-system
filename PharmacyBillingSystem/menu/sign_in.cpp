#include <iostream>
#include "menu/sign_in.hpp"
#include "sql/queries/sign_in_query.hpp"
#include "sql/execute_query.hpp"
#include "validations/authentication.hpp"

// Used to sign in an authenticated user
unsigned int signIn(PersonType typeOfPerson)
{
	unsigned int id;

	std::cout << "                                Please, enter id:";
	std::cin >> id;

	executeQuery(signInQuery(typeOfPerson, id));

	authentication(id, typeOfPerson);
	
	return id;
}