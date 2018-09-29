#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
#include "circle.h"
using namespace std;

/*
Global variables 
int pntX1, pntY1, r;
*/
int pntX1, pntY1, r;

void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	int d= 1-r;
	int deltaE = 3;
	int deltaSE = -2*r + 5;
	plot(x, y);

	while (y > x)
	{
		if (d < 0){
			d += deltaE;
			deltaE += 2;
			deltaSE += 2; 
		}
		else{
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		plot(pntX1+(x), pntY1+(y));
		plot(pntX1+(x), pntY1+(-y));
		plot(pntX1+(-x), pntY1+(y));
		plot(pntX1+(-x), pntY1+(-y));
		plot(pntX1+(y), pntY1+(x));
		plot(pntX1+(-y), pntY1+(x));
		plot(pntX1+(y), pntY1+(-x));
		plot(pntX1+(-y), pntY1+(-x));
	}

}

void myDisplayCircle(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	midPointCircleAlgo();
	glutSwapBuffers ();
}

