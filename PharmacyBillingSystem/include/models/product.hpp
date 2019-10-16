#pragma once
#include <iostream>

class Product
{
public:
	Product(std::string, double, unsigned short);
	Product(std::string, double);
	Product(std::string, unsigned short);
	Product();
	Product(const Product&);
	Product& operator=(const Product&);
	std::string getName() const;
	double getPrice() const;
	unsigned short getQuantity() const;
	void setPrice(double);
	void setQuantity(unsigned short);

private:
	void validateProduct(std::string);

private:
	std::string name;
    double price;
	unsigned short quantity;
};