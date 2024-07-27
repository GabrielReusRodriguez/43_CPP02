/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/27 19:57:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Fixed.hpp"

const int Fixed::number_fractional_bits = 8;


static float	ft_pow( int base, int exp)
{
	float	acum;
	int		i;
	
	acum = 1;
	if (exp == 0)
		return (1);
	if (exp > 0)
	{
		i = 0;
		while (i <= exp)
		{
			acum = acum * (float) base;
			i++;
		}
		return (acum);
	}
	else
	{
		i = 0;
		while (i >= exp)
		{
			acum = acum / (float)base;
			i--;
		}
		return (acum);
	}
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number_value = copy.number_value;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->number_value = value * ft_pow(2,Fixed::number_fractional_bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->number_value = value * ft_pow(2, Fixed::number_fractional_bits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->number_value = copy.number_value;
	return (*this);
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

float	Fixed::toFloat(void) const
{
	return ((float)this->number_value * ft_pow(2, -Fixed::number_fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->number_value * ft_pow(2, -Fixed::number_fractional_bits));
}

std::ostream&	operator<<(std::ostream &str, const Fixed &copy)
{
	return (str << copy.toFloat());
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