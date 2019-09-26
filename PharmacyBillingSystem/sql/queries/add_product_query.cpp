#include <iostream>
#include <string>
#include <mysql.h>
#include "sql/queries/add_product_query.hpp"
#include "sql/queries/execute_query.hpp"
#include "sql/connect.hpp"

void addProductQuery(Product product)
{
	std::string name = product.getName();
	unsigned short quantity = product.getQuantity();
	double price = product.getPrice();

	std::string queryMYSQL = "INSERT INTO product(name, price, quantity)\
                              VALUES('" + name + "'," + std::to_string(price) + ", " +std::to_string(quantity) + ");";

	executeQuery(queryMYSQL);
}