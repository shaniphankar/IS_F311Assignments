#include <iostream>
#include <cmath>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include "Point.h"
#include "Circle.h"
using namespace std;
void test();
void display();
void plotPixel(Point curr);

Circle figure;

void plotPixel(Point curr)
{
	glBegin(GL_POINTS);
		glVertex2i(curr.x,curr.y);
	glEnd();
	glFlush();
}

void test()
{
	Point tempP(2,7);
	Circle tempC(Point{5,8},10);//Ignoring the cases where Circle is initialized without radiu
	cout<<tempP.x<<" "<<tempP.y<<"\n";
	cout<<tempC.r<<" {"<<tempC.mid.x<<","<<tempC.mid.y<<"}\n";
}

void drawCircle()
{
	Point curr=Point{0,figure.r};
	int d=1-figure.r;
	int deltaE=3;
	int deltaSE=-2*figure.r + 5;
	plotPixel(curr);
	plotPixel(Point{curr.x,-curr.y});
	plotPixel(Point{-curr.x,-curr.y});
	plotPixel(Point{-curr.x,curr.y});
	while(curr.y>curr.x)
		{
			if(d<0)
			{
				d+=deltaE;
				deltaE+=2;
				deltaSE+=2;
			}
			else
			{
				d+=deltaSE;
				deltaE+=2;
				deltaSE+=4;
				curr.y-=1;
			}
			curr.x+=1;
			plotPixel(curr);
			plotPixel(Point{curr.x,-curr.y});
			plotPixel(Point{-curr.x,-curr.y});
			plotPixel(Point{-curr.x,curr.y});
			cout<<curr.x<<" "<<curr.y<<"\n";
		}

}
// void display()
// {
// 	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 	Point curr=Point{0,figure.r};
// 	int d=1-figure.r;
// 	int deltaE=3;
// 	int deltaSE=-2*figure.r + 5;
// 	glBegin(GL_POINTS);
// 		glColor3i(0,0,1);
// 		glVertex2i(curr.x,curr.y);
// 		glVertex2i(-curr.x,curr.y);
// 		glVertex2i(-curr.x,-curr.y);
// 		glVertex2i(curr.x,-curr.y);
// 		while(curr.y>curr.x)
// 		{
// 			if(d<0)
// 			{
// 				d+=deltaE;
// 				deltaE+=2;
// 				deltaSE+=2;
// 			}
// 			else
// 			{
// 				d+=deltaSE;
// 				deltaE+=2;
// 				deltaSE+=4;
// 				curr.y-=1;
// 			}
// 			curr.x+=1;
// 			glVertex2i(curr.x,curr.y);
// 			glVertex2i(-curr.x,curr.y);
// 			glVertex2i(-curr.x,-curr.y);
// 			glVertex2i(curr.x,-curr.y);
// 			cout<<curr.x<<" "<<curr.y<<"\n";
// 		}
// 	glEnd();

// 	glFlush();	
// }

void display()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(0.5,0.3,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char** argv)
{
	// test();
	cout<<"Enter radius and midpoint\n";
	// int tempR;
	// Point tempPoint;
	// cin>>tempR>>tempPoint.x>>tempPoint.y;
	cin>>figure.r>>figure.mid.x>>figure.mid.y;
	cout<<figure.r<<figure.mid.x<<figure.mid.y;
	cout<<"\n";
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Here's your circle");
	glutInitWindowSize(1920,1080);
	glutDisplayFunc(display);
	drawCircle();
	glutMainLoop();
	return 0;
}