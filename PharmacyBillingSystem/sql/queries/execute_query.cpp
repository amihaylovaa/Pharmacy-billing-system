#include "sql/connect.hpp"
#include "sql/queries/execute_query.hpp"

void executeQuery(std::string query)
{
	mysql_query(connection, query.c_str());
}