#pragma once
#include <iostream>
#include <stdexcept>

class unavailable_product : public std::runtime_error
{
public:
	unavailable_product(std::string);

private:
	std::string what_arg;
};