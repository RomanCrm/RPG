#pragma once

#include "stdafx.h"

class Skill;

class Heroes 
{
public:

	std::string Name; // имя персонажа
	
	int HealthPoint; // текущее хп персонажа
	int HpMax; // макс хп персонажа
	int Mana; // текущая мана персонажа
	int ManaMax; // макс мана персонажа
	int ManaRegen; // регенкрация маны за 1 ход
	int Armor; // текущая броня персонажа
	int ArmorMax; // максимальная броня персонажа
	int Experience; // текущий опыт 
	int ExpMax; // требуемый опыт для след уровня
	int Lvl; // текущий уровень
	int LvlMax; // макс уровень
	int Coins; // монеты

	int Damage; // урон персонажа 

	int NumberBHp; // количество баночек здоровья
	int NumberBMana; // количество баночек маны

	int CountHits; // счетчик для понижения брони от поломки
	double Absorption; // поглощение броней персонажа урона 
	double BreakOut; // пробитие персонажем брони моба
	double VamprizmCoef; // коеф вампиризма

	Heroes();
};