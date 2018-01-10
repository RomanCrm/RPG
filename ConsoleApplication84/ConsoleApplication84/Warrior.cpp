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
	char Menu; // меню
	int DamageFromMob; // урон от моба с расчетом поглощением брони
	int TmpDamage; // урон персонажа с расчетом пробития брони
attack1: // метка
	system("cls");
	OutBar("Class Warrior");
	cout << "1.Ударить врага " << name << " обычной атакой" << endl;
	cout << "2.Использовать способность: " << SuperArmor.SkillName << " (Осталось " << OtkatSkill << " ход(а) до восстановления,стоимость " << SuperArmor.ManaCost << " маны)" << endl;
	cout << "3.Выпить баночку здоровья(" << NumberBHp << ")" << endl;
	cout << "4.Выпить баночку маны(" << NumberBMana << ")" << endl;
	cout << "5.Магазин" << endl;
	cout << "Выбрать: ";
	cin >> Menu;
	if (Menu == '1')
	{
		Evasion = rand() % 8;
		CritHit = rand() % 8;
		CountHits++;
		Vampirizm++; 
		Mana = Mana + ManaRegen; // повышение маны на количество поля ManaRegen

		if (Mana > ManaMax)
		{
			Mana = ManaMax; // устанавливает барьер для повышения маны до ManaMax
		}
		if (CountHits == ArmorDown) // поломка брони на 1,если значение полученых ударов = значению требуемого для поломки
		{
			Armor--;
			TmpArmor--;
			CountHits = 0;
		}
		if (Armor < 0) // чтоб броня не стала отрицательным числом
		{
			Armor = 0;
		}
		if (TmpArmor < 0) // чтоб временная переменная брони не стала орицательным числом
		{
			TmpArmor = 0;
		}

		DamageFromMob = damagefrommob - Armor*Absorption; // урон от моба = начальный урон моба - броня*коеф поглощения брони
		HealthPoint = HealthPoint - DamageFromMob; // хп = хп - нанесеный урон моба
		TmpDamage = Damage - armormob*BreakOut; // урон персонажа = урон текущий - броня моба*пробитие брони
		if (Evasion == 2) // если зарандомленое число уклона = 2, то промах
		{
			TmpDamage = 0;
			Vampirizm--;
		}
		if (CritHit == 3) // если зарандомленое число крит удара = 3, то крит удар
		{
			TmpDamage = TmpDamage*CoefDamageFromCritHit; // урон нанесеный*коеф крит удара
		}
		hpmob = hpmob - TmpDamage; // хп моба = текущее хп моба - нанесеный урон

		if (Vampirizm == VampirizmHits) // если счетчик вампиризма за каждый нанесеный удар = значению требуемого для вампиризма
		{
			HealthPoint += TmpDamage*VamprizmCoef; // хп = нанесенный урон*коеф вампиризма
			Vampirizm = 0;
		}
		if (HealthPoint > HpMax) // чтоб текущее здоровье не стало больше максимального
		{
			HealthPoint = HpMax; 
		}
		if (HealthPoint <= 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tВас убили!!!" << endl;
			Sleep(5000);
			exit(0); // выход из игры
		}
		if (hpmob > 0) 
		{
			system("cls");
			OutBar("Class Warrior");

			if (OtkatSkill > 0)
			{
				OtkatSkill--; // счетчик до того, как можно использовать скилл
			}
			if (OtkatSkill == 0)
			{
				if (TmpArmor < Armor) // если скилл был активен возвращает значение брони до повышения
				{
					Armor = TmpArmor;
					ArmorMax -= NumberArmorFromSkill;
				}
				else // в другом случае возвращает текущюю броню
				{
					Armor = TmpArmor;  
				}
			}
			if (DamageFromMob < 0) // чтоб урон не стал отрицательным
			{
				DamageFromMob = 0;
			}
			if (Evasion == 2) 
			{
				cout << "\nВы промахнулись" << endl;
			}
			else
			{
				if (CritHit == 3)
				{
					cout << "\nКритический удар" << endl;
					cout << "Вы ударили врага " << name << " на " << TmpDamage << " урон(а)" << endl;
				}
				else cout << "\nВы ударили врага " << name << " на " << TmpDamage << " урон(а)" << endl;
			}
			cout << name << " (" << "HEALTH: " << hpmob << " ARMOR: " << armormob << ")" << endl;
			cout << name << " ударил вас на " << DamageFromMob << " урон(а)" << endl;
			Chance = rand() % 2 + 0; // рандомит число для выпадения монетки
			if (Chance == 1) // если это число = 1, то выпала монетка
			{
				cout << "Вам выпала монетка\n" << endl;
				Coins++;
			}
			Sleep(3000);
			goto attack1; // возвращение на метку
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
			Experience = Experience + expfrommob; // опыт = текущий опыт + опыт с убитого моба
			if (Experience >= ExpMax) // проверка на повышение уровня
			{
				if (Lvl == LvlMax) // проверка пройдена игра или нет
				{
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tИгра закончена!!!" << endl;
					Sleep(5000);
					exit(0);
				}
				else 
				{
					Lvl++; // повышение уровня 
					if (Lvl == LvlMax)
					{
						system("cls");
						cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tИгра закончена!!!" << endl;
						Sleep(5000);
						exit(0);
					}

					Experience = Experience - ExpMax; // опыт текущего уровня = опыт пред уровня - опыт максимальный за прошлый уровень
					ExpMax = ExpMax * 1.75; // повышение макс опыта текущего уровня
					HpMax = HpMax * 1.5; // повышение макс здоровья
					HealthPoint = HpMax; // восстановление здоровья
					ManaMax = ManaMax * 1.2; // повышение маны
					Mana = ManaMax; // восстановление маны
					Damage += 9; // повышение урона
					ArmorMax += 2; // повышение макс брони
					Armor = ArmorMax; // восстановление брони
					TmpArmor = Armor; 
					NumberBHp += 1; // +1 баночка здоровья
					NumberBMana += 1; // +1 баночка маны
					damagefrommob = damagefrommob * 1.75; // повышение урона мобов
					expfrommob = expfrommob * 1.5; // повышение даваемого опыта моба
					hpmob = hpmob * 1.75; // повышение здоровья моба
					armormob = armormob *1.3; // повышение брони моба
					cout << "\nПоздравляем, уровень повышен до " << Lvl << endl;
					cout << "Хп увеличен в 1,5 раза и обновлен до макс" << endl;
					cout << "Мана увеличена в 1,2 раза и обновлена до макс" << endl;
					cout << "Урон вырос на 9" << endl;
					cout << "Броня выросла на 2" << endl;
					cout << "Количество баночек с хп увеличено на 1" << endl;
					cout << "Количество баночек с маной увеличено на 1" << endl;
					cout << "Враги стали сильнее" << endl;
					Sleep(10000);
					goto attack1;
				}
			}
			system("cls");
			OutBar("Class Warrior");
			cout << "\nПоздравляем вы убили врага " << name << endl;
			cout << "Вы получили " << expfrommob << " опыта" << endl;
			Chance = rand() % 2 + 0;
			if (Chance == 1)
			{
				cout << "Вам выпала монетка\n" << endl;
				Coins++;
			}
		}
	}
	else if (Menu == '2') // скилл
	{
		if (OtkatSkill == 0 && Mana - SuperArmor.ManaCost > 0) // проверка на количество маны и откат скилла
		{
			Armor += NumberArmorFromSkill; // повышение брони при использовании скилла
			ArmorMax += NumberArmorFromSkill; // повышение макс брони
			Mana = Mana - SuperArmor.ManaCost; // вычитание маны
			OtkatSkill = TmpOtkatSkill;
			cout << "\nБроня повысилась на " << NumberArmorFromSkill << " на " << OtkatSkill << " хода(ов)" << endl;
			Sleep(3000);
			goto attack1;
		}
		else
		{
			if (OtkatSkill > 0)
			{
				cout << "\nСпособность недоступна еще " << OtkatSkill << " хода(ов)" << endl;
			}
			else cout << "\nНе хватает маны" << endl;
			Sleep(3000);
			goto attack1;
		}
	}
	else if (Menu == '3') // баночка здоровья
	{
		if (NumberBHp > 0) // если больше 0, то используем
		{
			NumberBHp--; // уменьшение количества
			HealthPoint += HpFromBottle; // повышение текущего здоровья
			if (HealthPoint > HpMax) // проверка на текущее хп,чтоб оно не стало больше макс
			{
				HealthPoint = HpMax;
			}
			cout << "\nВы выпили баночку и пополнили здоровье на 50 хп" << endl;
			Sleep(3000);
			goto attack1;
		}
		else
		{
			cout << "\nБаночек нету" << endl;
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
			cout << "\nВы выпили баночку и пополнили ману на 20" << endl;
			Sleep(3000);
			goto attack1;
		}
		else
		{
			cout << "\nБаночек нету " << endl;
			Sleep(3000);
			goto attack1;
		}
	}
	else if (Menu == '5')
	{
		char MagazMenu; // меню магазина
	shop: // метка магазина
		system("cls");
		OutBar("Class Warrior");
		cout << "1.Починить броню - 30 монет" << endl;
		cout << "2.Купить бутылочку хп - 30 монет" << endl;
		cout << "3.Купить бутылочку маны - 20 монет" << endl;
		cout << "4.Купить свиток урона (+30 к урону) - 70 монет" << endl;
		cout << "5.Купить свиток брони (+10 к брони) - 70 монет" << endl;
		cout << "6.Вернуться в игру" << endl;
		cout << "Выбрать ";
		cin >> MagazMenu;
		if (MagazMenu == '1')
		{
			if (Coins >= 30) // если есть требуемое количество монет,то покупаем
			{
				Armor = ArmorMax;
				Coins -= 30; // понижение количества монеток
				goto shop;
			}
			else // если нету очистить консоль и открыть магазин заново
			{
				cout << "\nНе хватает монет" << endl;
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
				cout << "\nНе хватает монет" << endl;
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
				cout << "\nНе хватает монет" << endl;
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
				cout << "\nНе хватает монет" << endl;
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
				cout << "\nНе хватает монет" << endl;
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
