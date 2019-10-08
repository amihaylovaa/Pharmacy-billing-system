#pragma once
#include <iostream>
#include <stdexcept>

// Represents custom exception that is thrown
// when inappropriate argument is passed
class inappropriate_argument : public std::invalid_argument
{
public:
	inappropriate_argument(std::string);

private:
	std::string what_arg;
};