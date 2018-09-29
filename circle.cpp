#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
#include "circle.h"
using namespace std;

/*
Global variables 
int pntX1, pntY1, r;
*/

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

int main(int argc, char** argv)
{	
	cout << "Enter the coordinates of the center: cx cy" << endl;
	cin >> pntX1;
	cin >> pntY1;
	cout << "Enter radius : ";
	cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1280,960);
	glutInitWindowPosition(100,150);
	glutCreateWindow ("Circle Drawing Alogrithms");
	glutDisplayFunc(myDisplayCircle);
	myInit ();
	glutMainLoop();
	return 0;
}