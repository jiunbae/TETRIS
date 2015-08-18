#include "main.h"

#define X 12
#define Y 23
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
				cur2xy(j*2,i);
				printf("■");
				matrix_printed[i][j] = matrix[i][j];
			}
		}
	}

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

	matrix[1][1] = 1;
	matrix[1][2] = 1;
	matrix[1][3] = 1;
	matrix[2][3] = 1;
	print_matrix();
	cur2xy(0,23);
}