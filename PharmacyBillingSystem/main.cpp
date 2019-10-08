#include <iostream>
#include <mysql.h>
#include "menu/menu.hpp"
#include "menu/menu_output.hpp"
#include "sql/connect.hpp"
#include "sql/queries/create_database_relations.hpp"
#include "sql/result.hpp"
#include "global/global_counter.hpp"
#include "create//create_person_type.hpp"

MYSQL* connection;
MYSQL_RES* result;
PersonType personType;
unsigned int counter = 1;

// This is the main function of the applicatin
int main()
{
	connection = mysql_init(nullptr);

	mysql_real_connect(connection, "localhost", "root", "", "billing_system", 3306, nullptr, 0);

	createRelations();

	menuOutput(menu());

	mysql_close(connection);

	return 0;
}