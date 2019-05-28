#include "File.h"

File::File(string path)
{
	this->path = path;
	file.open(path, fstream::in | fstream::out | fstream::app);
}

void File::operator<<(Game & object)
{
	file << setw(20) << left << object.getName()
		 << setw(20) << left << object.getGenre()
		 << setw(20) << left << object.getYear()
		 << setw(20) << left << object.getPlatform()
		 << setw(20) << left << object.getDeveloper()
		 << setw(20) << left << object.getQuantity() << endl;
}

bool File::checkIsOpen()
{
	if (file.is_open()) return 1;
	else return 0;
}

bool File::checkIsEof()
{
	if (file.eof()) return 0;
	else return 1;
}

void File::close()
{
	file.close();
}

string File::getNameOfGame()
{
	string name;
	file >> name;
	file.ignore(255, '\n');
	return name;
}

string File::readLine()
{
	string buffStr;
	getline(file, buffStr);
	return buffStr;
}
