#include <string>
#include "authentication.hpp"
#include "connect.hpp"
#include "sign_in.hpp"
#include "result.hpp"
#include "global_counter.hpp"
#include "add_person.hpp"

MYSQL_RES* result;
unsigned int counter = 1;

void authentication(unsigned int id, personType typeOfPerson)
{
	result = mysql_store_result(connection);

	if (result->row_count == 0)
	{
		std::cout << "                    Person with id " << id << " does not exist!" << std::endl;
		system("cls");
		if (counter == 3)
		{
			addPerson(typeOfPerson);
			counter = 1;
		}
		++counter;
		signIn(typeOfPerson);
	}
	mysql_free_result(result);
}