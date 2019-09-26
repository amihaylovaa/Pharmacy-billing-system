#include "models/product.hpp"

Product::Product(std::string name_, double price_, unsigned short quantity_)
: name(name_)
{
	price = price_;
	quantity = quantity_;
}

Product::Product() { }

Product::Product(std::string name_, double price_) : name(name_)
{
	price = price_;
	quantity = 0;
}

Product::Product(std::string name_, unsigned short quantity_) : name(name_)
{
	quantity = quantity_;
	price = 0;
}

Product::Product(const Product& product) : name(product.name)
{
	price = product.price;
	quantity = product.quantity;
}

Product& Product::operator=(const Product& product)
{
	name = product.name;
	price = product.price;;
	quantity = product.quantity;

	return *this;
}

std::string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

unsigned short Product::getQuantity() const { return quantity; }

void Product::setPrice(double price_){ price = price_; }

void Product::setQuantity(unsigned short quantity_){ quantity = quantity_; }

void Product::validateName(std::string)
{
	if (name.empty())
		throw new std::invalid_argument("The name is not allowed to be null");
}