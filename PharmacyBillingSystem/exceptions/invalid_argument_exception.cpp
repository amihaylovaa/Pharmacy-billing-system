#include <exceptions/invalid_argument_exception.hpp>

invalid_argument_exception::invalid_argument_exception(std::string what_arg) : invalid_argument(what_arg) { }