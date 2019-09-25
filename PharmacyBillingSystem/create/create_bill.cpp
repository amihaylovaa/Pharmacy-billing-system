#include "create_bill.hpp"

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