#include <iostream>
#include <string>
#include "create/person utils/add_person.hpp"
#include "create/person utils/create_person.hpp"
#include "create/create_person_type.hpp"
#include "models/pharmacist.hpp"
#include "models/customer.hpp"
#include "sql/queries/person_create_query.hpp"

// Gathers information to create person expecting user input
Person createPerson(PersonType typeOfPerson)
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

	if (typeOfPerson == pharmacist)
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
void addPerson(PersonType typeOfPerson)
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