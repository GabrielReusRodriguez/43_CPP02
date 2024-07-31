/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:14:48 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/31 21:28:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	The members are const so,  we have tou ser  initializer list to init
	the values of an const member.
*/
Point::Point(void) : x(0.0f), y(0.0f) 
{

}

Point::Point(const float x1, const float y1): x(x1), y(y1) 
{

}

Point::Point(Point const &copy): x(copy.x), y(copy.y)
{

}

Point::~Point()
{
	
}

/* we MUST use the const cast because the members are const.

The const cast ignores the const modificator. It only works
with pointers and references.
*/
void	Point::operator=(const Point point)
{
	const_cast<Fixed&>(x) = point.x;
	const_cast<Fixed&>(y) = point.y;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

/*
		Point(void);
		Point(const float x, const float y);
		Point(Point &copy);
		~Point();

	void	operator=(const Point point);
	Fixed&	getX(void);
	Fixed&	getY(void);

*/