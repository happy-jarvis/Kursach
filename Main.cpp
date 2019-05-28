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
	string name =""; // ��������;
	string genre = ""; // ����;
	string year = ""; // ��� �������;
	string platform = ""; // ���������;
	string developer = ""; // �����������;
	string quantity = ""; // ����������; 
	/////////////////////////////////

	int siteGameCounter = 0;
	int shopGameCounter = 0;
	int warehouseGameCounter = 0;

	do
	{
		CLEARWINDOW

			cout << "�������� ����������� ��������" << endl
			<< "1 - ����������;" << endl
			//<< "2 - ��������;" << endl
			<< "2 - ����� ���� (��� �������);" << endl
			<< "0 - ���������� ������;" << endl << endl << "-> "; cin >> key;
		
		CLEARWINDOW

		switch (key)
		{

		case 1: // ����������;
		{

			int keyCase1;

			cout << "�������� ������ ������ (1 - ����, 2 - �������, 3 - �����) -> "; cin >> keyCase1; CLEARWINDOW

				switch (keyCase1)
				{
				case 1: path = "site.txt"; siteGameCounter++; break; // ���������� �����;
				case 2: path = "shop.txt"; shopGameCounter++; break; // ���������� ��������;
				case 3: path = "warehouse.txt"; warehouseGameCounter++; break; // ���������� ������;
				default: cout << "������!" << endl; break;
				}

			flush_stdin();

			File file(path);

			if (!file.checkIsOpen())
			{
				cout << "������ ��� �������� ����� ��� ������!";
			}
			else
			{
				cout << "������� ��������: "; getline(cin, name); 
					cout << "������� ����: "; getline(cin, genre); 
					cout << "������� ���: "; getline(cin, year); 
					cout << "������� ���������: "; getline(cin, platform); 
					cout << "������� ������������: "; getline(cin, developer); 
					cout << "������� ����������: "; getline(cin, quantity); 

					Game game(name, genre, year, platform, developer, quantity);
				//fout.write((char*)&game, sizeof(Game));

				file << game;
				file.close();
			}
			CLEARWINDOW
				break;
		}

		case 2: // ��������;
		{
			int keyCase2;

			cout << "�������� ������ ������ (1 - ����, 2 - �������, 3 - �����) -> "; cin >> keyCase2; CLEARWINDOW

				switch (keyCase2)
				{
				case 1: path = "site.txt"; break; // �������� �����;
				case 2: path = "shop.txt"; break; // �������� ��������;
				case 3: path = "warehouse.txt"; break; // �������� ������;
				default: cout << "������!" << endl; break;
				}

			File file(path);
			string buffStr;

			if (!file.checkIsOpen())
			{
				cout << "������ ��� �������� ����� ��� ������!";
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

			cout << "���� - ��� � �������;" << endl;
			cout << "������� - ���� � �������;" << endl;
			cout << "����� - ��� � �������;" << endl;

			cout << endl << "���� Minecraft ���� ������� � ��������" << endl;
			PAUSEWINDOW
				break;
		case 0:
			cout << "������� �� ���������! ��������� ���!" << endl;
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
