#pragma once

#include "stdafx.h"
#include "Heroes.h"

class Warrior : public Heroes 
{
public:

	int Vampirizm; // ������� ������� ���� �� ����������
	int ArmorDown; // ����������� �������� ���� ��� ������� ���������� �����
	int VampirizmHits; // ����������� �������� ���� ��� ������� ���������� ���������
	int TmpArmor; // ��������� �����
	int Chance; // ���� ��������� �������

	int OtkatSkill; // ���������� ����� ��� ������� ������ ������������ �����������
	int TmpOtkatSkill; // ��������� ���������� ��� OtktaSkill
	int NumberArmorFromSkill; // ���������� ����� �������� �� ������

	int HpFromBottle; // ���������� �� ������������ �������� ��������
	int ManaFromBottle; // ���������� ���� ������������ �������� ����

	int Evasion; // ���� ������
	int CritHit; // ���� ���� �����
	int CoefDamageFromCritHit; // ���� �� ������� ��������� ���� ��� ���� �����

	void OutBar(std::string name); // ����� ���������� ��������
	void Attack(std::string name,int damagefrommob,int expfrommob,int hpmob,int armormob); // ��� � ������

	Warrior();
};
