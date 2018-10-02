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

void midPointLineAlgoL(int pntX0,int pntY0,int pntX1,int pntY1)
{
	cout<<"Called L algo\n";
	int incx,incy;
	int dx = pntX1 - pntX0;
	int dy = pntY1 - pntY0;
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	if(pntX1>=pntX0)
		incx=1;
	else
		incx=-1;
	if(pntY1>=pntY0)
		incy=1;
	else
		incy=-1;

	int d = 2*dy - dx;
	int incE = 2*dy;
	int incNE = 2*(dy-dx);
	int x = pntX0;
	int y = pntY0;
	plot(x, y);

	for(int i=0;i<dx;i++){
		if(d<0){
			d += incE;
			x+=incx;
		}
		else{
			d += incNE;
			x+=incx;
			y+=incy;
		}
		plot(x, y);
	}

}

void midPointLineAlgoG(int pntX0,int pntY0,int pntX1,int pntY1)
{
	int incx,incy;
	cout<<"Called G algo\n";
	int dx = pntX1 - pntX0;
	int dy = pntY1 - pntY0;
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	if(pntX1>=pntX0)
		incx=1;
	else
		incx=-1;
	if(pntY1>=pntY0)
		incy=1;
	else
		incy=-1;
	int d = 2*dx-dy;
	int incE = 2*dx;
	int incNE = 2*(dx-dy);
	int x = pntX0;
	int y = pntY0;
	plot(x, y);

	for(int i=0;i<dy;i++){
		if(d<0){
			d += incE;
			y+=incy;;
		}
		else{
			d += incNE;
			x+=incx;
			y+=incy;
		}
		plot(x, y);
	}

}

void myDisplayLine(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	if((pntY1-pntY0)/(pntX1-pntX0) >= 1 || (pntY1-pntY0)/(pntX1-pntX0) <= -1)
		midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
	else
		midPointLineAlgoL(pntX0,pntY0,pntX1,pntY1);
	glutSwapBuffers ();
}
