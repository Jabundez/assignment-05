/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Jose Abundez <Jabundez@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A file for defining functions in the Point Class.
*/

#include "Point.h"

#include <cmath>

	Point::Point(double x, double y)
		: x(x), y(y)
	{
	}

	Point::~Point() = default;

	double Point::distance(const Point & p) const
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
