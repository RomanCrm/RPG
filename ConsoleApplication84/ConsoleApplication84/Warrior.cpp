#include "stdafx.h"
#include "Warrior.h"

Warrior::Warrior()
{
	Name = "Class Warrior";
	HealthPoint = 150;
	HpMax = 150;
	Mana = 50;
	ManaMax = 50;
	ManaRegen = 2;
	Armor = 8;
	TmpArmor = 8;
	ArmorMax = 8;
	Coins = 0;

	Damage = 7;

	Experience = 0;
	ExpMax = 100;
	Lvl = 1;
	LvlMax = 20;

	Vampirizm = 0;
	CountHits = 0;
	Chance = 0;

	OtkatSkill = 3;
	TmpOtkatSkill = 3;
	NumberArmorFromSkill = 2;

	NumberBHp = 4;
	NumberBMana = 2;
	HpFromBottle = 50;
	ManaFromBottle = 20;

	Absorption = 0.3; 
	BreakOut = 0.2; 
	VamprizmCoef = 0.5;
	ArmorDown = 10;
	VampirizmHits = 5;

	Evasion = 0;
	CritHit = 0;
	CoefDamageFromCritHit = 2.25;
}

void Warrior::OutBar(string name)
{
	cout << name << " | " << "HEALTH: " << HealthPoint << "/" << HpMax << " ARMOR: " << Armor << "/" << ArmorMax << " MANA: " << Mana << "/" << ManaMax << " LVL: " << Lvl << "/" << LvlMax << " EXP: " << Experience << "/" << ExpMax << " | COINS: " << Coins << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
}

void Warrior::Attack(std::string name, int damagefrommob, int expfrommob, int hpmob, int armormob)
{
	WarriorSkill SuperArmor;
	char Menu; // ����
	int DamageFromMob; // ���� �� ���� � �������� ����������� �����
	int TmpDamage; // ���� ��������� � �������� �������� �����
attack1: // �����
	system("cls");
	OutBar("Class Warrior");
	cout << "1.������� ����� " << name << " ������� ������" << endl;
	cout << "2.������������ �����������: " << SuperArmor.SkillName << " (�������� " << OtkatSkill << " ���(�) �� ��������������,��������� " << SuperArmor.ManaCost << " ����)" << endl;
	cout << "3.������ ������� ��������(" << NumberBHp << ")" << endl;
	cout << "4.������ ������� ����(" << NumberBMana << ")" << endl;
	cout << "5.�������" << endl;
	cout << "�������: ";
	cin >> Menu;
	if (Menu == '1')
	{
		Evasion = rand() % 8;
		CritHit = rand() % 8;
		CountHits++;
		Vampirizm++; 
		Mana = Mana + ManaRegen; // ��������� ���� �� ���������� ���� ManaRegen

		if (Mana > ManaMax)
		{
			Mana = ManaMax; // ������������� ������ ��� ��������� ���� �� ManaMax
		}
		if (CountHits == ArmorDown) // ������� ����� �� 1,���� �������� ��������� ������ = �������� ���������� ��� �������
		{
			Armor--;
			TmpArmor--;
			CountHits = 0;
		}
		if (Armor < 0) // ���� ����� �� ����� ������������� ������
		{
			Armor = 0;
		}
		if (TmpArmor < 0) // ���� ��������� ���������� ����� �� ����� ������������ ������
		{
			TmpArmor = 0;
		}

		DamageFromMob = damagefrommob - Armor*Absorption; // ���� �� ���� = ��������� ���� ���� - �����*���� ���������� �����
		HealthPoint = HealthPoint - DamageFromMob; // �� = �� - ��������� ���� ����
		TmpDamage = Damage - armormob*BreakOut; // ���� ��������� = ���� ������� - ����� ����*�������� �����
		if (Evasion == 2) // ���� ������������� ����� ������ = 2, �� ������
		{
			TmpDamage = 0;
			Vampirizm--;
		}
		if (CritHit == 3) // ���� ������������� ����� ���� ����� = 3, �� ���� ����
		{
			TmpDamage = TmpDamage*CoefDamageFromCritHit; // ���� ���������*���� ���� �����
		}
		hpmob = hpmob - TmpDamage; // �� ���� = ������� �� ���� - ��������� ����

		if (Vampirizm == VampirizmHits) // ���� ������� ���������� �� ������ ��������� ���� = �������� ���������� ��� ����������
		{
			HealthPoint += TmpDamage*VamprizmCoef; // �� = ���������� ����*���� ����������
			Vampirizm = 0;
		}
		if (HealthPoint > HpMax) // ���� ������� �������� �� ����� ������ �������������
		{
			HealthPoint = HpMax; 
		}
		if (HealthPoint <= 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t��� �����!!!" << endl;
			Sleep(5000);
			exit(0); // ����� �� ����
		}
		if (hpmob > 0) 
		{
			system("cls");
			OutBar("Class Warrior");

			if (OtkatSkill > 0)
			{
				OtkatSkill--; // ������� �� ����, ��� ����� ������������ �����
			}
			if (OtkatSkill == 0)
			{
				if (TmpArmor < Armor) // ���� ����� ��� ������� ���������� �������� ����� �� ���������
				{
					Armor = TmpArmor;
					ArmorMax -= NumberArmorFromSkill;
				}
				else // � ������ ������ ���������� ������� �����
				{
					Armor = TmpArmor;  
				}
			}
			if (DamageFromMob < 0) // ���� ���� �� ���� �������������
			{
				DamageFromMob = 0;
			}
			if (Evasion == 2) 
			{
				cout << "\n�� ������������" << endl;
			}
			else
			{
				if (CritHit == 3)
				{
					cout << "\n����������� ����" << endl;
					cout << "�� ������� ����� " << name << " �� " << TmpDamage << " ����(�)" << endl;
				}
				else cout << "\n�� ������� ����� " << name << " �� " << TmpDamage << " ����(�)" << endl;
			}
			cout << name << " (" << "HEALTH: " << hpmob << " ARMOR: " << armormob << ")" << endl;
			cout << name << " ������ ��� �� " << DamageFromMob << " ����(�)" << endl;
			Chance = rand() % 2 + 0; // �������� ����� ��� ��������� �������
			if (Chance == 1) // ���� ��� ����� = 1, �� ������ �������
			{
				cout << "��� ������ �������\n" << endl;
				Coins++;
			}
			Sleep(3000);
			goto attack1; // ����������� �� �����
		}
		else
		{
			if (DamageFromMob < 0)
			{
				DamageFromMob = 0;
			}
			if (OtkatSkill > 0)
			{
				OtkatSkill--;
			}
			if (Armor < 0)
			{
				Armor = 0;
			}
			if (OtkatSkill == 0)
			{
				if (TmpArmor < Armor)
				{
					Armor = TmpArmor;
					ArmorMax -= NumberArmorFromSkill;
				}
				else
				{
					Armor = TmpArmor;
				}
			}
			Experience = Experience + expfrommob; // ���� = ������� ���� + ���� � ������� ����
			if (Experience >= ExpMax) // �������� �� ��������� ������
			{
				if (Lvl == LvlMax) // �������� �������� ���� ��� ���
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t���� ���������!!!" << endl;
					Sleep(5000);
					exit(0);
				}
				else 
				{
					Lvl++; // ��������� ������ 
					if (Lvl == LvlMax)
					{
						system("cls");
						cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t���� ���������!!!" << endl;
						Sleep(5000);
						exit(0);
					}

					Experience = Experience - ExpMax; // ���� �������� ������ = ���� ���� ������ - ���� ������������ �� ������� �������
					ExpMax = ExpMax * 1.75; // ��������� ���� ����� �������� ������
					HpMax = HpMax * 1.5; // ��������� ���� ��������
					HealthPoint = HpMax; // �������������� ��������
					ManaMax = ManaMax * 1.2; // ��������� ����
					Mana = ManaMax; // �������������� ����
					Damage += 9; // ��������� �����
					ArmorMax += 2; // ��������� ���� �����
					Armor = ArmorMax; // �������������� �����
					TmpArmor = Armor; 
					NumberBHp += 1; // +1 ������� ��������
					NumberBMana += 1; // +1 ������� ����
					damagefrommob = damagefrommob * 1.75; // ��������� ����� �����
					expfrommob = expfrommob * 1.5; // ��������� ��������� ����� ����
					hpmob = hpmob * 1.75; // ��������� �������� ����
					armormob = armormob *1.3; // ��������� ����� ����
					cout << "\n�����������, ������� ������� �� " << Lvl << endl;
					cout << "�� �������� � 1,5 ���� � �������� �� ����" << endl;
					cout << "���� ��������� � 1,2 ���� � ��������� �� ����" << endl;
					cout << "���� ����� �� 9" << endl;
					cout << "����� ������� �� 2" << endl;
					cout << "���������� ������� � �� ��������� �� 1" << endl;
					cout << "���������� ������� � ����� ��������� �� 1" << endl;
					cout << "����� ����� �������" << endl;
					Sleep(10000);
					goto attack1;
				}
			}
			system("cls");
			OutBar("Class Warrior");
			cout << "\n����������� �� ����� ����� " << name << endl;
			cout << "�� �������� " << expfrommob << " �����" << endl;
			Chance = rand() % 2 + 0;
			if (Chance == 1)
			{
				cout << "��� ������ �������\n" << endl;
				Coins++;
			}
		}
	}
	else if (Menu == '2') // �����
	{
		if (OtkatSkill == 0 && Mana - SuperArmor.ManaCost > 0) // �������� �� ���������� ���� � ����� ������
		{
			Armor += NumberArmorFromSkill; // ��������� ����� ��� ������������� ������
			ArmorMax += NumberArmorFromSkill; // ��������� ���� �����
			Mana = Mana - SuperArmor.ManaCost; // ��������� ����
			OtkatSkill = TmpOtkatSkill;
			cout << "\n����� ���������� �� " << NumberArmorFromSkill << " �� " << OtkatSkill << " ����(��)" << endl;
			Sleep(3000);
			goto attack1;
		}
		else
		{
			if (OtkatSkill > 0)
			{
				cout << "\n����������� ���������� ��� " << OtkatSkill << " ����(��)" << endl;
			}
			else cout << "\n�� ������� ����" << endl;
			Sleep(3000);
			goto attack1;
		}
	}
	else if (Menu == '3') // ������� ��������
	{
		if (NumberBHp > 0) // ���� ������ 0, �� ����������
		{
			NumberBHp--; // ���������� ����������
			HealthPoint += HpFromBottle; // ��������� �������� ��������
			if (HealthPoint > HpMax) // �������� �� ������� ��,���� ��� �� ����� ������ ����
			{
				HealthPoint = HpMax;
			}
			cout << "\n�� ������ ������� � ��������� �������� �� 50 ��" << endl;
			Sleep(3000);
			goto attack1;
		}
		else
		{
			cout << "\n������� ����" << endl;
			Sleep(3000);
			goto attack1;
		}
	}
	else if (Menu == '4')
	{
		if (NumberBMana > 0)
		{
			NumberBMana--;
			Mana += ManaFromBottle;
			if (Mana > ManaMax)
			{
				Mana = ManaMax;
			}
			cout << "\n�� ������ ������� � ��������� ���� �� 20" << endl;
			Sleep(3000);
			goto attack1;
		}
		else
		{
			cout << "\n������� ���� " << endl;
			Sleep(3000);
			goto attack1;
		}
	}
	else if (Menu == '5')
	{
		char MagazMenu; // ���� ��������
	shop: // ����� ��������
		system("cls");
		OutBar("Class Warrior");
		cout << "1.�������� ����� - 30 �����" << endl;
		cout << "2.������ ��������� �� - 30 �����" << endl;
		cout << "3.������ ��������� ���� - 20 �����" << endl;
		cout << "4.������ ������ ����� (+30 � �����) - 70 �����" << endl;
		cout << "5.������ ������ ����� (+10 � �����) - 70 �����" << endl;
		cout << "6.��������� � ����" << endl;
		cout << "������� ";
		cin >> MagazMenu;
		if (MagazMenu == '1')
		{
			if (Coins >= 30) // ���� ���� ��������� ���������� �����,�� ��������
			{
				Armor = ArmorMax;
				Coins -= 30; // ��������� ���������� �������
				goto shop;
			}
			else // ���� ���� �������� ������� � ������� ������� ������
			{
				cout << "\n�� ������� �����" << endl;
				Sleep(3000);
				goto shop;
			}
		}
		else if (MagazMenu == '2')
		{
			if (Coins >= 30)
			{
				NumberBHp++;
				Coins -= 30;
				goto shop;
			}
			else
			{
				cout << "\n�� ������� �����" << endl;
				Sleep(3000);
				goto shop;
			}
		}
		else if (MagazMenu == '3')
		{
			if (Coins >= 20)
			{
				NumberBMana++;
				Coins -= 20;
				goto shop;
			}
			else
			{
				cout << "\n�� ������� �����" << endl;
				Sleep(3000);
				goto shop;
			}
		}
		else if (MagazMenu == '4')
		{
			if (Coins >= 70)
			{
				Damage += 30;
				Coins -= 70;
				goto shop;
			}
			else
			{
				cout << "\n�� ������� �����" << endl;
				Sleep(3000);
				goto shop;
			}
		}
		else if (MagazMenu == '5')
		{
			if (Coins >= 70)
			{
				ArmorMax += 10;
				Armor += 10;
				TmpArmor += 10;
				Coins -= 70;
				goto shop;
			}
			else
			{
				cout << "\n�� ������� �����" << endl;
				Sleep(3000);
				goto shop;
			}
		}
		else if (MagazMenu == '6')
		{
			goto attack1;
		}
		else
		{
			goto shop;
		}
	}
	else
	{
		goto attack1;
	}
}
