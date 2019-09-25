#include <string>
#include "decrement_quantity.hpp"
#include "execute_query.hpp"


void decrementQuantity(std::string productName, unsigned short quantity)
{
	std::string queryMYSQL = "UPDATE product \
                              SET quantity = quantity - " + std::to_string(quantity) + "\
                              WHERE name = '" + productName + "';";
	executeQuery(queryMYSQL);
}