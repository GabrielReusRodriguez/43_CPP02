/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:00:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/30 02:04:39 by greus-ro         ###   ########.fr       */
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
            
        void    operator=(const Point point);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif