#pragma once
#pragma warning(disable:4996) // _s ����
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
	static void clrscr(); // ȭ���� ����� �޼���
	static void timeflow(int millisecond); // ���ϴ� �ð����� ������Ű�� �޼���
	static int getnum(); // ���� �Է¹޴� �޼���
	static string getstr(); // ���ڿ��� �Է¹޴� �޼���
	static keydata getkey(); // ��� Ű�� �Է¹޴� �޼���
private:
	ehglobal(void) {} // ��ü�� �������� ���ϰ� �ϱ� ���� private���� ���� ����
	~ehglobal(void) {}
};