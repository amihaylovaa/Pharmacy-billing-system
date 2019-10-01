#pragma once
#include <iostream>
#include <stdexcept>

class inappropriate_argument : public std::invalid_argument
{
public:
	inappropriate_argument(std::string);

private:
	std::string what_arg;
};