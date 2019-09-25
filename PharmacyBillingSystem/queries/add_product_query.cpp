#include <iostream>
#include <string>
#include <mysql.h>
#include "add_product_query.hpp"
#include "connect.hpp"
#include "execute_query.hpp"

void addProductQuery(Product product)
{
	std::string name = product.getName();
	unsigned short quantity = product.getQuantity();
	double price = product.getPrice();

	std::string queryMYSQL = "INSERT INTO product(name, price, quantity)\
                              VALUES('" + name + "'," + std::to_string(price) + ", " +std::to_string(quantity) + ");";

	executeQuery(queryMYSQL);
}