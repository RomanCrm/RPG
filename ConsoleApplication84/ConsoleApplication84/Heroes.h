#pragma once

#include "stdafx.h"

class Skill;

class Heroes 
{
public:

	std::string Name; // ��� ���������
	
	int HealthPoint; // ������� �� ���������
	int HpMax; // ���� �� ���������
	int Mana; // ������� ���� ���������
	int ManaMax; // ���� ���� ���������
	int ManaRegen; // ����������� ���� �� 1 ���
	int Armor; // ������� ����� ���������
	int ArmorMax; // ������������ ����� ���������
	int Experience; // ������� ���� 
	int ExpMax; // ��������� ���� ��� ���� ������
	int Lvl; // ������� �������
	int LvlMax; // ���� �������
	int Coins; // ������

	int Damage; // ���� ��������� 

	int NumberBHp; // ���������� ������� ��������
	int NumberBMana; // ���������� ������� ����

	int CountHits; // ������� ��� ��������� ����� �� �������
	double Absorption; // ���������� ������ ��������� ����� 
	double BreakOut; // �������� ���������� ����� ����
	double VamprizmCoef; // ���� ����������

	Heroes();
};