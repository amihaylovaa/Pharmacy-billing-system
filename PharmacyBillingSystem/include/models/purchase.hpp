#pragma once
#include <iostream>
#include <vector>
#include "models/product.hpp"
#include "models/person.hpp"

class Purchase
{
public:
	Purchase(unsigned short, Product&);
	Purchase(const Purchase&);
	Purchase();
	unsigned short getQuantity() const;
	Product getProduct() const;

private:
	Product product;
	unsigned short quantity;
};