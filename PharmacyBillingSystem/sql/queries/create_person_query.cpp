#include <iostream>
#include <string>
#include "sql/queries/person_create_query.hpp"
#include "sql/execute_query.hpp"
#include "sql/connect.hpp"
#include "global/person_type.hpp"

void createPersonQuery(Person person, PersonType typeOfPerson)
{
	std::string firstName = person.getFirstName();
	std::string lastName = person.getLastName();
	Address address = person.getAddress();
	Street street = address.getStreet();
	City city = street.getCity();
	std::string cityName = city.getName();
	std::string streetName = street.getName();
	unsigned short streetNumber = street.getNumber();

	std::string insertQuery = "INSERT INTO city (name)\
		                       VALUES('" + cityName + "');";

	executeQuery(insertQuery);

	insertQuery = "INSERT INTO street(name, number, city_id)\
		           SELECT '" + streetName + "'," + std::to_string(streetNumber) + ", city.id\
                   FROM city\
                   WHERE city.name = '" + cityName + "';";

	executeQuery(insertQuery);

	insertQuery = "INSERT INTO address(street_id)\
                   SELECT street.id\
                   FROM street\
                   WHERE street.id IN ( \
                   SELECT street.id FROM street, city\
                   WHERE street.name = '" + streetName + "' AND street.number = " + std::to_string(streetNumber) + "\
                   AND city.name = '" + cityName + "');";

	executeQuery(insertQuery);

	insertQuery = "INSERT INTO person (first_name, last_name, address_id)\
                   SELECT '" + firstName + "', '" + lastName + "', address.id \
                   FROM address \
                   WHERE address.street_id IN \
                   ( SELECT street.id from street, address \
                   WHERE street.number = " + std::to_string(streetNumber) + "\
                   AND street.name = '" + streetName + "'\
                   AND street.id = address.street_id);";

	executeQuery(insertQuery);

	if (typeOfPerson == pharmacist)
	{

		insertQuery = "INSERT INTO pharmacist(id)\
                       SELECT person.id\
		               FROM person,address,street\
                       WHERE person.first_name = '" + firstName + "' AND person.last_name = '" + lastName + "' \
                       AND person.address_id = address.id AND street.id = address.street_id; ";
	}

	if (typeOfPerson == customer)
	{
		insertQuery = "INSERT INTO customer(id)\
                       SELECT person.id\
		               FROM person,address,street\
                       WHERE person.first_name = '" + firstName + "' AND person.last_name = '" + lastName + "' \
                       AND person.address_id = address.id AND street.id = address.street_id; ";
	}
	executeQuery(insertQuery);
}