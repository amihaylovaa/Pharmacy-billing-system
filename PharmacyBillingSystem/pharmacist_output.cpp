#include "pharmacist_option_output.hpp"
#include "add_person.hpp"
#include "add_product.hpp"
#include "sign_in.hpp"
#include "pharmacist_option.hpp"
#include "add_product_query.hpp"
#include  "make_purchase.hpp"
#include "type.hpp"

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