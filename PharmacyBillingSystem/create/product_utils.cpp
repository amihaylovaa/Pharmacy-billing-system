#include <string>
#include "create/product utils/product_utils.hpp"
#include "sql/result.hpp"
#include "sql/connect.hpp"

Product addProduct()
{
	std::string name;
	unsigned short quantity;
	double price;

	std::cin.ignore();
	std::cout << "Product name:"; std::getline(std::cin, name); 
	std::cout << "Product price:"; std::cin >> price;
	std::cout << "Product quantity:"; std::cin >> quantity;
	
	Product product(name, price, quantity);
	
	return product;
}

Product getProduct(std::string name)
{
	MYSQL_ROW row = mysql_fetch_row(result);
	double price = atof(row[2]);
	Product product(name, price);

	return product;
}