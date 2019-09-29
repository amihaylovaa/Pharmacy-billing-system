#include "models/product.hpp"
#include "exceptions/invalid_argument_exception.hpp"

Product::Product(std::string name_, double price_, unsigned short quantity_)
{
	price = price_;
	quantity = quantity_;

	validateProduct(name_);

	name = name_;
}

Product::Product() 
{
	name = nullptr;
	quantity = 0;
	price = 0.00;
}

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

Product::Product(const Product& product)
{
	price = product.price;
	quantity = product.quantity;

	validateProduct(product.name);

	name = product.name;
}

Product& Product::operator=(const Product& product)
{
	price = product.price;;
	quantity = product.quantity;

	validateProduct(product.name);

	name = product.name;

	return *this;
}

std::string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

unsigned short Product::getQuantity() const { return quantity; }

void Product::setPrice(double price_){ price = price_; }

void Product::setQuantity(unsigned short quantity_){ quantity = quantity_; }

void Product::validateProduct(std::string)
{
	if (name.empty())
		throw new invalid_argument_exception("Product name can not be empty");

	if(quantity == 0 || price == 0.00)
		throw new invalid_argument_exception("Product price or quantity can not be zero");
}