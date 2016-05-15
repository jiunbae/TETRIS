#include "tetris.h"

HANDLE handle;
MATRIX map, rendered;

void initilize();

void initilize()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (int i = 0; i < HEIGHT + 2; ++i)
	{
		for (int j = 0; j < WIDTH + 2; ++j)
		{
			if (i == 0 || j == 0 || i == HEIGHT + 1 || j == WIDTH + 1)
				printBlock(FULL);
			else
				map[i - 1][j - 1] ? printBlock(FULL) : printBlock(EMPTY);
		}
		printf("\n");
	}
}

void setCur(int x, int y)
{
	COORD cur = { x, y };
	SetConsoleCursorPosition(handle, cur);
}
POINT getCur()
{
	POINT point = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO scrInfo;
	if (!GetConsoleScreenBufferInfo(handle, &scrInfo))
		return point;
	point.x = scrInfo.dwCursorPosition.X;
	point.y = scrInfo.dwCursorPosition.Y;
	return point;
}
void setColor(int color)
{
	SetConsoleTextAttribute(handle, color);
}

void render(MATPTR rend, MATPTR matrix)
{
	POINT point = getCur();
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			if ((*rend)[i][j] ^ (*matrix)[i][j])
			{
				setCur(j * 2 + 2, i + 1);
				(*rend)[i][j] = (*matrix)[i][j];
				setColor(BLUE);
				(*rend)[i][j] ? printBlock(FULL) : printBlock(EMPTY);
				setColor(NONE);
			}
	setCur(point.x, point.y);
}

void newMatrix(MATPTR matrix, int height, int width)
{
	*matrix = (MATRIX)malloc(sizeof(BLOCK*) * height);
	for (int i = 0; i < height; ++i)
		(*matrix)[i] = (BLOCK*)calloc(sizeof(BLOCK), width);
}
bool delMatrix(MATPTR matrix, int height, int width)
{
	for (int i = 0; i < height; ++i)
		free((*matrix)[i]);
	free((*matrix));
	return true;
}
MATPTR getMatrix()
{
	return &map;
}
void setMatrix(MATPTR matrix)
{
	render(&rendered, matrix);
}

void printBlock(int value)
{
	switch (value)
	{
		case EMPTY:
			printf("  ");
			break;
		case FULL:
			printf("■");
			break;
		default:
			break;
	}
}

int getKeyInput()
{
	int key = getch();
	switch (key)
	{
		case 224:
			return 300 + getch();
		default:
			return key;
	}
}
int main()
{
	char command[128] = { 0 };
	clock_t flag = clock(), flagNow, flagDiff;
	
	srand((unsigned int)time(NULL));

	newMatrix(&map, HEIGHT, WIDTH);
	newMatrix(&rendered, HEIGHT, WIDTH);

	sprintf(command, "mode con:cols=%d lines=%d", 2 * WIDTH + 5, 4+HEIGHT);
	system(command);
	SetConsoleOutputCP(949);

	initilize();
	eventInitilize();

	for (;;)
	{
		do {
			flagNow = clock();
			flagDiff = ((flagNow - flag) * 1000 / CLOCKS_PER_SEC) % 10000;
			if (flagDiff > timeInterval)
			{
				eventLoop();
				flag = flagNow;
			}
		} while (!kbhit());
		eventKeyPress(getKeyInput());

		switch (state)
		{
			case INIT:
				eventGameInit();
				render(&rendered, &map);
				if(autoState)
					state = GAME;
				break;
			case GAME:
				break;
			case DEAD:
				eventGameOver();
				if(autoState)
					state = INIT;
				break;
			default:
				break;
		}
	}

}
