/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:10:51 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/18 18:52:18 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const	y;
	Fixed		realX;
	Fixed		realY;
public:
	Point();
	~Point() {}
	Point(const float x, const float y);
	Point(const Point &p);
	Point &operator = (const Point &p);
	const Fixed	&getX() const;
	const Fixed	&getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
double	triangle_area(float x1, float y1, float x2, float y2, float x3, float y3);
#endif
