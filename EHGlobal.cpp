#include "EHGlobal.h"

void ehglobal::clrscr()
{
	system("cls");
}

void ehglobal::timeflow(int millisecond)
{
	Sleep(millisecond);
}

int ehglobal::getnum()
{
	int num;
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	sscanf(buf, "%d", &num);
	return num;
}

string ehglobal::getstr()
{
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	return buf;
}

keydata ehglobal::getkey()
{
	int key = getch();

	if (key == 27)
	{
		return ESC;
	}
	if (key == 0)
	{
		key = getch();
		switch (key)
		{
		case 59:return F1;
		case 60:return F2;
		case 61:return F3;
		case 62:return F4;
		case 63:return F5;
		case 64:return F6;
		case 65:return F7;
		}
	}
	return NO_DEFINED;
}