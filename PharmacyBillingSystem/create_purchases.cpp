#include "create_purchases.hpp"
#include "create_purchases_query.hpp"
#include "is_product_available.hpp"
#include "purchase.hpp"
#include "create_bill.hpp"
#include "get_product.hpp"

void createPurchases(std::vector<Product>& products, unsigned int pharmacistId, unsigned int userId)
{
	std::vector<Purchase> purchases;
	int size = products.size();

	for (Product product : products)
	{
		if(isProductAvailable(product.getName()))
		{
			Purchase purchase(product.getQuantity(), getProduct(product.getName()));
			purchases.push_back(purchase);
		}
	}
	createPurchasesQuery(purchases, pharmacistId, userId);
	createBill(purchases, pharmacistId, userId);
}