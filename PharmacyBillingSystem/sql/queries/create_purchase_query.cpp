#include <string>
#include "sql/queries/create_purchases_query.hpp"
#include "sql/execute_query.hpp"

void createPurchasesQuery(std::vector<Purchase>& purchases, unsigned int pharmacistId, unsigned int userId)
{
	for (unsigned int i = 0; i < purchases.size(); i++)
	{
		Product product = purchases.at(i).getProduct();
		std::string queryMYSQL = "\
          INSERT INTO purchase (product_id, customer_id, pharmacist_id, quantity)\
          SELECT product.id, " + std::to_string(userId) + ", \
          " + std::to_string(pharmacistId) + ", " + std::to_string(purchases.at(i).getQuantity()) + "\
           FROM product \
          WHERE product.name = '" + product.getName() + "';";

		executeQuery(queryMYSQL);
	}
}