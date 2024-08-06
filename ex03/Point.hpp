/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:00:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/08/06 22:08:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/* 
Note We MUST write const to every function that does NOT modify the param /this
because when we compile and we pass a const v var it is a warning  and 
compilation fails.*/
class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point const &copy);
		~Point();

		void	operator=(const Point point);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif