/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/26 22:54:41 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number_value = copy.number_value;
	//this = copy;
}

Fixed::Fixed(const int value)
{
	this->number_value = value;
}

Fixed::Fixed(const float value)
{
	//TODO	
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(Fixed &copy)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->number_value = copy.number_value;
}

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number_value = raw;
}

float		toFloat(void) const
{
	return (1.0f);
}

int			toInt(void) const
{
	return (1);
}

std::string	operator<<(const Fixed &copy); 
{
	return ("");
}
/*
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		void 		operator=(Fixed &copy);
		int			getRawBits(void);
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		std::string	operator<<(Fixed &copy); 
*/