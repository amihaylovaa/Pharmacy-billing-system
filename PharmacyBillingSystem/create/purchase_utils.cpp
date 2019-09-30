#include <iostream>
#include <string>
#include  <vector>
#include "create/purchase utils/create_bill.hpp"
#include "create/purchase utils/get_customer_orders.hpp"
#include "create/product utils/product_utils.hpp"
#include "sql/queries/create_purchases_query.hpp"
#include "sql/get_product.hpp"
#include "validations/is_product_available.hpp"

void getCustomerOrders(unsigned int pharmacistId, unsigned int userId)
{
	system("cls");
	std::string productName;
	unsigned short quantity;
	std::vector<Product> products;

	while(1)
	{
		std::cout << "Enter quantity:";
		std::cin >> quantity;
		if (quantity == 0) break;

		std::cout << "Enter product:";
		std::cin >> productName;

		products.push_back(Product(productName, quantity));
	}
	createPurchases(products, pharmacistId, userId);
}

void createPurchases(std::vector<Product>& products, unsigned int pharmacistId, unsigned int userId)
{
	std::vector<Purchase> purchases;
	
	for (Product product : products)
	{
		if (isProductAvailable(product.getName()))
		{
			Product prod(getProduct(product.getName(), product.getQuantity()));

			purchases.push_back(Purchase(prod, prod.getQuantity()));
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