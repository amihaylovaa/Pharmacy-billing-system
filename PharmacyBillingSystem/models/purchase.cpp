#include "models/purchase.hpp"

Purchase::Purchase(Product& product_, unsigned short quantity_)
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