/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Jose Abundez <Jabundez@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A file that defines a class named Point.
*/


#ifndef POINT_H
#define POINT_H

class Point {

public:

	double x;
	double y;

	Point(double x = 0, double y = 0);
	
	~Point();

	double distance(const Point & p) const;

};

#endif
