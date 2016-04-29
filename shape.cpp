/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Jose Abundez <Jabundez@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A file for defining functions of the Classes found in "Shape.h"
*/


#include "Shape.h"

//Rectangle Functions

	Rectangle::Rectangle(double length, double height, Point p1	)
		: length(length), height(height), p1(p1)
	{
	}

	Rectangle:: ~Rectangle() = default;

	bool Rectangle::contains(const Point & p) const
	{
		if (p.x >= p1.x && p.x < p1.x + length && p.y >= p1.y && p.y < p1.y + height)
			return true;

		else 
			return false;
	}

//Square Functions

	Square::Square(double side, Point p1)
		: Rectangle(side, side, p1)
	{
	}

	Square::~Square() = default;

//Ellipse Functions

	Ellipse::Ellipse(double distance, Point f1, Point f2)
		:distance(distance), f1(f1), f2(f2)
	{
	}

	Ellipse::~Ellipse() = default;

	bool Ellipse::contains(const Point & p) const
	{
		if (f1.distance(p) + f2.distance(p) <= distance)
			return true;

		else
			return false;
	}

//Circle Functions

	Circle::Circle(double diameter, Point center)
		:Ellipse(diameter,center, center)
	{
	}

	Circle::~Circle() = default;
