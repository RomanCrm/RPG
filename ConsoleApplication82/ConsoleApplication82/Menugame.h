#pragma once
class Menugame
{
public:
	char* map[25][25];  //массив главного меню игры
	char* chooseclass[30][80]; //массив меню выбора персонажа
	int x, y; // координаты меню
	Menugame(); // задаем начальные параметры координатам
	void outmap(); // вывод главного меню
	void inmap(); // заполнение главного меню пробелами
	void outchooseclass(); // вывод меню выбора персонажа
	void inchooseclass(); // заполнение меню выбора персонажа
	void newgame(); // открывает следующее меню выбора персонажа при нажатии пробела ( >> << указывают в меню на NEW GAME )
	void options(); // открывает меню с опциями ( >> << указывают в меню на OPTIONS )
	void history(); // открывает историю о персонаже ( >> << указывают в меню на HISTORY )
	void exit1(); // выходит из игры ( >> << указывают в меню на EXIT )
	void infoout(); // история о персонаже
	void musicon(); // вкл музыку ( >> << указывают в меню на MUSIC ON )
	void musicoff(); // выкл музыку ( >> << указывают в меню на MUSIC OFF )
	void backtomenu(); // вернуться в главное меню ( >> << указывают в меню на BACK TO MENU )
	void random(); // рандом координат меню
	void choosewarrior(); // открывает новую консоль с игрой ( >> << указывают в меню на CLASS WARRIOR )
	void choosemenu(); // возвращает в главное меню ( >> << указывают в меню на BACK TO MENU )
	~Menugame();
};

