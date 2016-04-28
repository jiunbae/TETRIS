#include "main.h"

/**
* README:
* 여러분은 이 main.c의 주석을 보고 코드를 작성함으로써 Tetris를 완성해 나갈 수 있습니다.
* tetris.c와 tetris.h는 미리 구현되어 있는 코드입니다.
* 주석을 참조하면 미리 구현된 코드를 보지 않고도 구현할 수 있도록 작성되어 있습니다.
* 
* 앞으로 나타날 표시는 대략 아래와 같습니다.
* - README: 표시는 읽어봐야할 주석을 나타냅니다.
* - TODO: 표시는 코드를 구현해야하는 위치를 나타냅니다.
* - IF: 만약 ~하고 싶다면 ~하라는 사항을 나타냅니다.
*/

/**
* README:
* - 미리 정의된 변수
*	WIDTH			: 너비
*	HEIGHT			: 높이
*	BLOCK_EMPTY		: 빈 블럭
*	BLOCK_FULL		: 꽉찬 블럭
*	COLOR			: 색상을 담고있는 enum
*	timeInterval	: 시간 간격
*	state			: 현재 상태를 나타냅니다. { 0: 게임 시작 전, 1: 게임 중, 2: 죽음 }
*	autoState		: 이 값이 1이면 자동으로 사망을 체크합니다. 0이라면 사용자가 직접 state를 조절해야 합니다.
* 
* - 미리 정의된 구조
*	typedef int bool		: 0은 flase, 1은 true를 나타내는 boolean형태의 구조입니다.
*	typedef COORD POINT		: 좌표를 나타낼 수 있도록 x, y를 가지고 있는 구조체입니다.
*	typedef char BLOCK		: 블럭을 나타냅니다. 0은 비어있는 블럭을, 1 이상은 각 색상값에 해당하는 블럭 하나를 나타냅니다.
*	typedef BLOCK** MATRIX	: matrix는 앞으로 테트리스 판을 나타냅니다.
*							  이차원 배열로 구성되어있으며 그것의 주소를 사용하기 위해 삼중 포인터로 구현되어있습니다.
*
* - 미리 정의된 함수
*	MATRIX getMatrix()			: 현재 맵을 matrix형태로 반환해 줍니다.
*   void setMatrix(MATRIX)		: 현재 맵을 인자로 사용한 matrix로 변경합니다.
*	void refresh()				: 화면을 강제로 새로고침합니다.
*
*/
int x = 0, y = 0;
void eventInitilize()
{
	autoState = 1;
	x = 0;
	y = 0;
	/**
	* TODO:
	* 이 함수는 프로그램이 시작될 때 한번만 실행됩니다.
	* 여기에는 초기화할 변수들을 초기화하는 코드를 적으면 좋습니다.
	*/

	/**
	* IF: 게임판의 크기를 변경하고 싶다면
	* tetris.h의 41줄에는 아래와 같이 적혀있습니다.
	* const static int WIDTH = 13, HEIGHT = 23;
	* 이는 const로 선언해 게임 도중에 게임판의 크기가 변경되지 않도록 하기 위함이므로
	* 만약 게임판의 크기를 변경하고 싶다면 13, 23을 바꾸시면됩니다.
	*/
}
void eventGameInit()
{
	/**
	* TODO:
	* 여기에 게임이 실행되기 전에 수행할 행동을 적습니다.
	* state값은 0으로 주어집니다.
	*/
}
void eventKeyPress(int key)
{
	MATRIX * map = getMatrix();
	(*map)[x][y] = BLOCK_EMPTY;
	switch (key)
	{
		case UP:
			--x;
			break;
		case LEFT:
			--y;
			break;
		case RIGHT:
			++y;
			break;
		case DOWN:
			++x;
			break;
		default:
			break;
	};
	(*map)[x][y] = BLOCK_FULL;
	setMatrix(map);
	/**
	* TODO: 
	* 여기에 key가 눌렸을 때 수행할 행동을 적습니다.
	*/
}
void eventLoop()
{
	/**
	* TODO: 
	* 여기에 매 시간간격마다 수행할 행동을 적습니다.
	* keyInterval 변수의 값을 조절함으로 시간간격을 조절할 수 있습니다.
	* keyInterval은 ms단위의 시간을 사용합니다 1(s) = 1000(ms)
	*/
}
void eventGameOver()
{
	/**
	* TODO:
	* 여기에 게임이 끝났을 때 수행할 행동을 적습니다.
	* state값은 2로 주어집니다.
	*/
}