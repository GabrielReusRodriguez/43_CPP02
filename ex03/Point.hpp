/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:00:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/30 23:58:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point &copy);
		~Point();

	void	operator=(const Point point);
	Fixed	getX(void);
	Fixed	getY(void);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif