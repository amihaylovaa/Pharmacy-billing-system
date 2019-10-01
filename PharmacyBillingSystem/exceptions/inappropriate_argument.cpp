#include <exceptions/inappropriate_argument.hpp>

inappropriate_argument::inappropriate_argument(std::string what_arg) : invalid_argument(what_arg) { }