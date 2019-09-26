#include <iostream>
#include <string>
#include  <vector>
#include "create/create_bill.hpp"
#include "create/create_purchases.hpp"
#include "create/get_customer_orders.hpp"
#include "create/create_bill.hpp"
#include "sql/queries/decrement_quantity.hpp"
#include "sql/queries/create_purchases_query.hpp"
#include "sql/get_product.hpp"
#include "validations/is_product_available.hpp"

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

void createPurchases(std::vector<Product>& products, unsigned int pharmacistId, unsigned int userId)
{
	std::vector<Purchase> purchases;
	int size = products.size();

	for (Product product : products)
	{
		if (isProductAvailable(product.getName()))
		{
			Purchase purchase(product.getQuantity(), getProduct(product.getName()));
			purchases.push_back(purchase);
		}
	}
	createPurchasesQuery(purchases, pharmacistId, userId);
	createBill(purchases, pharmacistId, userId);
}

void createBill(std::vector<Purchase>& purchases, unsigned int pharmacistId, unsigned int customerId)
{
	double total = 0.00;

	for (Purchase purchase : purchases)
	{
		Product product(purchase.getProduct());

		std::cout << product.getName() << std::endl
			<< purchase.getQuantity() << " x " << product.getPrice() << std::endl;
		total += product.getPrice() * purchase.getQuantity();
	}

	std::cout << "Pharmacist: " << pharmacistId << std::endl;
	std::cout << "Customer: " << customerId << std::endl;
	std::cout << "Total price :" << total << "lv";
}