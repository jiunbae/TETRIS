#include "main.h"

enum COLOR { NONE, SKYBLUE, BLUE, ORANGE, YELLOW, RED, PUPLE, GREEN };
//이 색상은 TTC 세계표준 테트리스 색상을 참조했습니다.
//추후에 이 값을 토대로 색상을 적용시킬 것입니다.

char BC[] = { NONE, SKYBLUE, BLUE, ORANGE, YELLOW, RED, PUPLE, GREEN };
//각 블럭의 색상을 미리 정의해둡니다.

#define X 12
#define Y 23

int delay = 1000;
char matrix[X][Y];
char matrix_printed[X][Y];

void cur2xy(int x, int y)
{
	COORD cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}
void print_matrix()
{
	int i, j;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			if (matrix_printed[i][j] - matrix[i][j])
			{
				cur2xy(j * 2, i);
				if (matrix[i][j])
					printf("■");
				else
					printf("□");
				matrix_printed[i][j] = matrix[i][j];
			}
		}
	}
}
void move_matrix()
{
	int i, j;
	for (i = Y - 1; i + 1; i--)
	{
		for (j = X - 1; j + 1; j--)
		{
			if (matrix[i][j])
			{
				matrix[i + 1][j] = matrix[i][j];
				matrix[i][j] = 0;
			}
		}
	}
}
void create_block(char value)
{
	int block_matrix_x[][4] = { { 1, 2, 3, 4 }, { 1, 1, 2, 3 }, { 1, 2, 3, 3 }, { 1, 1, 2, 2 }, { 1, 2, 2, 3 }, { 1, 2, 2, 3 }, { 1, 2, 2, 3 } }
		, block_matrix_y[][4] = { { 2, 2, 2, 2 }, { 1, 2, 2, 2 }, { 2, 2, 2, 1 }, { 1, 2, 1, 2 }, { 1, 1, 2, 2 }, { 2, 1, 2, 2 }, { 2, 2, 1, 1 } }
		, i, j;
	for (i = 0; i < 4; i++)
		matrix[block_matrix_y[value][i]][block_matrix_x[value][i]+3] = 1;
}
void initialize()
{
	int i, j;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			matrix_printed[i][j] = matrix[i][j] = 0;
		}
	}
}
int main()
{
	initialize();
	system("mode con:cols=35 lines=25");
	printf("■■■■■■■■■■■■■■■■■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■□□□□□□□□□□■□□□□■\n");
	printf("■■■■■■■■■■■■■■■■■\n");

	srand(time(NULL));

	create_block(rand() % 6 + 1);
	for (;;)
	{
		Sleep(delay);
		move_matrix();
		print_matrix();
		cur2xy(0, 23);
	}
}