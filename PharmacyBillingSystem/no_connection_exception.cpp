#include <iostream>

class NoConnectionException : public std::exception
{
	NoConnectionException(std::string message);

};

NoConnectionException::NoConnectionException(std::string message)
{  
	puts(message.c_str());
}