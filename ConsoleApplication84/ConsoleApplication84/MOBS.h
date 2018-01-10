#pragma once

#include "stdafx.h"

class MOBS
{
public:
	std::string Name; // имя моба
	int HealthPoint; // здоровье моба
	int Damage; // урон моба
	int Armor; // броня моба
	int ExpFromMob; // опыт, получаемый с моба

	int NextLvlHp; // число хп, добавляемое при смерти пред. моба
	int NextLvlArmor; // число брони, добавляемое при смерти пред. моба
	int NextLvlExp; // число даваемого опыта, добавляемое при смерти пред. моба
	int NextLvlDamage; // число урона, добавляемое при смерти пред. моба

	void RandNextLvl1MobsStats(); // рандом добавления параметров моба при смерти
	void RandNextLvl2MobsStats(); // рандом добавления улучшенных параметров моба при смерти

	MOBS();
};
