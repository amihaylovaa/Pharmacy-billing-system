#include "get_product.hpp"
#include "result.hpp"
#include "connect.hpp"

Product getProduct(std::string name)
{
	MYSQL_ROW row = mysql_fetch_row(result);
	double price = atof(row[2]);
	Product product(name, price);

	return product;
}