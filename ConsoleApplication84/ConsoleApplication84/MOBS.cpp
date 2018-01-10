#include "stdafx.h"
#include "MOBS.h"

MOBS::MOBS()
{
	HealthPoint = 0;
	Damage = 0;
	Armor = 0;
	ExpFromMob = 0;
}

void MOBS::RandNextLvl1MobsStats()
{
	NextLvlHp = rand() % 2 + 0; // рандом количества хп, которое прибавит со смертью моба
	NextLvlArmor = rand() % 2 + 0;
	NextLvlDamage = rand() % 2 + 0;
	NextLvlExp = rand() % 2 + 0;
	HealthPoint += NextLvlHp; // к текущему здоровью моба добавляется зарандомленое число
	Damage += NextLvlArmor;
	Armor += NextLvlArmor;
	ExpFromMob += NextLvlExp;
}

void MOBS::RandNextLvl2MobsStats()
{
	NextLvlHp = rand() % 3 + 0;
	NextLvlArmor = rand() % 3 + 0;
	NextLvlDamage = rand() % 3 + 0;
	NextLvlExp = rand() % 3 + 0;
	HealthPoint += NextLvlHp;
	Damage += NextLvlArmor;
	Armor += NextLvlArmor;
	ExpFromMob += NextLvlExp;
}