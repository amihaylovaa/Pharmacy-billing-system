#include <string>
#include "create/product utils/product_utils.hpp"
#include "sql/result.hpp"
#include "sql/connect.hpp"
#include "sql/execute_query.hpp"
#include "sql/queries/decrement_quantity.hpp"

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

Product getProduct(std::string name, unsigned short requestedQuantity)
{
	MYSQL_ROW row = mysql_fetch_row(result);
	constexpr int price_idx = 2;
	double price = atof(row[price_idx]);
	
	Product product(name, price, getAvailableQuantity(name, requestedQuantity, row));

	return product;
}

unsigned short getAvailableQuantity(std::string productName, unsigned short productQuantity, MYSQL_ROW row)
{
	constexpr int quantity_idx = 3;
	unsigned short availableQuantity = atoi(row[quantity_idx]);

	if (availableQuantity <= productQuantity)
	{
		deleteProduct(productName);
		return availableQuantity;
	}

	else
	{
		decrementQuantity(productName, productQuantity);
		return productQuantity;
	}
}

void deleteProduct(std::string productName)
{
	std::string queryMySQL = "DELETE FROM product\
                              WHERE name = '" + productName + "';";
	executeQuery(queryMySQL);
}