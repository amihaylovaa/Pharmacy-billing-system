#include "validations/is_product_available.hpp"
#include "sql/queries/execute_query.hpp"
#include "sql/result.hpp"
#include "sql/connect.hpp"

bool isProductAvailable(std::string productName)
{
	std::string queryMYSQL = "SELECT * \
                              FROM product\
                              WHERE name = '" + productName + "';";

	executeQuery(queryMYSQL);
	result = mysql_store_result(connection);

	if (result->row_count == 0)
		return false;
	return true;
}