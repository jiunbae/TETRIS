#pragma once

#include <stdio.h>

#ifdef WIN32
//이 전처리 구문절은 WINDOWS에서만 실행됩니다.

#include <conio.h>

#pragma warning ( disable : 4996)
//이 전처리 구문은 C4996에러를 무시합니다.

#endif
