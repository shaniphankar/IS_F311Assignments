#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
#include "line.h"
using namespace std;

/*
Global variables
int x0, y0, x1, y1;
*/
int x0, y0, x1, y1;

void midPointLineAlgoL()
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = 2*dy - dx;
	int incE = 2*dy;
	int incNE = 2*(dy-dx);
	int x = x0;
	int y = y0;
	plot(x, y);

	while(x<x1){
		if(d<=0){
			d += incE;
			x++;
		}
		else{
			d += incNE;
			x++;
			y++;
		}
		plot(x, y);
	}

}

void midPointLineAlgoG()
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = dy - 2*dx;
	int incE = 2*dy;
	int incNE = 2*(dy-dx);
	int x = x0;
	int y = y0;
	plot(x, y);

	while(y<y1){
		if(d>0){
			d += incE;
			y++;
		}
		else{
			d += incNE;
			x++;
			y++;
		}
		plot(x, y);
	}

}

void myDisplayLine(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	if( (y1-y0)/(x1-x0) >= 1 || (y1-y0)/(x1-x0) <= -1)
		midPointLineAlgoG();
	else
		midPointLineAlgoL();
	glutSwapBuffers ();
}
