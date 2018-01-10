// RPG.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void Game();

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	system("color 0F"); // устанавливает ярко-белый цвет текста
	Game();
	system("pause");
	return 0;
}

void Game()
{
	Skeleton Skelet;
	Golem Golem;
	Warrior Warrior;
	WarriorSkill SuperArmor;

	Warrior.OutBar("Class Warrior"); // вызывает полосу с параметрами персонажа
	cout << "Игра началась!" << endl;
	cout << "У вас есть способность " << SuperArmor.SkillName << ":" << endl;
	cout << "На " << Warrior.OtkatSkill << " ход(а) увеличивает броню на ";
	cout << Warrior.NumberArmorFromSkill << ".\n\n";
	char Menu;
fight: // метка
	cout << "1.Войти в бой с врагом " << Skelet.Name << "(HEALH: " << Skelet.HealthPoint;
	cout << " ARMOR: " << Skelet.Armor << " +EXP: " << Skelet.ExpFromMob << ")" << endl;
	cout << "2.Войти в бой с врагом " << Golem.Name << "(HEALH: " << Golem.HealthPoint;
	cout << " ARMOR: " << Golem.Armor << " +EXP: " << Golem.ExpFromMob << ")" << endl << endl;
	cout << "Войти в бой с врагом №";
	cin >> Menu;
	if (Menu == '1')
	{
		system("cls");
		Warrior.OutBar("Class Warrior");
		Warrior.Attack(Skelet.Name, Skelet.Damage, Skelet.ExpFromMob, Skelet.HealthPoint, Skelet.Armor);
		Skelet.RandNextLvl1MobsStats();
		Golem.RandNextLvl1MobsStats();
		goto fight; // возвращение по метке
	}
	else if (Menu == '2')
	{
		system("cls");
		Warrior.OutBar("Class Warrior");
		Warrior.Attack(Golem.Name, Golem.Damage, Golem.ExpFromMob, Golem.HealthPoint, Golem.Armor);
		Golem.RandNextLvl2MobsStats();
		Skelet.RandNextLvl2MobsStats();
		goto fight;
	}
	else
	{
		system("cls");
		Warrior.OutBar("Class Warrior");
		goto fight;
	}
}

