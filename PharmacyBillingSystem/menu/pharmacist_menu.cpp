#include "create/person utils/add_person.hpp"
#include "create/product utils/product_utils.hpp"
#include "create/purchase utils/create_bill.hpp"
#include "create/product utils/product_utils.hpp"
#include "create/purchase utils/get_customer_orders.hpp"
#include "create/purchase utils/create_bill.hpp"
#include "menu/sign_in.hpp"
#include "menu/pharmacist_menu.hpp"
#include "validations/menu_validation.hpp"
#include "sql/queries/add_product_query.hpp"
#include "sql/queries/create_purchases_query.hpp"
#include "global/person_type.hpp"

// Represents the options a pharmaicst got
unsigned short pharmacistOption()
{
	unsigned short choice = 0;

	while (!isMenuChoiceValid(choice))
	{
		system("cls");
		std::cout << "                             1.Purchase:" << std::endl;
		std::cout << "                             2.Add new product" << std::endl;
		std::cout << "                             3.Add new customer";
		std::cin >> choice;
	}
	return choice;
}

// Evaluates the choice from the pharmacist menu input 
// and navigates the flow of execution
void pharmacistOptionOutput(unsigned int pharmacistId, unsigned short result)
{
	personType = customer;
	system("cls");

	if (result == 1)
	{
		unsigned int customerId = signIn(personType);
		createPurchases(getCustomerOrders(), pharmacistId, customerId);
	}

	else if (result == 2)
		addProductQuery(addProduct());

	else
		addPerson(personType);
}