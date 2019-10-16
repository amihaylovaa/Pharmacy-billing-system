#include <exceptions/inappropriate_argument.hpp>

// Represents constructor implementation of a custom exception 
inappropriate_argument::inappropriate_argument(std::string what_arg) : invalid_argument(what_arg) { }