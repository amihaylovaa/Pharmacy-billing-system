#include <iostream>
#include <string>
#include  <vector>
#include "exceptions/unavailable_product.hpp"
#include "create/purchase utils/create_bill.hpp"
#include "create/purchase utils/get_customer_orders.hpp"
#include "create/product utils/product_utils.hpp"
#include "sql/queries/create_purchases_query.hpp"
#include "sql/get_product.hpp"
#include "validations/is_product_available.hpp"
#include "sql/queries/decrement_quantity.hpp"

// Gets customer orders 
// to form a list of requested products
std::vector<Product> getCustomerOrders()
{
	system("cls");
	std::string productName;
	unsigned short quantity;
	std::vector<Product> products;

	while(1)
	{
		std::cout << "                         Enter quantity:";
		std::cin >> quantity;

		if (quantity == 0) break;

		std::cout << "                        Enter product:";
		std::cin >> productName;

		products.push_back(Product(productName, quantity));
	}
	return products;
}

void createPurchases(std::vector<Product>& products, unsigned int pharmacistId, unsigned int userId)
{
	std::vector<Purchase> purchases;
	
	for (Product product : products)
	{
		std::string name = product.getName();

		if (isProductAvailable(name))
		{
			Product prod = getProduct(name);
			unsigned short availableQuantity = prod.getQuantity();
			unsigned short requestedQuantity = product.getQuantity();
			
			if (availableQuantity < requestedQuantity)
				throw new unavailable_product("Insufficient quantity");

				purchases.push_back(Purchase(prod, requestedQuantity));
				decrementQuantity(name, requestedQuantity);
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