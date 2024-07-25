// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Fixed.cpp>>

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void)
{
	this->setRawBits(0);
}

Fixed::Fixed(const int n)
{
	this->setRawBits(n << this->_bits);
}

Fixed::Fixed(const float n)
{
	this->setRawBits(std::roundf(n * (1 << this->_bits)));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	this->setRawBits(copy.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {}

// ops

int Fixed::operator>(const Fixed &n) const
{
	return this->getRawBits() > n.getRawBits();
}

int Fixed::operator<(const Fixed &n) const
{
	return this->getRawBits() < n.getRawBits();
}

int	Fixed::operator>=(const Fixed &n) const
{
	return this->getRawBits() >= n.getRawBits();
}

int	Fixed::operator<=(const Fixed &n) const
{
	return this->getRawBits() <= n.getRawBits();
}

int	Fixed::operator==(const Fixed &n) const
{
	return this->getRawBits() == n.getRawBits();
}

int	Fixed::operator!=(const Fixed &n) const
{
	return this->getRawBits() != n.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &n) const
{
	Fixed	out;

	out.setRawBits(this->getRawBits() + n.getRawBits());
	return out;
}

Fixed	Fixed::operator-(const Fixed &n) const
{
	Fixed	out;

	out.setRawBits(this->getRawBits() - n.getRawBits());
	return out;
}

Fixed	Fixed::operator*(const Fixed &n) const
{
	Fixed	out(this->toFloat() * n.toFloat());

	return out;
}

Fixed	Fixed::operator/(const Fixed &n) const
{
	Fixed	out(this->toFloat() / n.toFloat());

	return out;
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	out;

	out.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return out;
}

Fixed	Fixed::operator--(int)
{
	Fixed	out;

	out.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return out;
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

// misc

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}
