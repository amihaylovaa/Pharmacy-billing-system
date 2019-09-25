#include <iostream>
#include "sign_in.hpp"
#include "sign_in_query.hpp"
#include "execute_query.hpp"
#include "authentication.hpp"

unsigned int signIn(personType typeOfPerson)
{
	unsigned int id;

	std::cout << "                                Please, enter id:";
	std::cin >> id;

	executeQuery(signInQuery(typeOfPerson, id));

	authentication(id, typeOfPerson);
	
	return id;
}