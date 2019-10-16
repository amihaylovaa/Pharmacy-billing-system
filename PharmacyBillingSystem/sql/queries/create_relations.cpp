#include <iostream>
#include "sql/connect.hpp"
#include "sql/queries/create_database_relations.hpp"

// Creates all relation of billing_system database
void createRelations()
{
	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS city\
		( id    INT UNSIGNED PRIMARY KEY AUTO_INCREMENT, \
		  name  VARCHAR(32)  NOT NULL UNIQUE\
		);"
	);

	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS street \
		(\
		id      INT UNSIGNED      PRIMARY KEY AUTO_INCREMENT,\
		name    VARCHAR(50)       NOT NULL, \
		number  SMALLINT UNSIGNED NOT NULL,\
		city_id INT UNSIGNED      NOT NULL,\
		FOREIGN KEY(city_id) REFERENCES city(id) ON DELETE CASCADE,\
        UNIQUE (name, number, city_id)\
		);"
	);

	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS address\
		(\
		id        INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,\
		street_id INT UNSIGNED NOT NULL UNIQUE,\
		FOREIGN KEY(street_id) REFERENCES street(id) ON DELETE CASCADE\
		);"
	);

	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS person\
		(\
		id         INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,\
		first_name VARCHAR(32)  NOT NULL,\
		last_name  VARCHAR(64)  NOT NULL,\
		address_id INT UNSIGNED,\
		FOREIGN KEY(address_id) REFERENCES address(id) ON DELETE CASCADE \
		);"
	);

	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS customer\
		(\
		id INT UNSIGNED PRIMARY KEY,\
		FOREIGN KEY(id) REFERENCES person(id) ON DELETE CASCADE \
		);"
	);


	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS pharmacist\
		(\
		id            INT UNSIGNED PRIMARY KEY,\
		FOREIGN KEY(id) REFERENCES person(id) ON DELETE CASCADE\
		);"
	);

	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS product\
		(\
		id        INT UNSIGNED     PRIMARY KEY AUTO_INCREMENT,\
		name      VARCHAR(32)      NOT NULL UNIQUE,\
		price     DOUBLE PRECISION UNSIGNED NOT NULL,\
		quantity  TINYINT UNSIGNED CHECK(quantity>0)\
		);"
	);

	mysql_query(connection,
		"CREATE TABLE IF NOT EXISTS purchase\
		(\
		id            INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,\
		product_id    INT UNSIGNED NOT NULL,\
		customer_id   INT UNSIGNED NOT NULL,\
        pharmacist_id INT UNSIGNED NOT NULL,\
		quantity      SMALLINT UNSIGNED CHECK(quantity >= 1 && quantity <= product.quantity),\
        FOREIGN KEY(customer_id) REFERENCES customer(id) ON DELETE CASCADE ,\
		FOREIGN KEY(pharmacist_id) REFERENCES pharmacist(id) ON DELETE CASCADE ,\
		FOREIGN KEY(product_id) REFERENCES product(id)   ON DELETE CASCADE\
		);"
	);
}