#pragma once

#include "Header.h"
#include "Game.h"
#include <fstream>

class File
{
private:
	fstream file;
	string path;
public:
	File(string path);
	void operator<<(Game &object);
	bool checkIsOpen();
	bool checkIsEof();
	void close();
	string getNameOfGame();
	string readLine();
};