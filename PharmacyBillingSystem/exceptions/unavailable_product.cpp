#include "exceptions/unavailable_product.hpp"


unavailable_product::unavailable_product(std::string what_arg) : runtime_error(what_arg) { }