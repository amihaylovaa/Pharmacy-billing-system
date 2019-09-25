#pragma once
#include <iostream>
#include <vector>
#include "product.hpp"
#include "person.hpp"

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