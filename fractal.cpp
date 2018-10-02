#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <GL/glut.h>
#include "glRoutines.h"
#include "circle.h"
#include "line.h"
#define pi 3.14159265
using namespace std;

extern int midX, midY, r,pntX0, pntY0, pntX1, pntY1;
pair<int,int> origin(0,0);
vector<pair<int,int>> triangle (3,origin);
vector<pair<int,int>> quad (4,origin);

void drawLine()
{
	cout << "Enter the coordinates pntX0 pntY0:" << endl;
	cin>> pntX0;
	cin>> pntY0;
	cout << "Enter the coordinates pntX1 pntY1:" << endl;
	cin>> pntX1;
	cin>> pntY1;
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplayLine);
	myInit ();
	glutMainLoop();
	
}

void drawCircle()
{
	cout << "Enter the coordinates of the center: cx cy" << endl;
	cin >> midX;
	cin >> midY;
	cout << "Enter radius : ";
	cin >> r;
	glutCreateWindow ("Circle Drawing Alogrithms");
	glutDisplayFunc(myDisplayCircle);
	myInit ();
	glutMainLoop();
	
}

void drawFractalSkeleton()
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	// Add code here
	glutSwapBuffers ();
}

void drawCircle1(int x,int y,int radius)
{
	// Accept circle parameters here
	midPointCircleAlgo(x,y,radius);
	if(radius>2)
	{
		drawCircle1(x+radius,y,radius/2);
		drawCircle1(x-radius,y,radius/2);
	}
}

void drawCircle2(int x,int y,int radius)
{
	midPointCircleAlgo(x,y,radius);
	if(radius>16)
	{
		drawCircle2(x+radius,y,radius/2);
		drawCircle2(x-radius,y,radius/2);
		drawCircle2(x,y+radius,radius/2);
		drawCircle2(x,y-radius,radius/2);
	}
}

void drawKoch(int x1,int y1,int x2,int y2,int depth)
{
	if(depth<=0)
	{
		if((x2-x1)==0)
			midPointLineAlgoG(x1,y1,x2,y2);
		else if(((y2-y1)/(x2-x1))>=1 || ((y2-y1)/(x2-x1)) <=-1)
			midPointLineAlgoG(x1,y1,x2,y2);
		else
			midPointLineAlgoL(x1,y1,x2,y2);
	}
	else
	{
		int xb,xc,xd,yb,yc,yd;
		double angle=atan2((y2-y1),(x2-x1));
		double dist=sqrt(pow((y2-y1),2)+pow((x2-x1),2))/3;
		cout<<angle;
		xb=x1+cos(angle)*dist;
		yb=y1+sin(angle)*dist;
		xc=xb+dist*cos(angle+1.0472);
		yc=yb+dist*sin(angle+1.0472);
		xd=2*dist*cos(angle)+x1;
		yd=2*dist*sin(angle)+y1;
		
		
		drawKoch(x1,y1,xb,yb,depth-1);
		drawKoch(xb,yb,xc,yc,depth-1);
		drawKoch(xc,yc,xd,yd,depth-1);
		drawKoch(xd,yd,x2,y2,depth-1);
	}

	
}

void myDisplay(void)
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	// drawCircle1(0,0,150);
	// drawCircle2(0,0,150);
	drawKoch(200,0,0,0,3);
	drawKoch(0,0,0,200,3);
	drawKoch(0,200,200,200,3);
	drawKoch(200,200,200,0,3);
	glutSwapBuffers ();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000,1000);
	glutInitWindowPosition(100,150);
	int option;
	cout<< "Enter which the question number of the assignment you want to choose\n";
	cin>>option;
	//Add functionality to test if option number is correct otherwise retake input
	if(option==1)
		drawLine();
	else if(option==2)
		drawCircle();
	else
	{
		glutCreateWindow ("Fractal");
		glutDisplayFunc(myDisplay);	
		glutMainLoop();	
	}
}