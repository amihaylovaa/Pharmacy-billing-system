#include "exceptions/unavailable_product.hpp"

// Represents constructor implementation of a custom exception 
unavailable_product::unavailable_product(std::string what_arg) : runtime_error(what_arg) { }