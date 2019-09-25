#include "connect.hpp"
#include "execute_query.hpp"

void executeQuery(std::string query)
{
	mysql_query(connection, query.c_str());
}