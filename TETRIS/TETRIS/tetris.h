#pragma once
//이 전처리 구문은 헤더파일의 중복을 피합니다.

#include <stdio.h>
#include <time.h>

#ifdef _WIN32
//이 전처리 구문은 WINDOWS인 경우 해당됩니다.	
	#include <conio.h>
	#include <Windows.h>

	#ifdef _MSC_VER
	//이 전처리 구문은 Visual Studio Compiler를 체크합니다.
		#pragma warning ( disable : 4996)
		//이 전처리 구문은 Visual Studio에서 C4996에러를 무시하는데 사용됩니다.
		//https://msdn.microsoft.com/ko-kr/library/ttcz0bys.aspx
	#endif
#else
//이 전처리 구문은 WINDOWS가 아닐경우 해당됩니다.
	#error This program developed for windows.
	#include <unistd.h>
#endif

#include "main.h"

//구조를 정의합니다.
typedef int bool;
typedef int BLOCK;
typedef BLOCK** MATRIX;
typedef MATRIX* MATPTR;

//bool에 사용할 false와 true를 정의합니다.
enum BOOLEAN { false, true };

//state에 사용할 INIT, GAME, DEAD를 정의합니다.
enum STATE { INIT, GAME, DEAD };

//이 색상은 TTC 세계표준 테트리스 색상을 나타냅니다.
enum COLOR { NONE = 7, SKYBLUE = 3, BLUE = 11, ORANGE = 4, YELLOW = 14, RED = 12, PUPLE = 13, GREEN = 10 };

//상 좌 우 하를 나타내는 enum
enum KEY { UP = 372, LEFT = 375, RIGHT = 377, DOWN = 380};

enum BLOCK { EMPTY, FULL, SQUARE };

//게임판의 크기를 정합니다.
const static int WIDTH = 10, HEIGHT = 23;

static int state, autoState;

//반복 루프의 시간 간격을 정합니다.
static int timeInterval = 1000;

/**
* setCur()
*	이 함수는 커서의 위치를 설정합니다.
*	- 인자: x, y로 콘솔의 커서를 설정합니다.
*/
void setCur(int x, int y);

/**
* getCur()
*	이 함수는 현재 커서의 위치를 반환합니다.
*	- 반환: 현재 커서를 POINT형식으로 반환합니다.
*/
POINT getCur();

/**
* setColor()
*	현재 콘솔의 색상을 지정합니다.
*	- 인자: color로 색상을 지정합니다.
*/
void setColor(int color);

/**
* render()
*	이 함수는 rend와 matrix 두개의 맵을 받아 화면에 출력합니다.
*	rend는 이미 출력된 맵의 주소를 입력해야 합니다.
*	matrix는 변경된 맵의 주소를 입력합니다.
*	두 개의 맵의 차이가 있다면 그지점으로 커서를 이동하여 바뀐 값을 출력합니다.
*	- 인자: rend: 이미 출력되었던 맵의 주소를 넣어줍니다.
*		   matrix: 이제 출력할 맵의 주소를 넣어줍니다.
*/
void render(MATPTR rend, MATPTR matrix);

/**
* newMatrix()
*	이 함수는 인자로 받은 matrix의 주소를 받아 그 matrix를 HEIGHT와 WIDTH의 크기로 초기화 해줍니다.
*	- 인자: 초기화할 맵의 주소
*/
void newMatrix(MATPTR matrix);

/**
* getMatrix()
*	현재 matrix를 반환합니다.
*	- 반환: 현재 출력할 matrix를 반환합니다.
*/
MATPTR getMatrix();

/**
* setMatrix()
*	변경된 matrix를 출력하고 적용시킵니다.
*	- 인자: 출력할 matrix
*/
void setMatrix(MATPTR matrix);

/**
* printBlock()
*	이 함수는 지정된 Block을 출력합니다.
*	- 인자: value의 값을 갖는 Block을 출력합니다.
*/
void printBlock(int value);

/**
* getKeyInput()
*	문자를 하나 입력받습니다. 입력 버퍼 딜레이가 없습니다.
*	- 반환: 입력된 문자를 반환해 줍니다.
*/
int getKeyInput();