#pragma once
#include "tetris.h"

typedef struct Shape {
	int x, y, type, rotate;
} shape;

/*
oxoo    oooo    oxoo    ooxo    oxoo    ooxo    oxoo
oxoo    oxxo    oxxo    oxxo    oxoo    ooxo    oxxo
oxoo    oxxo    ooxo    oxoo    oxxo    oxxo    oxoo
oxoo    oooo    oooo    oooo    oooo    oooo    oooo

I       O       S       Z       L       J       T
*/

enum SHAPE { SHAPE_I, SHAPE_O, SHAPE_S, SHAPE_Z, SHAPE_L, SHAPE_J, SHAPE_T };
POINT SHAPE_POINT[][4] = { { { 1,0 },{ 1,1 },{ 1,2 },{ 1,3 } },{ { 1,1 },{ 1,2 },{ 2,1 },{ 2,2 } },
{ { 1,0 },{ 1,1 },{ 2,1 },{ 2,2 } },{ { 2,0 },{ 2,1 },{ 1,1 },{ 1,2 } },
{ { 1,0 },{ 1,1 },{ 1,2 },{ 2,2 } },{ { 2,0 },{ 1,0 },{ 1,1 },{ 1,2 } },
{ { 1,0 },{ 1,1 },{ 1,2 },{ 2,1 } } };

shape newShape(int type);
bool applyMatrix(MATPTR matrix, shape block);
MATPTR shapeToMatrix(shape block);
shape rotate(shape block);
shape rRotate(shape block);