#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <GL/glut.h>
#include "glRoutines.h"
using namespace std;

extern int pntX0, pntY0, pntX1, pntY1;

void midPointLineAlgoL(int,int,int,int);

void midPointLineAlgoG(int,int,int,int);

void myDisplayLine(void);

#endif
