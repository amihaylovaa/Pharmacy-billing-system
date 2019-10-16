#include <iostream>
#include <string>
#include "create/person utils/add_person.hpp"
#include "create/person utils/person_info_input.hpp"
#include "create/create_person_type.hpp"
#include "models/pharmacist.hpp"
#include "models/customer.hpp"
#include "sql/queries/person_create_query.hpp"

// Gathers information to create person expecting user input
Person personInfoInput(PersonType personType)
{
	std::string firstName = "";
	std::string lastName = "";
	std::string cityName = "";
	std::string streetName = "";
	unsigned short streetNumber = 0;

	std::cout << "                                 Enter first name :"; std::cin >> firstName;
	std::cout << "                                 Enter last name :"; std::cin >> lastName;
	std::cout << "                                 Enter city name :"; std::cin.ignore();
	std::getline(std::cin, cityName);
	std::cout << "                                 Enter street number :";
	std::cin >> streetNumber;
	std::cout << "                                 Enter street name :"; std::cin.ignore();
	std::getline(std::cin, streetName);

	City city(cityName);
	Street street(streetName, streetNumber, city);
	Address address(street);

	if (personType == pharmacist)
	{
		Pharmacist pharmacist(firstName, lastName, address);
		return pharmacist;
	}

	else
	{
		Customer cusomter(firstName, lastName, address);
		return cusomter;
	}
}

// Creates person (customer or pharmacist)
void addPerson(PersonType personType)
{
	Person person(personInfoInput(personType));

	if (personType == pharmacist)
	{
		Pharmacist pharmacist(person.getFirstName(), person.getLastName(), person.getAddress());
		createPersonQuery(pharmacist, personType);
	}

	if (personType == customer)
	{
		Customer customer(person.getFirstName(), person.getLastName(), person.getAddress());
		createPersonQuery(customer, personType);
	}
}