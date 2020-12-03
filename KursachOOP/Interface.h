#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"

void pointOfEntry();

void userMenu();
bool isUserAuthorization();
void userRegistration();
void userFileCreating();

void adminMenu();
bool isAdminAuthorization();
void adminRegistration();
void adminFileCreating();

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenuAdmin();
};

template <class T>
void Interface<T>::serviceMenuAdmin()
{
	Ring<T> object;

	while (true)
	{
		cout << "�������� ��������:" << endl << endl
			<< "1. �������� ������ � ������ �������" << endl
			<< "2. �������� ������ � ����� �������" << endl
			<< "3. �������� ������ � ������� �� �������" << endl << endl
			<< "4. ������� ������ � ������ �������" << endl
			<< "5. ������� ������ � ����� �������" << endl
			<< "6. ������� ������ � ������� �� �������" << endl
			<< "7. ������� ��� ������" << endl << endl
			<< "8. ������������� ������" << endl << endl
			<< "9. ������� ������ �� �����" << endl << endl
			<< "10. ������ � ����� ������" << endl << endl
			<< "0. �����" << endl;

		int choiceMenu;
		cin >> choiceMenu;

		system("CLS");

		T value;
		int index;

		switch (choiceMenu)
		{
		case 1:
			cin >> value;
			object.addToBegin(value);

			break;

		case 2:
			cin >> value;
			object.addToEnd(value);

			break;

		case 3:
			cout << "������� ������: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "�������� ������" << endl;
				break;
			}

			cin >> value;

			object.addByIndex(value, index);

			break;

		case 4:
			object.deleteFirst();
			break;

		case 5:
			object.deleteLast();
			break;

		case 6:
			cout << "������� ������: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "�������� ������" << endl;
				break;
			}

			object.deleteByIndex(index);

			break;

		case 7:
			object.clear();
			break;

		case 8:
			cout << "������� ������: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "�������� ������" << endl;
				break;
			}

			object.changeData(index);

			break;

		case 9:
			object.display();
			break;

		case 10:
			object.saveDataToFile();
			break;

		case 0:
			return;
		}

		cout << endl;
	}
}

void typeChoosingAdmin()
{
	while (true)
	{
		int choiceDevice;

		cout << "�������� ������ ������������: " << endl << endl
			<< "1. �����������" << endl
			<< "2. ��������" << endl << endl
			<< "3. �������" << endl
			<< "4. ����" << endl << endl
			<< "5. �������" << endl << endl
			<< "0. ����� � ������� ����" << endl;

		cin >> choiceDevice;

		system("CLS");

		switch (choiceDevice)
		{
		case 1:
		{
			Interface<NewBuilding> object;
			object.serviceMenuAdmin();
		}
		break;

		case 2:
		{
			Interface<SecondaryHousing> object;
			object.serviceMenuAdmin();
		}
		break;

		case 3:
		{
			Interface<Cottage> object;
			object.serviceMenuAdmin();
		}
		break;

		case 4:
		{
			Interface<Country> object;
			object.serviceMenuAdmin();
		}
		break;

		case 5:
		{
			Interface<Ground> object;
			object.serviceMenuAdmin();
		}
		break;

		case 0:
			return;
		}
	}
}

void pointOfEntry()
{
	ifstream fin;

	fin.open("admin.txt");

	if (!fin.is_open())
	{
		adminFileCreating();
	}

	fin.close();

	fin.open("user.txt");

	if (!fin.is_open())
	{
		userFileCreating();
	}

	fin.close();

	while (true)
	{
		cout << "�������� ��� �����: " << endl
			<< "1. ������������" << endl
			<< "2. �������������" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			userRegistration();
			break;

		case 2:
			if (isAdminAuthorization())
			{
				cout << "�� ����� � �������" << endl;
				adminMenu();
			}
			else
			{
				cout << "�������� ����� ��� ������" << endl;
			}
			break;

		case 0:
			return;
		}
	}
}


void viewEstate()
{
	while (true)
	{
		string fileName;

		cout << "�����������: " << endl << endl
			<< "1.��� ������������" << endl
			<< "2. �����������" << endl
			<< "3. ��������" << endl
			<< "4. ��������" << endl
			<< "5. ����" << endl
			<< "6. �������" << endl << endl
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			break;

		case 2:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 3:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 4:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

			fileName = "Cottage.txt";
			break;

		case 5:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

			fileName = "Country.txt";
			break;

		case 6:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;

			fileName = "Ground.txt";
			break;

		case 0:
			return;
		}

		fstream fs;

		fs.open(fileName, fstream::in);

		if (!fs.is_open())
		{
			cout << "������ ��� ������������ ���������� � ��������" << endl;
		}
		else
		{
			char ch;
			while (fs.get(ch))
			{
				cout << ch;
			}	
		}
		fs.close();
	}
}

void searchEstate()
{
	while (true)
	{
		string fileName;

		cout << "������ � �������: " << endl << endl
			<< "1. ��� ������������" << endl
			<< "2. �����������" << endl
			<< "3. ��������" << endl
			<< "4. ��������" << endl
			<< "5. ����" << endl
			<< "6. �������" << endl << endl
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			break;

		case 2:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 3:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 4:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

			fileName = "Cottage.txt";
			break;

		case 5:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

			fileName = "Country.txt";
			break;

		case 6:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;

			fileName = "Ground.txt";
			break;

		case 0:
			return;
		}

		fstream fs;

		fs.open(fileName, fstream::in);

		if (fs.is_open())
		{
			cout << "������ ��� ������������ ���������� � ��������" << endl;
		}
		else
		{
			char ch;
			while (fs.get(ch))
			{
				cout << ch;
			}
		}
		fs.close();
	}
}

void userMenu()
{
	while (true)
	{
		cout << "�������� �����: " << endl
			<< "1. ����������� ������������" << endl
			<< "2. ������ ������������ �� ����������" << endl
			<< "3. ������ ������������" << endl << endl
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			viewEstate();
			break;

		case 2:
			searchEstate();
			break;

		case 3:

			break;

		case 0:
			return;
		}
	}
}

bool isUserAuthorization()
{
	string login;
	string password;

	cout << "�����: ";
	cin >> login;

	cout << "������: ";
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("user.txt");

	if (!fin.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		string temp;
		while (!fin.eof())
		{
			temp = "";
			fin >> temp;

			if (temp == login)
			{
				fin >> temp;
				if (temp == password)
				{
					fin.close();
					return true;
				}
			}
			else
			{
				fin >> temp;
			}
		}
	}

	fin.close();
	return false;
}

void userRegistration()
{
	fstream fs;

	while (true)
	{
		fs.open("user.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "�������� �����: " << endl
				<< "1. �����������" << endl
				<< "2. �����������" << endl;

			int userChoice;
			cin >> userChoice;

			system("CLS");

			switch (userChoice)
			{
			case 1:
				if (isUserAuthorization())
				{
					cout << "�� ����� � �������" << endl;
					userMenu();
				}
				else
				{
					cout << "�������� ����� ��� ������" << endl;
				}

				break;

			case 2:
			{
				string login;
				string password;

				cout << "������� �����: ";
				cin >> login;

				cout << "������� ������: ";
				cin >> password;

				fs << login << " " << password << "\n";

				cout << "�������� �����������" << endl;

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void userFileCreating()
{
	ofstream fout;

	fout.open("user.txt");

	if (!fout.is_open())
	{
		cout << "������ �������� �����" << endl;
	}

	fout.close();
}


void adminMenu()
{
	while (true)
	{
		cout << "�������� �����: " << endl << endl
			<< "1. ������ � ���������" << endl
			<< "2. ������ � �������� �������� ���������������" << endl << endl
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			typeChoosingAdmin();
			break;

		case 2:
			adminRegistration();
			break;

		case 0:
			return;
		}
	}
}

bool isAdminAuthorization()
{
	string login;
	string password;

	cout << "�����: ";
	cin >> login;

	cout << "������: ";
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("admin.txt");

	if (!fin.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		string temp;
		while (!fin.eof())
		{
			temp = "";
			fin >> temp;

			if (temp == login)
			{
				fin >> temp;
				if (temp == password)
				{
					fin.close();
					return true;
				}
			}
			else
			{
				fin >> temp;
			}
		}
	}

	fin.close();
	return false;
}

void adminRegistration()
{
	fstream fs;
	while (true)
	{
		fs.open("admin.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "�������� �����: " << endl
				<< "1. ���������������� ������ ��������������" << endl
				<< "2. ���������� ������ ���� ���������������" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string login;
				string password;

				cout << "������� �����: ";
				cin >> login;

				cout << "������� ������: ";
				cin >> password;

				fs << login << " " << password << "\n";
			}
			break;

			case 2:
			{
				string view;
				cout << setw(10) << "�����" << setw(10) << "������" << endl;

				while (!fs.eof())
				{
					view = "";

					fs >> view;
					cout << setw(10) << view;

					view = "";

					fs >> view;
					cout << setw(10) << view;

					cout << endl;
				}

				cout << endl << endl;
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}

	}


}

void adminFileCreating()
{
	ofstream fout;

	fout.open("admin.txt");

	if (!fout.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		string firstLoginAndPassword = "admin";

		fout << firstLoginAndPassword << " " << firstLoginAndPassword << "\n";
	}

	fout.close();
}


