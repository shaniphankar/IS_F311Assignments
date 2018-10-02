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
void testForArgs()
{
	myInit ();
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(4.0);
	midX=0;
	midY=0;
	r=250;
	midPointCircleAlgo(midX,midY,r);
	glPointSize(2.0);
	midPointCircleAlgo(midX,midY,r-10);
	r=250;
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
		r=round(r/4);
		midPointCircleAlgo(midX,midY,r);
		r=tempR;
	}
	vector<vector<pair<int,int>>> bigTriangles (2,triangle);
	angle=90;
	i=0;
	while(angle<360)
	{
		bigTriangles[0][i].first=round((r)*cos(angle*pi/180.0));
		bigTriangles[0][i].second=round((r)*sin(angle*pi/180.0));
		// cout<<bigTriangles[0][i].first<<" "<<bigTriangles[0][i].second<<"\n";		
		i+=1;
		angle+=120;
	}

	angle=30;
	i=0;
	while(angle<360)
	{
		bigTriangles[1][i].first=round((r)*cos(angle*pi/180.0));
		bigTriangles[1][i].second=round((r)*sin(angle*pi/180.0));
		// cout<<bigTriangles[1][i].first<<" "<<bigTriangles[1][i].second<<"\n";		
		i+=1;
		angle+=120;

	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			pntX0=bigTriangles[i][j%3].first;
			pntY0=bigTriangles[i][j%3].second;
			pntX1=bigTriangles[i][(j+1)%3].first;
			pntY1=bigTriangles[i][(j+1)%3].second;
			cout<<pntX0<<" "<<pntY0<<" "<<pntX1<<" "<<pntY1<<"\n";
			if((pntX1-pntX0)==0)
				midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
			else if( (pntY1-pntY0)/(pntX1-pntX0) >= 1 || (pntY1-pntY0)/(pntX1-pntX0) <= -1)
				midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
			else
				midPointLineAlgoL(pntX0,pntY0,pntX1,pntY1);
		}
	}
	vector<vector<pair<int,int>>> rhombi(12,quad);
	angle=0;
	i=0;
	while(angle<360)
	{
		rhombi[i][0].first=0;
		rhombi[i][0].second=0;
		rhombi[i][1].first=round(r/2*(cos(angle*pi/180.0)));
		rhombi[i][1].second=round(r/2*(sin(angle*pi/180.0)));
		rhombi[i][2].first=round(r*(cos((angle+30)*pi/180.0)));
		rhombi[i][2].second=round(r*(sin((angle+30)*pi/180.0)));
		rhombi[i][3].first=round(r/2*(cos((angle+60)*pi/180.0)));
		rhombi[i][3].second=round(r/2*(sin((angle+60)*pi/180.0)));
		angle+=30;
		i+=1;
	}
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<4;j++)
		{
			pntX0=rhombi[i][j%4].first;
			pntY0=rhombi[i][j%4].second;
			pntX1=rhombi[i][(j+1)%4].first;
			pntY1=rhombi[i][(j+1)%4].second;
			cout<<pntX0<<" "<<pntY0<<" "<<pntX1<<" "<<pntY1<<"\n";
			if((pntX1-pntX0)==0)
				midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
			else if( (pntY1-pntY0)/(pntX1-pntX0) >= 1 || (pntY1-pntY0)/(pntX1-pntX0) <= -1)
				midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
			else
				midPointLineAlgoL(pntX0,pntY0,pntX1,pntY1);
		}
	}
	vector<pair<int,int>> perps(6,origin);
	angle=0;
	i=0;
	while(angle<360)
	{
		perps[i].first=round((r/2)*(cos((angle+30)*pi/180.0)));
		perps[i].second=round((r/2)*(sin((angle+30)*pi/180.0)));
		angle+=60;
		i+=1;
	}
	for(int i=0;i<6;i++)
	{
		pntX0=0;
		pntY0=0;
		pntX1=perps[i].first;
		pntY1=perps[i].second;
		if((pntX1-pntX0)==0)
			midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
		else if((pntY1-pntY0)/(pntX1-pntX0) >= 1 || (pntY1-pntY0)/(pntX1-pntX0) <= -1)
				midPointLineAlgoG(pntX0,pntY0,pntX1,pntY1);
		else
			midPointLineAlgoL(pntX0,pntY0,pntX1,pntY1);
	}
	glutSwapBuffers ();
}
// void drawSacredGeom2()
// {
// 	myInit ();
// 	glClear (GL_COLOR_BUFFER_BIT);
// 	glColor3f (0.0, 0.0, 0.0);
// 	glPointSize(2.0);
// 	// Add code here
// 	midX=0;
// 	midY=0;
// 	r=400;
// 	vector<pair<int,int>> circleXY (24,origin);
// 	int i=0,angle=0;
// 	while(angle<360)
// 	{
// 		circleXY[i].first=round((1.1*r/4)*cos(angle * pi/180.0));
// 		circleXY[i].second=round((1.1*r/4)*sin(angle * pi/180.0));
// 		i+=1;
// 		angle+=15;
// 	}
// 	int tempR=r;
// 	for(int i=0;i<24;i++)
// 	{
// 		midX=circleXY[i].first;
// 		midY=circleXY[i].second;
// 		r=round(r/4);
// 		midPointCircleAlgo(pntX0,pntY0,pntX1,pntY1);
// 		r=tempR;
// 	}
// 	glutSwapBuffers ();
// }
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
		glutDisplayFunc(testForArgs);	
		glutMainLoop();	
	}
	else
	{

	}
}