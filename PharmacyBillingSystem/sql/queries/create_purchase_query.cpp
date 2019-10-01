#include <string>
#include "sql/queries/create_purchases_query.hpp"
#include "sql/execute_query.hpp"

void createPurchasesQuery(std::vector<Purchase>& purchases, unsigned int pharmacistId, unsigned int userId)
{
	for (Purchase purchase : purchases)
	{
		Product product = purchase.getProduct();
		unsigned short quantity = product.getQuantity();
		
		std::string queryMYSQL = "\
          INSERT INTO purchase (product_id, customer_id, pharmacist_id, quantity)\
          SELECT product.id, " + std::to_string(userId) + ", \
          " + std::to_string(pharmacistId) + ", " + std::to_string(quantity) + "\
          FROM product \
          WHERE product.name = '" + product.getName() + "';";

		executeQuery(queryMYSQL);
	}
}