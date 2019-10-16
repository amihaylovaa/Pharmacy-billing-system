#include "sql/connect.hpp"
#include "sql/execute_query.hpp"

void executeQuery(std::string query)
{
	mysql_query(connection, query.c_str());
}