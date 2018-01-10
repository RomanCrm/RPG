#pragma once

#include "stdafx.h"

class MOBS
{
public:
	std::string Name; // ��� ����
	int HealthPoint; // �������� ����
	int Damage; // ���� ����
	int Armor; // ����� ����
	int ExpFromMob; // ����, ���������� � ����

	int NextLvlHp; // ����� ��, ����������� ��� ������ ����. ����
	int NextLvlArmor; // ����� �����, ����������� ��� ������ ����. ����
	int NextLvlExp; // ����� ��������� �����, ����������� ��� ������ ����. ����
	int NextLvlDamage; // ����� �����, ����������� ��� ������ ����. ����

	void RandNextLvl1MobsStats(); // ������ ���������� ���������� ���� ��� ������
	void RandNextLvl2MobsStats(); // ������ ���������� ���������� ���������� ���� ��� ������

	MOBS();
};
