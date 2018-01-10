#pragma once

#include "stdafx.h"
#include "Heroes.h"

class Warrior : public Heroes 
{
public:

	int Vampirizm; // счетчик каждого хода до вампиризма
	int ArmorDown; // константное значение хода при котором понизиться броня
	int VampirizmHits; // константное значение хода при котором произойдет вампиризм
	int TmpArmor; // временная броня
	int Chance; // шанс выпадания монетки

	int OtkatSkill; // количество ходов при котором нельзя использовать способность
	int TmpOtkatSkill; // временная переменная для OtktaSkill
	int NumberArmorFromSkill; // количество брони даваемой от скилла

	int HpFromBottle; // количество хп пополняемого баночкой здоровья
	int ManaFromBottle; // количество маны пополняемого баночкой маны

	int Evasion; // шанс уклона
	int CritHit; // шанс крит удара
	int CoefDamageFromCritHit; // коеф на который умножится урон при крит ударе

	void OutBar(std::string name); // вывод параметров здоровья
	void Attack(std::string name,int damagefrommob,int expfrommob,int hpmob,int armormob); // бой с мобами

	Warrior();
};
