#include "main.h"

int main()
{
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

	COORD cur = { 1,2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	printf("☆");
	cur.X = 3;
	cur.Y = 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	printf("☆");
}