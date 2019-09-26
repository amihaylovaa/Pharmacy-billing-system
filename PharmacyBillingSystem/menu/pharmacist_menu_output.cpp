#include "create/person utils/add_person.hpp"
#include "create/product utils/product_utils.hpp"
#include "create/get_customer_orders.hpp"
#include "menu/sign_in.hpp"
#include "menu/pharmacist_menu_output.hpp"
#include "menu/pharmacist_menu.hpp"
#include "sql/queries/add_product_query.hpp"
#include "global/person_type.hpp"

void pharmacistOptionOutput(unsigned int pharmacistId, unsigned short result)
{
	typePerson = customer;
	system("cls");

	if (result == 1)
	{
		unsigned int userId = signIn(typePerson);
		getCustomerOrders(pharmacistId, userId);
	}

	else if (result == 2)
		addProductQuery(addProduct());

	else
		addPerson(typePerson);
}