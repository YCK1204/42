/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:45:31 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/26 01:51:10 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

double	triangle_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double	area = 0.5 * fabs((double)((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1)));
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	double x1 = a.getX().toDouble(), y1 = a.getY().toDouble();
	double x2 = b.getX().toDouble(), y2 = b.getY().toDouble();
	double x3 = c.getX().toDouble(), y3 = c.getY().toDouble();
	double px = point.getX().toDouble(), py = point.getY().toDouble();

	double	area = triangle_area(x1, y1, x2, y2, x3, y3);
	double	t1 = triangle_area(px, py, x1, y1, x2, y2);
	double	t2 = triangle_area(px, py, x2, y2, x3, y3);
	double	t3 = triangle_area(px, py, x1, y1, x3, y3);
	return (area == t1 + t2 + t3);
}
