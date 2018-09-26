#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int x0, y0, x1, y1;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


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

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	if( (y1-y0)/(x1-x0) >= 1 || (y1-y0)/(x1-x0) <= -1)
		midPointLineAlgoG();
	else
		midPointLineAlgoL();
	glFlush ();
}

int main(int argc, char** argv)
{	
	cout << "Enter the coordinates x0 y0:" << endl;
	cin>> x0;
	cin>> y0;
	cout << "Enter the coordinates x1 y1:" << endl;
	cin>> x1;
	cin>> y1;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}