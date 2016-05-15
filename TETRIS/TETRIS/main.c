#include "main.h"

/**
* README:
* You can complete the tetris, filling code referring to comment.
* tetris.c and tetris.h are pre-implementation code.
* Referring to comment, you can use the function of pre-implementation without seeing the code.
* 
* you should check below
* - README: a comment must read before filling code.
* - TODO: indicates where you need to implement the code.
* - IF: if want to do - to do.
*/

/**
* README:
* - predefined variables
*	WIDTH			
*	HEIGHT			
*	timeInterval	: controlling the loop function.
*	COLOR			: enum of color
*	BLOCK			: enum of block type { EMPTY, FULL, SQUARE }
*	state			: enum of state { INIT, GAME, DEAD }
*	autoState		: if autoState == 1, after call eventGameInit(or Over) state change automatically
*					  (after eventGameOver(), state = INIT)
* 
* - predefined structers
*	typedef int bool		: 0 for flase, 1 for true
*	typedef int BLOCK		: represent block color, 0 is EMPTY block others are FULL block
*	typedef BLOCK** MATRIX	: represent a map with height and width.
*	typedef MATRIX* MATPTR	: pointer of MATRIX
*
* - predefined functions
* setCur()
*	set console cursor
*	- arg: cursor position to set
*
* getCur()
*	return console cursor
*	- return: now cursor point
*
* setColor()
*	set consloe color to color
*
*	- arg: color
* render()
*	render a matrix.
*	get two matrix, just print difference between two matrix
*	- arg: pointer of rended matrix, pointer of matrix to print
*
* newMatrix()
*	create new matrix with height, width
*	- arg: pointer of matrix, height, width
*
* delMatrix()
*	dealloc matrix
*	when after using matrix, must call this function
*	- arg: pointer of matrix to delete, height of matrix, width of matrix
*
* getMatrix()
*	return now matrix(printed matrix just before)
*	- return: now matrix
*
* setMatrix()
*	set matrix and print.
*	- arg: point of matrix to print
*
* printBlock()
*	print block (EMPTY == " ", FULL == "бс")
*	- arg: block
*
* getKeyInput()
*	input a key.
*	- return: inputed key.
*/

void eventInitilize()
{
	/**
	* TODO:
	*	this function called once in before program start.
	*	recommend: write variable initlizing code.
	*/

	/**
	* IF: you want modife the size
	*	int tetris.h : 41 line 
	*	const static int WIDTH = 13, HEIGHT = 23;
	*	you can change the value for resize.
	*/
}
void eventGameInit()
{
	/**
	* TODO:
	*	this function called before game start. (when state == DEAD)
	*	you can change state and something else.
	*/
}
void eventKeyPress(int key)
{
	/**
	* TODO: 
	*	this function called when key pressed.
	*/
}
void eventLoop()
{
	/**
	* TODO: 
	*	this function called every interval
	*	recommend: wrtie loop code like block fall down
	* 
	* IF: want modife the interval
	*	change timeInterval value
	*	unit of timeInterval is (ms), 1(s) == 1000(ms)
	*/
}
void eventGameOver()
{
	/**
	* TODO:
	*	this function called game over (when state == DEAD)
	*/
}