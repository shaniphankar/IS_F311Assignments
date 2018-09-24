#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "Point.h"
#include "Circle.h"
using namespace std;

void test()
{
	Point tempP(2,7);
	Circle tempC(Point{5,8},10);//Ignoring the cases where Circle is initialized without radiu
	cout<<tempP.x<<" "<<tempP.y<<"\n";
	cout<<tempC.r<<" {"<<tempC.mid.x<<","<<tempC.mid.y<<"}\n";
}
int main(int argc, char** argv)
{
	test();
}