#include <string>
#include "validations/authentication.hpp"
#include "sql/connect.hpp"
#include "menu/sign_in.hpp"
#include "sql/result.hpp"
#include "global/global_counter.hpp"
#include "create/person utils/add_person.hpp"

MYSQL_RES* result;
unsigned int counter = 1;

void authentication(unsigned int id, PersonType typeOfPerson)
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