#pragma once
#include <vector>
#include "models/purchase.hpp"

void createPurchases(std::vector<Product>&, unsigned int, unsigned int);
void createBill(std::vector<Purchase>&, unsigned int, unsigned int);