#include <string>
#include  <vector>
#include "purchase.hpp"
#include "create_purchases.hpp"
#include "make_purchase.hpp"
#include "decrement_quantity.hpp"

void getCustomerOrders(unsigned int pharmacistId, unsigned int userId)
{
	system("cls");
	std::string productName;
	unsigned short quantity = 1;
	std::vector<Product> products;

	do 
	{
		std::cout << "Enter quantity:";
		std::cin >> quantity;
		std::cin.ignore();
		std::cout << "Enter product:";
		std::cin >> productName;

		decrementQuantity(productName, quantity);

		Product product(productName, quantity);
		products.push_back(product);
	} while (quantity != 0);

	createPurchases(products, pharmacistId, userId);
}