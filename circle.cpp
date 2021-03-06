#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
#include "circle.h"
using namespace std;

int midX, midY, r;

void midPointCircleAlgo(int midX,int midY,int r)
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
		plot(midX+(x), midY+(y));
		plot(midX+(x), midY+(-y));
		plot(midX+(-x), midY+(y));
		plot(midX+(-x), midY+(-y));
		plot(midX+(y), midY+(x));
		plot(midX+(-y), midY+(x));
		plot(midX+(y), midY+(-x));
		plot(midX+(-y), midY+(-x));
	}
	cout<<"Plotting Circle"<<" "<<midX<<" "<<midY<<" "<<r<<"\n";
}

void myDisplayCircle(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	midPointCircleAlgo(midX,midY,r);
	glutSwapBuffers ();
}

