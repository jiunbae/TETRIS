#pragma once
#include "tetris.h"

/**
* eventInitilize()
*	when program initlize, once in program.
*/
void eventInitilize();

/**
* eventGameInit()
*	when game initlize, before game start.
*/
void eventGameInit();

/**
* eventGameOver()
*	when game over.
*/
void eventGameOver();

/**
* eventKeyPress(key)
*	when key pressed
*	- arg: key(inputed key)
*/
void eventKeyPress(int key);

/**
* eventLoop()
*	loop in game, each timeInterval
*/
void eventLoop();