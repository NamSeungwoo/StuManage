#pragma once
#pragma warning(disable:4996) // _s 무시
#include <string>
#include <iostream>
// #include <vector>
#include "EHAlgorithm.h"
#include <conio.h>
#include <Windows.h>
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
using std::string;

enum keydata
{
	NO_DEFINED, F1, F2, F3, F4, F5, F6, F7, ESC
};

class ehglobal
{
public:
	static void clrscr(); // 화면을 지우는 메서드
	static void timeflow(int millisecond); // 원하는 시간동안 지연시키는 메서드
	static int getnum(); // 수를 입력받는 메서드
	static string getstr(); // 문자열을 입력받는 메서드
	static keydata getkey(); // 기능 키를 입력받는 메서드
private:
	ehglobal(void) {} // 개체를 생성하지 못하게 하기 위해 private으로 접근 지정
	~ehglobal(void) {}
};