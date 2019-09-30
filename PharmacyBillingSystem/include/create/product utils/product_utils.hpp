#pragma once
#include <iostream>
#include <mysql.h>
#include "models/product.hpp"

Product addProduct();
Product getProduct(std::string name, unsigned short);
unsigned short getAvailableQuantity(std::string, unsigned short, MYSQL_ROW);
void deleteProduct(std::string);