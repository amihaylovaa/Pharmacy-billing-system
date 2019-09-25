#include <string>
#include "add_product.hpp"

Product addProduct()
{
	std::string name;
	unsigned short quantity;
	double price;

	std::cin.ignore();
	std::cout << "Product name:"; std::getline(std::cin, name); 
	std::cout << "Product price:"; std::cin >> price;
	std::cout << "Product quantity:"; std::cin >> quantity;
	
	Product product(name, price, quantity);
	
	return product;
}