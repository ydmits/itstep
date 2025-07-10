#include "Point.h"
#include <iostream>
Point::Point(int x, int y): x(x), y(y){}
void Point::showPoint()
{
	std::cout << "(" << x << "," << y << ")\n";
}