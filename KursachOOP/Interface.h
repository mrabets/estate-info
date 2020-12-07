#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"
#include "User.h"

using namespace std;

void pointOfEntry();

void userMenu();
bool isUserAuthorization();
void userRegistration();
void userFileCreating();

void viewEstate();

void adminMenu();
bool isAdminAuthorization();
void adminRegistration();
void userManage();
void adminFileCreating();

string encryptDecrypt(string toEncrypt);

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenuAdmin();
	T enterData();
	void searchData();
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
			object.addToBegin(enterData());
			break;

		case 2:
			object.addToEnd(enterData());
			break;

		case 3:
			cout << "������� ������: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "�������� ������" << endl;
				break;
			}

			object.addByIndex(enterData(), index);

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


template<class T>
T Interface<T>::enterData()
{
	cout << "������� ������: ";
	T data;
	cin >> data;
	return data;
}

template<>
NewBuilding Interface<NewBuilding>::enterData()
{
	string city;
	cout << "������� ����� (����. �����): ";
	cin >> city;

	string owner;
	cout << "������� ��������� (����. ���������): ";
	cin >> owner;

	int price;
	cout << "������� ���� (� ��������): ";
	cin >> price;

	float livingSpace;
	cout << "������� ����� ������� (� ���������� ������): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "������� ��� ���������: ";
	cin >> yearBuilt;

	int floor;
	cout << "������� ����: ";
	cin >> floor;

	int roomsAmount;
	cout << "������� ���������� ������: ";
	cin >> roomsAmount;

	int waranty;
	cout << "������� �������� (���): ";
	cin >> waranty;

	NewBuilding object(waranty, roomsAmount, floor, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
SecondaryHousing Interface<SecondaryHousing>::enterData()
{
	string city;
	cout << "������� ����� (����. �����): ";
	cin >> city;

	string owner;
	cout << "������� ��������� (����. ���������): ";
	cin >> owner;

	int price;
	cout << "������� ���� (� ��������): ";
	cin >> price;

	float livingSpace;
	cout << "������� ����� ������� (� ���������� ������): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "������� ��� ���������: ";
	cin >> yearBuilt;

	int floor;
	cout << "������� ����: ";
	cin >> floor;

	int roomsAmount;
	cout << "������� ���������� ������: ";
	cin >> roomsAmount;

	string typeOfRepair;
	cout << "������� ��� ������� (����. ����������): ";
	cin >> typeOfRepair;

	SecondaryHousing object(city, owner, price, livingSpace, yearBuilt, roomsAmount, floor, typeOfRepair);
	return object;
}

template<>
Cottage Interface<Cottage>::enterData()
{
	string city;
	cout << "������� ����� (����. �����): ";
	cin >> city;

	string owner;
	cout << "������� ��������� (����. ���������): ";
	cin >> owner;

	int price;
	cout << "������� ���� (� ��������): ";
	cin >> price;

	float livingSpace;
	cout << "������� ����� ������� (� ���������� ������): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "������� ��� ���������: ";
	cin >> yearBuilt;

	int floorsAmount;
	cout << "������� ���������� ������: ";
	cin >> floorsAmount;

	string nameOfVillage;
	cout << "������� �������� ������: ";
	cin >> nameOfVillage;

	Cottage object(nameOfVillage, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Country Interface<Country>::enterData()
{
	string city;
	cout << "������� ����� (����. �����): ";
	cin >> city;

	string owner;
	cout << "������� ��������� (����. ���������): ";
	cin >> owner;

	int price;
	cout << "������� ���� (� ��������): ";
	cin >> price;

	float livingSpace;
	cout << "������� ����� ������� (� ���������� ������): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "������� ��� ���������: ";
	cin >> yearBuilt;

	int floorsAmount;
	cout << "������� ���������� ������: ";
	cin >> floorsAmount;

	int distanceFromCity;
	cout << "������� �������� ������: ";
	cin >> distanceFromCity;

	Country object(distanceFromCity, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Ground Interface<Ground>::enterData()
{
	string city;
	cout << "������� ����� (����. �����): ";
	cin >> city;

	string owner;
	cout << "������� ��������� (����. ���������): ";
	cin >> owner;

	int price;
	cout << "������� ���� (� ��������): ";
	cin >> price;

	float landSquare;
	cout << "������� ������� ���������� ������� (� ���������� ������): ";
	cin >> landSquare;

	Ground object(landSquare, city, owner, price);
	return object;
}

template<>
void Interface<NewBuilding>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("NewBuilding.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "������ ��: " << endl << endl
				<< "1. ������" << endl
				<< "2. ����" << endl
				<< "3. ���������� ������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "������� �����: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

				while (true)
				{
					NewBuilding object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int minPrice;
				int maxPrice;

				cout << "������� ����������� ����: ";
				cin >> minPrice;

				cout << "������� ������������ ����: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

				while (true)
				{
					NewBuilding object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getPrice() >= minPrice && object.getPrice() <= maxPrice)
					{
						cout << object;
					}

				}
			}
			break;

			case 3:
			{
				int roomsAmount;
				cout << "������� ���������� ������: ";
				cin >> roomsAmount;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

				while (true)
				{
					NewBuilding object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getRoomsAmount() == roomsAmount)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<SecondaryHousing>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("SecondaryHousing.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "������ ��: " << endl << endl
				<< "1. ������" << endl
				<< "2. ����" << endl
				<< "3. ����� �������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "������� �����: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

				while (true)
				{
					SecondaryHousing object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int floor ;
				cout << "������� �����: ";
				cin >> floor;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

				while (true)
				{
					SecondaryHousing object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getFloor() == floor)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 3:
			{
				float minLivingSpace;
				float maxLivingSpace;

				cout << "������� ����������� ����� �������: ";
				cin >> minLivingSpace;

				cout << "������� ������������ ����� �������: ";
				cin >> maxLivingSpace;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

				while (true)
				{
					SecondaryHousing object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getLivingSpace() <= maxLivingSpace && object.getLivingSpace() >= minLivingSpace)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<Cottage>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("Cottage.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "������ ��: " << endl << endl
				<< "1. �����" << endl
				<< "2. ������" << endl
				<< "3. ���������� ������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "������� �����: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

				while (true)
				{
					Cottage object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				string nameOfVillage;
				cout << "������� �������� ������: ";
				cin >> nameOfVillage;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

				while (true)
				{
					Cottage object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getNameOfVillage() == nameOfVillage)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 3:
			{
				int floorsAmount;
				cout << "������� ���������� ������: ";
				cin >> floorsAmount;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

				while (true)
				{
					Cottage object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getFloorsAmount() == floorsAmount)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<Country>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("Country.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "������ ��: " << endl << endl
				<< "1. ���������� �� ������" << endl
				<< "2. ����" << endl
				<< "3. ��� ���������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				int distanceFromCity;
				cout << "������� ������������ ���������� �� ������: ";
				cin >> distanceFromCity;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

				while (true)
				{
					Country object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getDistanceFromCity() <= distanceFromCity)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int minPrice;
				int maxPrice;

				cout << "������� ����������� ����: ";
				cin >> minPrice;

				cout << "������� ������������ ����: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

				while (true)
				{
					Country object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getPrice() >= minPrice && object.getPrice() <= maxPrice)
					{
						cout << object;
					}

				}
			}
			break;

			case 3:
			{
				int yearBuilt;
				cout << "������� ��� ���������: ";
				cin >> yearBuilt;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
					<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

				while (true)
				{
					Country object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getYearBuilt() == yearBuilt)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<Ground>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("Ground.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "������ ��: " << endl << endl
				<< "1. ������� ���������� �������" << endl
				<< "2. ����" << endl
				<< "3. �����" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				float minLandSquare;
				float maxLandSquare;

				cout << "������� ����������� ������� ���������� �������: ";
				cin >> minLandSquare;

				cout << "������� ������������ ������� ���������� �������: ";
				cin >> maxLandSquare;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;

				while (true)
				{
					Ground object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getLandSquare() <= maxLandSquare && object.getLandSquare() >= minLandSquare)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int minPrice;
				int maxPrice;

				cout << "������� ����������� ����: ";
				cin >> minPrice;

				cout << "������� ������������ ����: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;

				while (true)
				{
					Ground object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getPrice() >= minPrice && object.getPrice() <= maxPrice)
					{
						cout << object;
					}

				}
			}
			break;

			case 3:
			{
				string city;
				cout << "������� �����: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;

				while (true)
				{
					Ground object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
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
			<< "1. �����������" << endl
			<< "2. ��������" << endl
			<< "3. ��������" << endl
			<< "4. ����" << endl
			<< "5. �������" << endl << endl
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 2:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 3:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

			fileName = "Cottage.txt";
			break;

		case 4:
			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
				<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

			fileName = "Country.txt";
			break;

		case 5:
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
		case 2:
		{
			Interface<NewBuilding> object;
			object.searchData();
		}			
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
				string decrypted = encryptDecrypt(temp);
				if (decrypted == password)
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
				int age;
				char sex;
				string phone;
				string email;

				cout << "������� �����: ";
				cin >> login;

				cout << "������� ������: ";
				cin >> password;
				password = encryptDecrypt(password);

				cout << "�������: ";
				cin >> age;

				cout << "���: ";
				cin >> sex;

				cout << "����� ���������� ��������: ";
				cin >> phone;

				cout << "����� ����������� �����: ";
				cin >> email;

				string decrypted = encryptDecrypt(password);

				system("CLS");

				User user(login, password, age, sex, phone, email);
				
				fs << user;

				//fs << login << " " << decrypted << "\n";

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
			<< "2. ������ � �������� �������� ���������������" << endl
			<< "3. ������ � �������� �������� �������������" << endl << endl
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

		case 3:
			userManage();
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
				string decrypted = encryptDecrypt(temp);
				if (decrypted == password)
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
			cout << "�������� �����: " << endl << endl
				<< "1. ���������������� ������ ��������������" << endl
				<< "2. ���������� ������ ���� ���������������" << endl << endl
				<< "0. �����" << endl;

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

				string encrypted = encryptDecrypt(password);

				fs << setw(10) <<login << setw(10) << encrypted << "\n";
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

void userManage()
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
			cout << "�������� �����: " << endl << endl
				<< "1. ����������� ������ ���� �������������" << endl
				<< "2. ����������� ������ ������������� ������������" << endl
				<< "3. ������� ������ ���� �������������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				while (true)
				{
					User u;
					fs >> u;

					if (fs.eof())
					{
						break;
					}

					cout << u;
				}
			}

				/*char symbol;
				while (fs.get(symbol))
				{
					cout << symbol;
				}*/

				break;

			case 2:
			{
				string login;
				cout << "������� ����� ������������: ";
				cin >> login;

				while (true)
				{
					User u;
					fs >> u;

					if (fs.eof())
					{
						break;
					}

					if (u.getLogin() == login)
					{
						cout << u;
						break;
					}

				}
			}
				

				break;

			case 0:
				return;
			}
		}

		fs.close();
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
		fout << setw(10) << "�����" << setw(10) << "������" << "\n";

		string firstLogin = "admin";
		string firstPassword = "admin";

		firstPassword = encryptDecrypt(firstPassword);

		fout << setw(10) << firstLogin << setw(10) << firstPassword << "\n";
	}

	fout.close();
}

string encryptDecrypt(string toEncrypt)
{
	char key[3] = { 'K', 'C', 'Q' };
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}


