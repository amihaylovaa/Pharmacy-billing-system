#include <string>
#include "sql/queries/sign_in_query.hpp"

std::string signInQuery(personType typeOfPerson, unsigned int id)
{
	std::string query;

	if (typeOfPerson == pharmacist)
	{
		query = "SELECT * FROM person, pharmacist \
                 WHERE person.id = " + std::to_string(id) + "\
                 AND  person.id = pharmacist.id;";
	}

	if (typeOfPerson == customer)
	{
		query = "SELECT * FROM person, customer \
		         WHERE person.id = " + std::to_string(id) + "\
		         AND person.id = customer.id;";
	}
	return query;
}