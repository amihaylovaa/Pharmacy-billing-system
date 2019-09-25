#pragma once
#include <vector>
#include "person.hpp"

class Customer : public Person
{
public:	
	Customer(std::string, std::string, Address&);
	Customer(const Customer&);
	void addItem(std::string);

private:
	std::vector <std::string> items;
};