#pragma once
#include <iostream>
#include <stdexcept>

// Represents custom exception that is thrown
// when a product does not exist
class unavailable_product : public std::runtime_error
{
public:
	unavailable_product(std::string);

private:
	std::string what_arg;
};