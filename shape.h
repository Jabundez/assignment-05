/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Jose Abundez <Jabundez@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A file for defining a Shape class,
* its child classes, Rectangle and Ellipse
* and its grandchild classes Square and Circle.
*/


#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

class Shape {
public:
	virtual bool contains(const Point & p) const = 0;

	virtual ~Shape() {};
};

class Rectangle : public Shape {
protected:
	double length;
	double height;
	Point p1;

public:
	Rectangle(double length = 1, double height = 2, Point p1 = Point(0, 0));

	virtual ~Rectangle();

	virtual void set_length(double length) { this->length = length; }

	virtual void set_height(double height) { this->height = height; }

	virtual void move_point(Point &p) { p1 = p; }

	virtual bool contains(const Point & p) const;
};

class Square :public Rectangle {

public:
	Square(double side = 1, Point p1 = Point(0, 0));

	~Square();
};

class Ellipse : public Shape {
protected:
	Point f1;
	Point f2;

	double distance;

public:

	Ellipse(double distance = 2, Point f1 = Point(0, 0), Point f = Point(0, 0));

	virtual ~Ellipse();

	virtual void set_distance(double distance) { this->distance = distance; }

	virtual void set_f1(Point & p) { this->f1 = p; }

	virtual void set_f2(Point & p) { this->f2 = p;}

	virtual bool contains(const Point & p) const;
};

class Circle : public Ellipse {
public:
	Circle(double diameter = 2, Point center = Point(0, 0));

	~Circle();

};

#endif
