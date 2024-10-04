// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Fixed.cpp>>

#include <iostream>
#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(n << this->_bits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	this->setRawBits(std::roundf(n * (1 << this->_bits)));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(copy.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

// set

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

// get

int	Fixed::getRawBits(void) const
{
	return this->_value;
}

// to

float	Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << this->_bits);
}

int	Fixed::toInt(void) const
{
	return this->getRawBits() >> this->_bits;
}

// out

std::ostream	&operator<<(std::ostream &stream, const Fixed &n)
{
	stream << n.toFloat();
	return stream;
}
