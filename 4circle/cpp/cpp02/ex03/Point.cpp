/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:15:33 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/18 19:45:49 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)), realX(0), realY(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y), realX(x), realY(y)
{
}

Point::Point(const Point &p) : x(p.x), y(p.y), realX(x), realY(y)
{
}

Point &Point::operator = (const Point &p)
{
	this->realX = p.x;
	this->realY = p.y;
	return (*this);
}

const Fixed	&Point::getX() const
{
	return (this->realX);
}

const Fixed	&Point::getY() const
{
	return (this->realY);
}
