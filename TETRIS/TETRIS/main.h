#pragma once
//이 전처리 구문은 헤더파일의 중복을 피합니다.

#include <stdio.h>
//stdio.h를 사용합니다.
	//이 헤더의 printf함수가 사용되었습니다.

#ifdef WIN32
//이 전처리 구문절은 WINDOWS에서만 실행됩니다.
	#include <Windows.h>

	#include <conio.h>

	#pragma warning ( disable : 4996)
	//이 전처리 구문은 C4996에러를 무시합니다.

#endif
