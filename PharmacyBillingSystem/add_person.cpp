#include "add_person.hpp"
#include "pharmacist.hpp"
#include "customer.hpp"
#include "create_person.hpp"
#include "person_create_query.hpp"

void addPerson(personType typeOfPerson)
{
	Person person(createPerson(typeOfPerson));

	if (typeOfPerson == pharmacist)
	{
		Pharmacist pharmacist(person.getFirstName(), person.getLastName(), person.getAddress());
		createPersonQuery(pharmacist, typeOfPerson);
	}

	if (typeOfPerson == customer)
	{
		Customer customer(person.getFirstName(), person.getLastName(), person.getAddress());
		createPersonQuery(customer, typeOfPerson);
	}
}