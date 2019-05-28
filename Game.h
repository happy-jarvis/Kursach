#pragma once

#include "Header.h"

class Game
{

private:
	string name = ""; // ��������;
	string genre = ""; // ����;
	string year = ""; // ��� �������;
	string platform = ""; // ���������;
	string developer = ""; // �����������;
	string quantity = ""; // ����������;
public:

	Game(string name, string genre, string year, string platform, string developer, string quantity);
	Game();
	string getName();
	string getGenre();
	string getYear();
	string getPlatform();
	string getDeveloper();
	string getQuantity();
	virtual void find(string name);
};