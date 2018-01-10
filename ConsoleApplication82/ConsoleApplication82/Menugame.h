#pragma once
class Menugame
{
public:
	char* map[25][25];  //������ �������� ���� ����
	char* chooseclass[30][80]; //������ ���� ������ ���������
	int x, y; // ���������� ����
	Menugame(); // ������ ��������� ��������� �����������
	void outmap(); // ����� �������� ����
	void inmap(); // ���������� �������� ���� ���������
	void outchooseclass(); // ����� ���� ������ ���������
	void inchooseclass(); // ���������� ���� ������ ���������
	void newgame(); // ��������� ��������� ���� ������ ��������� ��� ������� ������� ( >> << ��������� � ���� �� NEW GAME )
	void options(); // ��������� ���� � ������� ( >> << ��������� � ���� �� OPTIONS )
	void history(); // ��������� ������� � ��������� ( >> << ��������� � ���� �� HISTORY )
	void exit1(); // ������� �� ���� ( >> << ��������� � ���� �� EXIT )
	void infoout(); // ������� � ���������
	void musicon(); // ��� ������ ( >> << ��������� � ���� �� MUSIC ON )
	void musicoff(); // ���� ������ ( >> << ��������� � ���� �� MUSIC OFF )
	void backtomenu(); // ��������� � ������� ���� ( >> << ��������� � ���� �� BACK TO MENU )
	void random(); // ������ ��������� ����
	void choosewarrior(); // ��������� ����� ������� � ����� ( >> << ��������� � ���� �� CLASS WARRIOR )
	void choosemenu(); // ���������� � ������� ���� ( >> << ��������� � ���� �� BACK TO MENU )
	~Menugame();
};

