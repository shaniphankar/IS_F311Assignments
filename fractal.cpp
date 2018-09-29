#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
#include "circle.h"
#include "line.h"
using namespace std;

extern int pntX1, pntY1, r,x0, y0, x1, y1;

void drawLine()
{
	cout << "Enter the coordinates x0 y0:" << endl;
	cin>> x0;
	cin>> y0;
	cout << "Enter the coordinates x1 y1:" << endl;
	cin>> x1;
	cin>> y1;
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplayLine);
	myInit ();
	glutMainLoop();
	
}

void drawCircle()
{
	cout << "Enter the coordinates of the center: cx cy" << endl;
	cin >> pntX1;
	cin >> pntY1;
	cout << "Enter radius : ";
	cin >> r;
	glutCreateWindow ("Circle Drawing Alogrithms");
	glutDisplayFunc(myDisplayCircle);
	myInit ();
	glutMainLoop();
	
}

void drawFractal()
{
	glutCreateWindow ("Fractal");
	int cirPointsArr[11][2]={{-250,0},{-200,0},{-150,0},{-100,0},{-50,0},{0,0},{50,0},{100,0},{150,0},{200,0},{250,0}};
	int cirRadArr[11];
	for(int i=0;i<11;i++)
		cirRadArr[i]=50;
	glutDisplayFunc(myDisplayCircle);
	myInit ();
	for(int i=0;i<11;i++)
	{
		pntX1=cirPointsArr[i][0];
		pntY1=cirPointsArr[i][1];
		r=cirRadArr[i];
		glutMainLoop();	
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1280,960);
	glutInitWindowPosition(100,150);
	int option;
	cout<< "Enter which the question number of the assignment you want to choose\n";
	cin>>option;
	if(option==1)
		drawLine();
	else if(option==2)
		drawCircle();
	else if(option==3)
		drawFractal();
	//Add functionality to test if option number is correct otherwise retake input
	
	

}