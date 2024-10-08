/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/09 00:46:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.number_value);
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << Fixed::number_fractional_bits);
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits(std::ceil(value * (float)(1 << Fixed::number_fractional_bits)));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	//std::cout << "Copy assigment operator called" << std::endl;
	this->setRawBits(copy.number_value);
	return (*this);
}

/* We have to put const because many arhs are Fixed const &*/
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->number_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->number_value = raw;
}

float	Fixed::toFloat(void) const
{
	float val;

	val = (float)(this->getRawBits()) / (float)(1 << Fixed::number_fractional_bits);
	return (val);
}

int		Fixed::toInt(void) const
{
	//std::cout << "toInt member function called" << std::endl;
	return (this->getRawBits() >>  Fixed::number_fractional_bits);
}

std::ostream&	operator<<(std::ostream &str, const Fixed &copy)
{
	return (str << copy.toFloat());
}

bool	operator<(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() < num2.getRawBits());
}

bool	operator>(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() > num2.getRawBits());
}

bool	operator<=(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() <= num2.getRawBits());
}

bool	operator>=(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() >= num2.getRawBits());
}

bool	operator==(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() == num2.getRawBits());
}

bool	operator!=(Fixed const &num1, Fixed const &num2)
{
	return (num1.getRawBits() != num2.getRawBits());
}

Fixed	operator+(Fixed const &num1, Fixed const &num2)
{
	Fixed	result;
	result.setRawBits(num1.getRawBits() + num2.getRawBits());
	return (result);
}

Fixed	operator-(Fixed const &num1, Fixed const &num2)
{
	Fixed result;
	
	result.setRawBits(num1.getRawBits() - num2.getRawBits());
	return (result);
}

Fixed	operator*(Fixed const &num1, Fixed const &num2)
{
	Fixed result((float)(num1.toFloat() * num2.toFloat()));
	return (result);
}

/* The subject says that it is acceptable that the 0 division crashes*/
Fixed		operator/(Fixed const &num1, Fixed const &num2)
{
	Fixed result((float)(num1.toFloat() / num2.toFloat()));
	return (result);
}

/*
	Pre-fix have not args
*/
Fixed&	Fixed::operator++(void)
{
	this->number_value++;
	return (*this);
}

/*
	Postfix have args.
*/
Fixed	Fixed::operator++(int arg)
{
	Fixed result(*this);

	(void)arg;
	this->number_value++;
	return (result);
}

Fixed&	Fixed::operator--(void)
{
	this->number_value--;
	return (*this);	
}

Fixed	Fixed::operator--(int arg)
{
	Fixed	result(*this);

	(void)arg;
	this->number_value--;	
	return (result);
}

Fixed&	Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return ((Fixed&)fixed1);
	else
		return ((Fixed&)fixed2);
}

Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

Fixed&	Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return ((Fixed&)fixed1);
	else
		return ((Fixed&)fixed2);
}
