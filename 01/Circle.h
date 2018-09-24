#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "Point.h"
class Circle
{
public:
	int r;
	Point mid;
	Circle(Point midIn=Point{0,0},int rIn=0);
};
#endif