#include "stdafx.h"
#include "Menugame.h"

Menugame::Menugame() 
{
	x = 0;
	y = 0;
}

Menugame::~Menugame()
{}

void Menugame::inmap()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			map[i][j] = " ";
		}
	}
}

void Menugame::outmap()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

void Menugame::inchooseclass()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			chooseclass[i][j] = " ";
		}
	}
}

void Menugame::outchooseclass()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			cout << chooseclass[i][j];
		}
		cout << endl;
	}
}

void Menugame::random()
{
	x = rand() % 5 + 12;
	y = rand() % 5 + 12;
}

void Menugame::newgame()
{
	random();
	inmap();
	map[x][y - 1] = ">>";
	map[x][y + 1] = "<<";
	map[x][y] = "NEW GAME";
	map[x + 1][y] = "OPTIONS";
	map[x + 2][y] = "HISTORY";
	map[x + 3][y] = "EXIT";
	outmap();

	while (GetAsyncKeyState(VK_DOWN) == 0 || (GetAsyncKeyState(VK_SPACE) == 0)) // пока не нажмешь кнопку стрелку вниз или пробел будет работать застывание и очищение консоли
	{
		Sleep(100); // застывание консоли
		if (GetAsyncKeyState(VK_DOWN)) // если нажать кнопку стрелку вниз - очищает консоль и переходит на пункт ниже
		{
			system("cls");
			random();
			options();
		}
		if (GetAsyncKeyState(VK_SPACE)) // если нажать пробел - открывает меню с выбором персонажа
		{
			system("cls");
			choosewarrior();
		}
	};

}

void Menugame::options()
{
	inmap();
	map[x + 1][y - 1] = ">>";
	map[x + 1][y + 1] = "<<";
	map[x][y] = "NEW GAME";
	map[x + 1][y] = "OPTIONS";
	map[x + 2][y] = "HISTORY";
	map[x + 3][y] = "EXIT";
	outmap();
	while ((GetAsyncKeyState(VK_UP) == 0) || (GetAsyncKeyState(VK_DOWN) == 0) || (GetAsyncKeyState(VK_SPACE) == 0)) 
	{ // пока не нажмешь кнопку вниз, вверх или пробел будет работать застывание и очищение консоли
		Sleep(100);
		if (GetAsyncKeyState(VK_DOWN)) // если нажать кнопку стрелку вниз - очищает консоль и переходит на пункт ниже
		{
			system("cls");
			random();
			history();
		}
		if (GetAsyncKeyState(VK_UP)) // если нажать кнопку стрелку вверх - очищает консоль и переходит на пункт выше
		{
			system("cls");
			random();
			newgame();
		}
		if (GetAsyncKeyState(VK_SPACE)) // если нажать кнопку пробел - очищает консоль и переходит в меню с вкл/выкл музыки
		{
			system("cls");
			random();
			musicon();
		}
	};
}

void Menugame::history()
{
	inmap();
	map[x + 2][y - 1] = ">>";
	map[x + 2][y + 1] = "<<";
	map[x][y] = "NEW GAME";
	map[x + 1][y] = "OPTIONS";
	map[x + 2][y] = "HISTORY";
	map[x + 3][y] = "EXIT";
	outmap();
	while (GetAsyncKeyState(VK_SPACE) == 0) 
	{ 
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			infoout(); 
		}
	};
}

void Menugame::exit1()
{
	inmap();
	map[x + 3][y - 1] = ">>";
	map[x + 3][y + 1] = "<<";
	map[x][y] = "NEW GAME";
	map[x + 1][y] = "OPTIONS";
	map[x + 2][y] = "HISTORY";
	map[x + 3][y] = "EXIT";
	outmap();
	while (GetAsyncKeyState(VK_UP) == 0 || (GetAsyncKeyState(VK_SPACE) == 0))
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			system("cls");
			random();
			history();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
			exit1();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			exit(0);
		}
	};
}

void Menugame::infoout()
{
	cout << "\n\n\n\n\t\t\t\t\tВоин — один из классических шаблонов RPG. " << endl;
	cout << "\t\t\t\tПрофессиональный боец, лишенный способностей к магии, " << endl;
	cout << "\t\tно компенсирующий это виртуозным владением оружием и незаурядными физическими данными."<<endl;
	cout << "\t\t\t\tТрадиционные черты персонажа воинской направленности: " << endl;
	cout << "\t\t\t\t\t     Хорошее владение оружием." << endl;
	cout << "\t\t\tГерой полагается в первую очередь на него в боевых столкновениях."<<endl;
	cout << "\t\tВысокая выносливость, здоровье или иная системная способность переносить повреждения." << endl;
	cout << "\t\t\t\tОтсутствие явно сверхъестественных способностей," << endl;
	cout << "\t\t\tхотя персонаж может развивать «естественные» умения до выдающихся высот" << endl;
	cout << "\n\n\n\n\t\t\t\t\t PRESS ESCAPE TO RETURN IN MENU" << endl;
	do
	{
		Sleep(100);
	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	system("cls");
	newgame();
}

void Menugame::musicon()
{
	inmap();
	map[x][y - 1] = ">>";
	map[x][y + 1] = "<<";
	map[x][y] = "MUSIC ON";
	map[x + 1][y] = "MUSIC OFF";
	map[x + 2][y] = "BACK TO MENU";
	outmap();
	while (GetAsyncKeyState(VK_DOWN) == 0 || (GetAsyncKeyState(VK_SPACE) == 0))
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			system("cls");
			musicon();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
			random();
			musicoff();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			PlaySound(TEXT("03.wav"), NULL, SND_FILENAME || SND_SYNC); // вкл музыку
		}
	};
}

void Menugame::musicoff()
{
	inmap();
	map[x + 1][y - 1] = ">>";
	map[x + 1][y + 1] = "<<";
	map[x][y] = "MUSIC ON";
	map[x + 1][y] = "MUSIC OFF";
	map[x + 2][y] = "BACK TO MENU";
	outmap();
	while (GetAsyncKeyState(VK_DOWN) == 0 || GetAsyncKeyState(VK_UP) || (GetAsyncKeyState(VK_SPACE) == 0))
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			system("cls");
			random();
			musicon();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
			random();
			backtomenu();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			PlaySound(0, NULL, 0);
		}
	};
}

void Menugame::backtomenu()
{
	x = 5;
	y = 23;
	inmap();
	map[x + 2][y - 1] = ">>";
	map[x + 2][y + 1] = "<<";
	map[x][y] = "MUSIC ON";
	map[x + 1][y] = "MUSIC OFF";
	map[x + 2][y] = "BACK TO MENU";
	outmap();
	while (GetAsyncKeyState(VK_DOWN) == 0 || GetAsyncKeyState(VK_UP) || (GetAsyncKeyState(VK_SPACE) == 0))
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			system("cls");
			random();
			musicoff();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
			backtomenu();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			random();
			newgame();
		}
	};
}

void Menugame::choosewarrior()
{
	x = 10;
	y = 50;
	inchooseclass();
	chooseclass[x][y - 1] = ">>";
	chooseclass[x][y + 1] = "<<";
	chooseclass[x][y] = "CLASS WARRIOR";
	chooseclass[x + 5][y + 1] = "BACK TO MENU";
	outchooseclass();
	do {
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			system("cls");
			choosewarrior();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
			choosemenu();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			system("C:\\ConsoleApplication84\\Debug\\RPG.exe"); // открывает вторую консоль по указаному пути
		}
	} while ((GetAsyncKeyState(VK_SPACE) == 0) || (GetAsyncKeyState(VK_DOWN) == 0) || (GetAsyncKeyState(VK_UP) == 0));
}

void Menugame::choosemenu()
{
	x = 10;
	y = 50;
	inchooseclass();
	chooseclass[x + 5][y - 1] = ">>";
	chooseclass[x + 5][y + 1] = "<<";
	chooseclass[x][y + 1] = "CLASS WARRIOR";
	chooseclass[x + 5][y] = "BACK TO MENU";
	outchooseclass();
	while ((GetAsyncKeyState(VK_SPACE) == 0) || (GetAsyncKeyState(VK_DOWN) == 0) || (GetAsyncKeyState(VK_UP) == 0))
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			system("cls");
			choosewarrior();
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			system("cls");
			choosemenu();
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			newgame();
		}
	};
}

