#pragma once
#include "models/person.hpp"

class Pharmacist : public Person
{
public:
	Pharmacist( std::string, std::string, Address&);
	Pharmacist(const Pharmacist&);

};