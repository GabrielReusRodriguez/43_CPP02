/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:17:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/10/09 00:42:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(1.02f);
	Fixed d(2.05f);
	Fixed e(-1.21f);
	Fixed f(0.7f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << c / d << std::endl;
	std::cout << e / f << std::endl;
	std::cout << c + d << std::endl;
	std::cout << e - f << std::endl;

	return 0;
}