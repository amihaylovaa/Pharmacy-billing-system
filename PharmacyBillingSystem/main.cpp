#include <iostream>
#include <mysql.h>
#include "menu/menu.hpp"
#include "menu/menu_output.hpp"
#include "sql/connect.hpp"
#include "sql/queries/create_database_relations.hpp"

MYSQL* connection;

int main()
{
	connection = mysql_init(nullptr);

	mysql_real_connect(connection, "localhost", "root", "", "billing_system", 3306, NULL, 0);
	createRelations();

	menuOutput(menu());

	mysql_close(connection);

	system("pause");
	return 0;
}