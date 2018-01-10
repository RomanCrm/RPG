#include "stdafx.h"
#include "Welcome.h"


void Welcome::Hello()
{
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                  [                          " << endl;
	cout << "                                       @XXXXXXXXXX[}:::::::::::::::::::::::::::::::>                                 " << endl;
	cout << "                                                  [                         " << endl;
	cout << "                                                                                                " << endl;
	cout << "                 ___    " << endl;
	cout << "                 \\  \\              _______________________________________________________________" << endl;
	cout << "                  \\  \\            /   /_______/  /      /  ______/  ___   /  ___   ___   /_______/" << endl;
	cout << "                   \\  \\    ____  /   /____   /  /      /  /     /  /  /  /  /  /  /  /  /____   " << endl;
	cout << "                    \\  \\  /    \\/   /____/  /  /      /  /     /  /  /  /  /  /  /  /  /____/" << endl;
	cout << "                     \\  \\/  /\\  \\  /_______/  /______/  /_____/  /__/  /  /  /__/  /  /_______" << endl;
	cout << "                      \\__\\_/  \\__\\/_______/_________/________/________/__/        /__/_______/" << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	Sleep(2000);
	cout << "\t\t\t\t\t\t PRESS SPACE TO CONTINUE" << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	do
	{
		Sleep(100);
	} while (GetAsyncKeyState(VK_SPACE) == 0);  // Ждет нажатия пробела для продолжения
	system("cls");
}

Welcome::Welcome()
{
}

Welcome::~Welcome()
{
}