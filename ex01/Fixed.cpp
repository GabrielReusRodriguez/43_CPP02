/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/09 00:09:26 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#include "Fixed.hpp"


const int Fixed::number_fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << Fixed::number_fractional_bits);
}

/* We must round up the value because if we do not do, we do not get the entire number.
42.42 => 42.418*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(std::ceil(value * (float)(1 << Fixed::number_fractional_bits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	if (this != &copy)
	{
		std::cout << "Copy assigment operator called" << std::endl;
		this->setRawBits(copy.getRawBits());
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->number_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->number_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)((float)(this->getRawBits()) / (float)(1 << Fixed::number_fractional_bits)));
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::number_fractional_bits);
}

/*The operators are functions que are called with the left param as 1st param
and the  seconds param as the right param
	Fixed a;
	std::cout << a; 
is equals to
	operator<<(std::cout, a);
*/
std::ostream&	operator<<(std::ostream &str, const Fixed &copy)
{
	return (str << copy.toFloat());
}
