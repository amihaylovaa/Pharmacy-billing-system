#include <iostream>
#include <string>
#include "create_person.hpp"
#include "pharmacist.hpp"
#include "customer.hpp"

Person createPerson(personType typeOfPerson)
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

	if (typeOfPerson == customer)
	{
		Customer cusomter(firstName, lastName, address);
		return cusomter;
	}
}