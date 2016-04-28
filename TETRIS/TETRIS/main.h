#pragma once
#include "tetris.h"

/**
* eventInitilize()
*	이 함수는 프로그램이 초기화 될 때 딱 한번만 실행됩니다.
*/
void eventInitilize();

/**
* eventGameInit()
*	이 함수는 매 게임마다 게임 시작 전에 실행됩니다.
*/
void eventGameInit();

/**
* eventGameOver()
*	이 함수는 매 게임마다 게임이 끝났을 떄(=죽었을 때) 실행됩니다.
*/
void eventGameOver();

/**
* eventKeyPress(key)
*	이 함수는 게임 중에 키가 입력되었다면 실행됩니다.
*	- 인자: key, 입력된 키가 int 형태로 반환됩니다.
*/
void eventKeyPress(int key);

/**
* eventLoop()
*	이 함수는 게임 중에 매 시간 간격 마다 실행됩니다.
*	이 함수가 호출되는 시간 간격을 조절하려면 timeInterval값을 조절하면 됩니다.
*/
void eventLoop();