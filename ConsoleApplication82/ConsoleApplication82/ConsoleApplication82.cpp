// ConsoleApplication82.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void main()
{
	setlocale(LC_ALL, "rus");
	system("color 0F"); // ������ ���� �� ����-�����
	Welcome welcome;
	welcome.Hello();
	Menugame game;
	game.newgame();
	system("pause");
}