#pragma once
#include <iostream>
#include <mysql.h>
#include "models/product.hpp"

Product addProduct();
Product getProduct(std::string name);