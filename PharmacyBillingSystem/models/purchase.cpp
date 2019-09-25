#include "purchase.hpp"

Purchase::Purchase(unsigned short quantity_, Product& product_)
	: product(product_)
{
	quantity = quantity_;
}

Purchase::Purchase(const Purchase& purchase)
	: product(purchase.product)
{
	quantity = purchase.quantity;
}

Purchase::Purchase() { }

Product Purchase::getProduct() const { return product; }

unsigned short Purchase::getQuantity() const { return quantity; }