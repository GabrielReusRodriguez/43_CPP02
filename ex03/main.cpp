/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:32:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/31 21:30:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.0f, 5.0f);
	Point	point(-1.0f, 0.0f);
	Point	point2(1.0f, 2.0f);
	
	std::cout << bsp(a, b, c, point) << std::endl;
	std::cout << bsp(a, b, c, point2) << std::endl;
	return (0);
}