/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Jose Abundez <Jabundez@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A programs that prints out shapes and move their position along an x and y coordinates.
*/

#include "Point.h"
#include "Shape.h"
#include "Constants.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using std::cout;
using std::vector;


/**
* A function to draw the `Shape*`s in the given vector in a terminal.
*
* Arguments:
* - `v`: A vector containing pointers to each `Shape` to draw.
*
* Notes:
* - A terminal window is typically 80 columns wide by 25 lines high.
* - The width:height aspect ratio of a terminal character is approximately
*   1:1.9.
*/

void draw(const vector<Shape*> & v) {

	/*for (int y = 0; y <= Y; y++)
	{
		for (int x = 1; x <= X; x++)
		{
			if (y == 0 || y == Y)
				cout << "-";
			else if (x == 1 || x == X)
				cout << "|";
			else
				cout << " ";
		}
		cout << std::endl;
	}*/
	

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			bool contains = false;

			for (Shape* e : v)
			{
				if (e->contains(Point(x, y * 1.5)) == true)
				{
					contains = true;
					break;
				}
			}

			if (contains)
				cout << "*";
			else
				cout << " ";
		}
		cout << std::endl;
	}
};

int main() {

	Rectangle r(10,3,Point(4,20));
	Square s(6,Point(6,5));
	Ellipse e(20,Point(40,20),Point(40,10));
	Circle c(15,Point(65,25));
	
	vector<Shape*> shapes = { &r , & s, &e, &c};

	for (int i = 0; i < 25; i++)
	{
		draw(shapes);

		
		r.set_height(11 + i);
		s.move_point(Point(6 + 2 * i, 5 + 1 * i));
		e.set_distance(20 - i / 4);
		c.set_f1(Point(65 - 2 * i, 25 - i / 2));
		c.set_f2(Point(65 - 2 * i, 25 - i / 2));
		

		// wait before drawing the next frame
		//
		// for example:
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		// if you'd like to know more about what this line is doing, look
		// up the documentation for `std::this_thread::sleep_for` and
		// `std::chrono::milliseconds()`.
	}

	system("pause");

	return 0;  // success
}

