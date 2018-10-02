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

void drawFractal()
{
	int cirPointsArr[11][2]={{-250,0},{-200,0},{-150,0},{-100,0},{-50,0},{0,0},{50,0},{100,0},{150,0},{200,0},{250,0}};
	int cirRadArr[11];
	for(int i=0;i<11;i++)
		cirRadArr[i]=50;
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	for(int i=0;i<11;i++)
	{
		// midX=cirPointsArr[i][0];
		// midY=cirPointsArr[i][1];
		// r=cirRadArr[i];
		// cout<<midX<<" "<<midY<<" "<<r<<"\n";
		midPointCircleAlgo();
		midX=cirPointsArr[i][0]+r;
		midY=cirPointsArr[i][1];
		r=cirRadArr[i]/2;
		midPointCircleAlgo();
		midX=cirPointsArr[i][0]-r;
		midY=cirPointsArr[i][1];
		r=cirRadArr[i]/2;
		midPointCircleAlgo();
		midX=cirPointsArr[i][0];
		midY=cirPointsArr[i][1]+r;
		r=cirRadArr[i]/2;
		midPointCircleAlgo();
		midX=cirPointsArr[i][0];
		midY=cirPointsArr[i][1]-r;
		r=cirRadArr[i]/2;
		midPointCircleAlgo();	
	}
	glutSwapBuffers ();
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
void drawSacredGeom1()
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(4.0);
	midX=0;
	midY=0;
	r=250;
	midPointCircleAlgo();
	glPointSize(2.0);
	r=240;
	midPointCircleAlgo();
	vector<pair<int,int>> circleXY (12,origin);
	int i=0,angle=0;
	while(angle<360)
	{
		circleXY[i].first=round((3*r/4)*cos(angle * pi/180.0));
		circleXY[i].second=round((3*r/4)*sin(angle * pi/180.0));
		i+=1;
		angle+=30;
	}
	int tempR=r;
	for(int i=0;i<12;i++)
	{
		midX=circleXY[i].first;
		midY=circleXY[i].second;
		r=r/4;
		midPointCircleAlgo();
		r=tempR;
	}
	vector<vector<pair<int,int>>> bigTriangles (2,triangle);
	angle=90;
	i=0;
	while(angle<360)
	{
		bigTriangles[0][i].first=round((r)*cos(angle*pi/180.0));
		bigTriangles[0][i].second=round((r)*sin(angle*pi/180.0));
		i+=1;
		angle+=120;
	}
	angle=30;
	i=0;
	while(angle<360)
	{
		bigTriangles[0][i].first=round((r)*cos(angle*pi/180.0));
		bigTriangles[0][i].second=round((r)*sin(angle*pi/180.0));
		i+=1;
		angle+=120;
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
		}
	}


	glutSwapBuffers ();
}
void drawSacredGeom2()
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	// Add code here

	glutSwapBuffers ();
}
void drawSacredGeom3()
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	// Add code here
	glutSwapBuffers ();
}
void drawSacredGeom4()
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(2.0);
	// Add code here
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
	else if(option==3)
		{
			glutCreateWindow ("Fractal");
			glutDisplayFunc(drawFractal);	
			glutMainLoop();	
		}
	else 
	{
		glutCreateWindow ("Fractal");
		glutDisplayFunc(drawSacredGeom1);	
		glutMainLoop();	
	}
}