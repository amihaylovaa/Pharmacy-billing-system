#include <iostream>
#include <mysql.h>
#include "menu.hpp"
#include "welcome.hpp"
#include "connect.hpp"
#include "create_database_relations.hpp"
#include "menu_output.hpp"

MYSQL* connection;

int main()
{
	connection = mysql_init(nullptr);

	mysql_real_connect(connection, "localhost", "root", "", "billing_system", 3306, NULL, 0);
	createRelations();

	//welcome();

	menuOutput(menu());

	mysql_close(connection);

	system("pause");
	return 0;
}