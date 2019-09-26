#include <string>
#include "sql/queries/decrement_quantity.hpp"
#include "sql/queries/execute_query.hpp"


void decrementQuantity(std::string productName, unsigned short quantity)
{
	std::string queryMYSQL = "UPDATE product \
                              SET quantity = quantity - " + std::to_string(quantity) + "\
                              WHERE name = '" + productName + "';";
	executeQuery(queryMYSQL);
}