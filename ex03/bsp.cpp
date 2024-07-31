/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:03:10 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/31 21:23:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

Let the coordinates of the three corners be (x1, y1), (x2, y2), and (x3, y3). And coordinates of the given point P be (x, y)

    Calculate the area of the given triangle, i.e., the area of the triangle ABC in the above diagram. 
    Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
    Calculate the area of the triangle PAB. We can use the same formula for this. Let this area be A1. 
    Calculate the area of the triangle PBC. Let this area be A2. 
    Calculate the area of the triangle PAC. Let this area be A3. 
    If P lies inside the triangle, then A1 + A2 + A3 must be equal to A. 

*/

static Fixed	calculate_area(Point const p1, Point const p2, Point const p3)
{
	Fixed	half(2.0f);
	Fixed	area;

	area = (p1.getX() * (p2.getY() - p3.getY()) + p2.getX()*(p3.getY() - p1.getY()) + p3.getX()*(p1.getY() - p2.getY())) / half;
	return (area);	
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_A;
	Fixed area_PAB;
	Fixed area_PBC;
	Fixed area_PAC;
	
	area_A = calculate_area(a, b, c);
	area_PAB = calculate_area(point, a, b);
	area_PBC = calculate_area(point, b, c);
	area_PAC = calculate_area(point, a, c);
	if (area_A == area_PAB + area_PBC + area_PAC)
		return (true);
	else
		return (false);
}