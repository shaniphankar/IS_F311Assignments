#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
#include "line.h"
using namespace std;

/*
Global variables
int pntX0, pntY0, pntX1, pntY1;
*/
int pntX0, pntY0, pntX1, pntY1;

void midPointLineAlgoL()
{
	int dx = pntX1 - pntX0;
	int dy = pntY1 - pntY0;
	int d = 2*dy - dx;
	int incE = 2*dy;
	int incNE = 2*(dy-dx);
	int x = pntX0;
	int y = pntY0;
	plot(x, y);

	while(x<pntX1){
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
	int dx = pntX1 - pntX0;
	int dy = pntY1 - pntY0;
	int d = dy - 2*dx;
	int incE = 2*dy;
	int incNE = 2*(dy-dx);
	int x = pntX0;
	int y = pntY0;
	plot(x, y);

	while(y<pntY1){
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
	if( (pntY1-pntY0)/(pntX1-pntX0) >= 1 || (pntY1-pntY0)/(pntX1-pntX0) <= -1)
		midPointLineAlgoG();
	else
		midPointLineAlgoL();
	glutSwapBuffers ();
}
