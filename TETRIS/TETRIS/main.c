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
*	typedef int BLOCK		: 블럭을 나타냅니다. 0은 빈 블럭, 1이상은 각각 블럭의 색상을 나타냅니다.
*	typedef BLOCK** MATRIX	: BLOCK의 2차원 배열입니다. 이는 하나의 맵을 나타냅니다.
*	typedef MATRIX* MATPTR	: MATRIX의 주소를 나타냅니다.
*
*
* - 미리 정의된 함수
* setCur()
*	이 함수는 커서의 위치를 설정합니다.
*	- 인자: x, y로 콘솔의 커서를 설정합니다.
*
* getCur()
*	이 함수는 현재 커서의 위치를 반환합니다.
*	- 반환: 현재 커서를 POINT형식으로 반환합니다.
*
* setColor()
*	현재 콘솔의 색상을 지정합니다.
*	- 인자: color로 색상을 지정합니다.
*
* render()
*	이 함수는 rend와 matrix 두개의 맵을 받아 화면에 출력합니다.
*	rend는 이미 출력된 맵의 주소를 입력해야 합니다.
*	matrix는 변경된 맵의 주소를 입력합니다.
*	두 개의 맵의 차이가 있다면 그지점으로 커서를 이동하여 바뀐 값을 출력합니다.
*	- 인자: rend: 이미 출력되었던 맵의 주소를 넣어줍니다.
*		   matrix: 이제 출력할 맵의 주소를 넣어줍니다.
*
* newMatrix()
*	이 함수는 인자로 받은 matrix의 주소를 받아 그 matrix를 HEIGHT와 WIDTH의 크기로 초기화 해줍니다.
*	- 인자: 초기화할 맵의 주소
*
* getMatrix()
*	현재 matrix를 반환합니다.
*	- 반환: 현재 출력할 matrix를 반환합니다.
*
* setMatrix()
*	변경된 matrix를 출력하고 적용시킵니다.
*	- 인자: 출력할 matrix
*
* printBlock()
*	이 함수는 지정된 Block을 출력합니다.
*	- 인자: value의 값을 갖는 Block을 출력합니다.
*
* getKeyInput()
*	문자를 하나 입력받습니다. 입력 버퍼 딜레이가 없습니다.
*	- 반환: 입력된 문자를 반환해 줍니다.
*/

void eventInitilize()
{
	autoState = 1;

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