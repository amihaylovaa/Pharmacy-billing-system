#pragma once
#include <iostream>
#include <stdexcept>

class invalid_argument_exception : public std::invalid_argument
{
public:
	invalid_argument_exception(std::string);

private:
	std::string what_arg;
};