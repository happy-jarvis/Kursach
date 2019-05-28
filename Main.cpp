#include "Header.h"
#include "Game.h"
#include "File.h"

void flush_stdin();

int main()
{
	setlocale(LC_ALL, "Rus");

	int key = 0;
	string path = "";

	/////////////////////////////////
	string name =""; // название;
	string genre = ""; // жанр;
	string year = ""; // год выпуска;
	string platform = ""; // платформа;
	string developer = ""; // разработчик;
	string quantity = ""; // количество; 
	/////////////////////////////////

	int siteGameCounter = 0;
	int shopGameCounter = 0;
	int warehouseGameCounter = 0;

	do
	{
		CLEARWINDOW

			cout << "Выберите необходимое действие" << endl
			<< "1 - Заполнение;" << endl
			//<< "2 - Просмотр;" << endl
			<< "2 - Поиск игры (для клиента);" << endl
			<< "0 - Завершение работы;" << endl << endl << "-> "; cin >> key;
		
		CLEARWINDOW

		switch (key)
		{

		case 1: // заполнение;
		{

			int keyCase1;

			cout << "Выберите нужный ресурс (1 - сайт, 2 - магазин, 3 - склад) -> "; cin >> keyCase1; CLEARWINDOW

				switch (keyCase1)
				{
				case 1: path = "site.txt"; siteGameCounter++; break; // заполнение сайта;
				case 2: path = "shop.txt"; shopGameCounter++; break; // заполнение магазина;
				case 3: path = "warehouse.txt"; warehouseGameCounter++; break; // заполнение склада;
				default: cout << "Ошибка!" << endl; break;
				}

			flush_stdin();

			File file(path);

			if (!file.checkIsOpen())
			{
				cout << "Ошибка при открытии файла для записи!";
			}
			else
			{
				cout << "Введите название: "; getline(cin, name); 
					cout << "Введите жанр: "; getline(cin, genre); 
					cout << "Введити год: "; getline(cin, year); 
					cout << "Введите платформу: "; getline(cin, platform); 
					cout << "Введите разработчика: "; getline(cin, developer); 
					cout << "Введите количество: "; getline(cin, quantity); 

					Game game(name, genre, year, platform, developer, quantity);
				//fout.write((char*)&game, sizeof(Game));

				file << game;
				file.close();
			}
			CLEARWINDOW
				break;
		}

		case 2: // просмотр;
		{
			int keyCase2;

			cout << "Выберите нужный ресурс (1 - сайт, 2 - магазин, 3 - склад) -> "; cin >> keyCase2; CLEARWINDOW

				switch (keyCase2)
				{
				case 1: path = "site.txt"; break; // просмотр сайта;
				case 2: path = "shop.txt"; break; // просмотр магазина;
				case 3: path = "warehouse.txt"; break; // просмотр склада;
				default: cout << "Ошибка!" << endl; break;
				}

			File file(path);
			string buffStr;

			if (!file.checkIsOpen())
			{
				cout << "Ошибка при открытии файла для чтения!";
			}
			else
			{
				while (file.checkIsEof())
				{
					buffStr = file.readLine();
					cout << buffStr << endl;
				}
				PAUSEWINDOW
			}

			file.close();
			CLEARWINDOW
				break;
		}

		case 3:

			cout << "Сайт - нет в наличии;" << endl;
			cout << "Магазин - есть в наличии;" << endl;
			cout << "Склад - нет в наличии;" << endl;

			cout << endl << "Игра Minecraft была найдена в магазине" << endl;
			PAUSEWINDOW
				break;
		case 0:
			cout << "Спасибо за посещение! Приходите еще!" << endl;
			break;
		}

	} while (key != 0);

	PAUSEWINDOW
}

void flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}
