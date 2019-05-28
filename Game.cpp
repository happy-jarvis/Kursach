#include "Game.h"

Game::Game(string name, string genre, string year, string platform, string developer, string quantity)
{
	this->name = name;
	this->genre = genre;
	this->year = year;
	this->platform = platform;
	this->developer = developer;
	this->quantity = quantity;
}

Game::Game()
{
	name = genre = year = platform = developer = quantity = "null";
}

string Game::getName()
{
	return name;
}

string Game::getGenre()
{
	return genre;
}

string Game::getYear()
{
	return year;
}

string Game::getPlatform()
{
	return platform;
}

string Game::getDeveloper()
{
	return developer;
}

string Game::getQuantity()
{
	return quantity;
}

void Game::find(string name)
{

}
