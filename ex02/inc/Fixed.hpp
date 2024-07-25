// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Fixed.hpp>>

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <ostream>

class Fixed
{
	private:

		static const int	_bits;
		int					_value;

	public:

		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed(void);

		int	operator>(const Fixed &n) const;
		int	operator<(const Fixed &n) const;
		int	operator>=(const Fixed &n) const;
		int	operator<=(const Fixed &n) const;
		int	operator==(const Fixed &n) const;
		int	operator!=(const Fixed &n) const;

		Fixed	operator+(const Fixed &n) const;
		Fixed	operator-(const Fixed &n) const;
		Fixed	operator*(const Fixed &n) const;
		Fixed	operator/(const Fixed &n) const;

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		// set
		void	setRawBits(const int raw);

		// get
		int		getRawBits(void) const;

		// to
		float	toFloat(void) const;
		int		toInt(void) const;

		// misc
		static const Fixed	&min(const Fixed &n1, const Fixed &n2);
		static const Fixed	&max(const Fixed &n1, const Fixed &n2);

		static Fixed	&min(Fixed &n1, Fixed &n2);
		static Fixed	&max(Fixed &n1, Fixed &n2);
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &n);

#endif
