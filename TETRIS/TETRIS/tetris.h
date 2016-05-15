#pragma once
//Avoid duplication header

#include <stdio.h>
#include <time.h>

#ifdef _WIN32
//if windows
	#include <conio.h>
	#include <Windows.h>

	#ifdef _MSC_VER
	//if using visualstudio
		#pragma warning ( disable : 4996)
		//skip C4996 error
		//https://msdn.microsoft.com/ko-kr/library/ttcz0bys.aspx
	#endif
#else
//if not windows
	#error This program developed for windows.
	#include <unistd.h>
#endif

#include "main.h"

// define type
typedef int bool;
typedef int BLOCK;
typedef BLOCK** MATRIX;
typedef MATRIX* MATPTR;

// define BOOLEAN, C has no BOOLEAN structer.
enum BOOLEAN { false, true };

// the game stat, init, game, dead.
enum STATE { INIT, GAME, DEAD };

// color for blocks (console color)
enum COLOR { NONE = 7, SKYBLUE = 3, BLUE = 11, ORANGE = 4, YELLOW = 14, RED = 12, PUPLE = 13, GREEN = 10 };

// keybinding
enum KEY { UP = 372, LEFT = 375, RIGHT = 377, DOWN = 380};

enum BLOCK { EMPTY, FULL, SQUARE };

// set size
const static int WIDTH = 10, HEIGHT = 23;

static int state, autoState;

// set time interval of loop
static int timeInterval = 1000;

/**
* setCur()
*	set console cursor
*	- arg: cursor position to set
*/
void setCur(int x, int y);

/**
* getCur()
*	return console cursor
*	- return: now cursor point
*/
POINT getCur();

/**
* setColor()
*	set consloe color to color
*	- arg: color
*/
void setColor(int color);

/**
* render()
*	render a matrix.
*	get two matrix, just print difference between two matrix
*	- arg: pointer of rended matrix, pointer of matrix to print
*/
void render(MATPTR rend, MATPTR matrix);

/**
* newMatrix()
*	create new matrix with height, width
*	- arg: pointer of matrix, height, width
*/
void newMatrix(MATPTR matrix, int height, int width);

/**
* delMatrix()
*	dealloc matrix
*	when after using matrix, must call this function
*	- arg: pointer of matrix to delete, height of matrix, width of matrix
*/
bool delMatrix(MATPTR matrix, int height, int width);

/**
* getMatrix()
*	return now matrix(printed matrix just before)
*	- return: now matrix
*/
MATPTR getMatrix();

/**
* setMatrix()
*	set matrix and print.
*	- arg: point of matrix to print
*/
void setMatrix(MATPTR matrix);

/**
* printBlock()
*	print block (EMPTY == " ", FULL == "■")
*	- arg: block
*/
void printBlock(int value);

/**
* getKeyInput()
*	input a key.
*	- return: inputed key.
*/
int getKeyInput();