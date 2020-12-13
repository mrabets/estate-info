#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"
#include "Admin.h"
#include "User.h"

//void pointOfEntry();
//
//void userMenu();
//bool isUserAuthorization();
//void userRegistration();
//void userFileCreating();
//
//void viewEstate();
//
//void adminMenu();
//bool isAdminAuthorization();
//void adminRegistration();
//void userManage();
//void adminFileCreating();

//string encryptDecrypt(string toEncrypt);

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void service();
	T enterData();
	void searchData();
};

template <class T>
void Interface<T>::service()
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
	while (true)
	{
		cin.clear();

		cout << "������� ����� (����. �����): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= '�' && city[i] <= '�'))
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	string owner;
	while (true)
	{
		cin.clear();

		cout << "������� ��������� (����. ���������): ";
		cin >> owner;
		
		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	int price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "������� ����� ������� (� ���������� ������): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && price <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "������� ��� ���������: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	int floor;
	while (true)
	{
		cin.clear();

		cout << "������� ����: ";
		cin >> floor;

		if (floor >= 1 && floor <= 150)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	int roomsAmount;
	while (true)
	{
		cin.clear();

		cout << "������� ���������� ������: ";
		cin >> roomsAmount;

		if (roomsAmount >= 1 && roomsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	int waranty;
	while (true)
	{
		cin.clear();

		cout << "������� �������� (���): ";
		cin >> waranty;

		if (waranty >= 0 && waranty <= 20)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	NewBuilding object(waranty, roomsAmount, floor, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
SecondaryHousing Interface<SecondaryHousing>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "������� ����� (����. �����): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= '�' && city[i] <= '�'))
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	string owner;
	while (true)
	{
		cin.clear();

		cout << "������� ��������� (����. ���������): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "������� ����� ������� (� ���������� ������): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && price <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "������� ��� ���������: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int floor;
	while (true)
	{
		cin.clear();

		cout << "������� ����: ";
		cin >> floor;

		if (floor >= 1 && floor <= 150)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int roomsAmount;
	while (true)
	{
		cin.clear();

		cout << "������� ���������� ������: ";
		cin >> roomsAmount;

		if (roomsAmount >= 1 && roomsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	string typeOfRepair;
	while (true)
	{
		cin.clear();

		cout << "������� ��� ������� (����. ����������): ";
		cin >> typeOfRepair;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < typeOfRepair.length(); i++)
		{
			if (typeOfRepair[i] >= '0' && typeOfRepair[i] <= '9')
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	SecondaryHousing object(city, owner, price, livingSpace, yearBuilt, roomsAmount, floor, typeOfRepair);
	return object;
}

template<>
Cottage Interface<Cottage>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "������� ����� (����. �����): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= '�' && city[i] <= '�'))
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	string owner;
	while (true)
	{
		cin.clear();

		cout << "������� ��������� (����. ���������): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "������� ����� ������� (� ���������� ������): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && price <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "������� ��� ���������: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int floorsAmount;
	while (true)
	{
		cin.clear();

		cout << "������� ���������� ������: ";
		cin >> floorsAmount;

		if (floorsAmount >= 1 && floorsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	string nameOfVillage;
	while (true)
	{
		cin.clear();

		cout << "������� �������� ������: ";
		cin >> nameOfVillage;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < nameOfVillage.length(); i++)
		{
			if (!(nameOfVillage[i] >= '�' && nameOfVillage[i] <= '�'))
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}
	
	Cottage object(nameOfVillage, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Country Interface<Country>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "������� ����� (����. �����): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= '�' && city[i] <= '�'))
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	string owner;
	while (true)
	{
		cin.clear();

		cout << "������� ��������� (����. ���������): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "������� ����� ������� (� ���������� ������): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && price <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "������� ��� ���������: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int floorsAmount;
	while (true)
	{
		cin.clear();

		cout << "������� ���������� ������: ";
		cin >> floorsAmount;

		if (floorsAmount >= 1 && floorsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int distanceFromCity;
	while (true)
	{
		cin.clear();

		cout << "������� �������� ������: ";
		cin >> distanceFromCity;

		if (distanceFromCity >= 1 && distanceFromCity <= 50)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	Country object(distanceFromCity, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Ground Interface<Ground>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "������� ����� (����. �����): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= '�' && city[i] <= '�'))
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	string owner;
	while (true)
	{
		cin.clear();

		cout << "������� ��������� (����. ���������): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	int price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

	float landSquare;
	while (true)
	{
		cin.clear();

		cout << "������� ������� ���������� ������� (� ���������� ������): ";
		cin >> landSquare;

		if (landSquare >= 0.1 && landSquare <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "������������ ��������. ��������� ����: " << endl;
	}

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
				int floor;
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

//
//void typeChoosing()
//{
//	while (true)
//	{
//		int choiceDevice;
//
//		cout << "�������� ������ ������������: " << endl << endl
//			<< "1. �����������" << endl
//			<< "2. ��������" << endl << endl
//			<< "3. �������" << endl
//			<< "4. ����" << endl << endl
//			<< "5. �������" << endl << endl
//			<< "0. ����� � ������� ����" << endl;
//
//		cin >> choiceDevice;
//
//		system("CLS");
//
//		switch (choiceDevice)
//		{
//		case 1:
//		{
//			Interface<NewBuilding> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 2:
//		{
//			Interface<SecondaryHousing> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 3:
//		{
//			Interface<Cottage> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 4:
//		{
//			Interface<Country> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 5:
//		{
//			Interface<Ground> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 0:
//			return;
//		}
//	}
//}
//
//
//void pointOfEntry()
//{
//	ifstream fin;
//
//	fin.open("Admin.txt");
//
//	if (!fin.is_open())
//	{
//		adminFileCreating();
//	}
//
//	fin.close();
//
//	fin.open("User.txt");
//
//	if (!fin.is_open())
//	{
//		userFileCreating();
//	}
//
//	fin.close();
//
//	while (true)
//	{
//		cout << "�������� ��� �����: " << endl
//			<< "1. ������������" << endl
//			<< "2. �������������" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			userRegistration();
//			break;
//
//		case 2:
//			if (isAdminAuthorization())
//			{
//				cout << "�� ����� � �������" << endl;
//				adminMenu();
//			}
//			else
//			{
//				cout << "�������� ����� ��� ������" << endl;
//			}
//			break;
//
//		case 0:
//			return;
//		}
//	}
//}
//
//
//
//void viewEstate()
//{
//	while (true)
//	{
//		string fileName;
//
//		cout << "�����������: " << endl << endl
//			<< "1. �����������" << endl
//			<< "2. ��������" << endl
//			<< "3. ��������" << endl
//			<< "4. ����" << endl
//			<< "5. �������" << endl << endl
//			<< "0. �����" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;
//
//			fileName = "NewBuilding.txt";
//			break;
//
//		case 2:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;
//
//			fileName = "SecondaryHousing.txt";
//			break;
//
//		case 3:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;
//
//			fileName = "Cottage.txt";
//			break;
//
//		case 4:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;
//
//			fileName = "Country.txt";
//			break;
//
//		case 5:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;
//
//			fileName = "Ground.txt";
//			break;
//
//		case 0:
//			return;
//		}
//
//		fstream fs;
//
//		fs.open(fileName, fstream::in);
//
//		if (!fs.is_open())
//		{
//			cout << "������ ��� ������������ ���������� � ��������" << endl;
//		}
//		else
//		{
//			char ch;
//			while (fs.get(ch))
//			{
//				cout << ch;
//			}
//		}
//		fs.close();
//	}
//}
//
//void searchEstate()
//{
//	while (true)
//	{
//		string fileName;
//
//		cout << "������ � �������: " << endl << endl
//			<< "1. ��� ������������" << endl
//			<< "2. �����������" << endl
//			<< "3. ��������" << endl
//			<< "4. ��������" << endl
//			<< "5. ����" << endl
//			<< "6. �������" << endl << endl
//			<< "0. �����" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 2:
//		{
//			Interface<NewBuilding> object;
//			object.searchData();
//		}
//		break;
//
//		case 3:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;
//
//			fileName = "SecondaryHousing.txt";
//			break;
//
//		case 4:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;
//
//			fileName = "Cottage.txt";
//			break;
//
//		case 5:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
//				<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;
//
//			fileName = "Country.txt";
//			break;
//
//		case 6:
//			cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;
//
//			fileName = "Ground.txt";
//			break;
//
//		case 0:
//			return;
//		}
//
//		fstream fs;
//
//		fs.open(fileName, fstream::in);
//
//		if (fs.is_open())
//		{
//			cout << "������ ��� ������������ ���������� � ��������" << endl;
//		}
//		else
//		{
//
//		}
//		fs.close();
//	}
//}
//
//void userMenu()
//{
//	while (true)
//	{
//		cout << "�������� �����: " << endl
//			<< "1. ����������� ������������" << endl
//			<< "2. ������ ������������ �� ����������" << endl
//			<< "3. ������ ������������" << endl << endl
//			<< "0. �����" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			viewEstate();
//			break;
//
//		case 2:
//			searchEstate();
//			break;
//
//		case 3:
//		{
//			viewEstate();
//
//			break;
//		}
//			
//		case 0:
//			return;
//		}
//	}
//}
//
//bool isUserAuthorization()
//{
//	cout << "�����: ";
//
//	string login;
//	cin >> login;
//
//	cout << "������: ";
//
//	string password;
//	cin >> password;
//
//	system("CLS");
//
//	ifstream fin;
//
//	fin.open("User.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "������ �������� �����" << endl;
//	}
//	else
//	{
//		while (true)
//		{
//			User obj;
//			fin >> obj;
//
//			if (fin.eof())
//			{
//				break;
//			}
//
//			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
//			{
//				fin.close();
//				return true;
//			}
//		}
//	}
//
//	fin.close();
//	return false;
//}
//
//void userRegistration()
//{
//	fstream fs;
//
//	while (true)
//	{
//		fs.open("User.txt", fstream::in | fstream::out | fstream::app);
//
//		if (!fs.is_open())
//		{
//			cout << "������ �������� �����" << endl;
//		}
//		else
//		{
//			cout << "�������� �����: " << endl
//				<< "1. �����������" << endl
//				<< "2. �����������" << endl;
//
//			int userChoice;
//			cin >> userChoice;
//
//			system("CLS");
//
//			switch (userChoice)
//			{
//			case 1:
//				if (isUserAuthorization())
//				{
//					cout << "�� ����� � �������" << endl;
//					userMenu();
//				}
//				else
//				{
//					cout << "�������� ����� ��� ������" << endl;
//				}
//
//				break;
//
//			case 2:
//			{
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "�����: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string password;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "������: ";
//
//					cin >> password;
//
//					if (password.length() >= 5 && password.length() <= 12)
//					{
//						password = encryptDecrypt(password);
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				int age;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "�������: ";
//
//					cin >> age;
//
//					if (age >= 18 && age <= 120)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				char sex;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "��� (� - �������, � - �������): ";
//
//					cin >> sex;
//
//					if (sex == '�' || sex == '�' || sex == '�' || sex == '�')
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string phone;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "����� ���������� �������� (����. +375257712277): ";
//
//					cin >> phone;
//
//					if (phone.length() != 13 || phone[0] != '+')
//					{
//						system("CLS");
//						cout << "������������ ��������. ��������� ����: " << endl;
//					}
//
//					bool isAllDigit = true;
//					for (int i = 1; i < phone.length(); i++)
//					{
//						if (phone[i] < '0' || phone[i] > '9')
//						{
//							isAllDigit = false;
//							break;
//						}
//					}
//
//					if (isAllDigit)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string email;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "����� ����������� �����: ";
//					cin >> email;
//
//					bool isSign = false;
//					bool isPoint = false;
//					for (int i = 0; i < email.length(); i++)
//					{
//						if (email[i] == '@' && !isSign)
//						{
//							isSign = true;
//						}
//
//						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
//						{
//							isPoint = true;
//						}
//					}
//
//					if (isSign && isPoint)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				system("CLS");
//
//				User user(login, password, age, sex, phone, email);
//
//				fs << user;
//
//				cout << "�������� �����������" << endl;
//
//				break;
//			}
//
//			case 0:
//				return;
//			}
//		}
//
//		fs.close();
//	}
//}
//
//void userFileCreating()
//{
//	ofstream fout;
//
//	fout.open("User.txt");
//
//	if (!fout.is_open())
//	{
//		cout << "������ �������� �����" << endl;
//	}
//
//	fout.close();
//}
//
//
//void adminMenu()
//{
//	while (true)
//	{
//		cout << "�������� �����: " << endl << endl
//			<< "1. ������ � ���������" << endl
//			<< "2. ������ � �������� �������� ���������������" << endl
//			<< "3. ������ � �������� �������� �������������" << endl << endl
//			<< "0. �����" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			typeChoosing();
//			break;
//
//		case 2:
//			adminRegistration();
//			break;
//
//		case 3:
//			userManage();
//			break;
//
//		case 0:
//			return;
//		}
//	}
//}
//
//bool isAdminAuthorization()
//{
//	cout << "�����: ";
//
//	string login;
//	cin >> login;
//
//	cout << "������: ";
//
//	string password;
//	cin >> password;
//
//	system("CLS");
//
//	ifstream fin;
//
//	fin.open("Admin.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "������ �������� �����" << endl;
//	}
//	else
//	{
//		while (true)
//		{
//			Admin obj;
//			fin >> obj;
//
//			if (fin.eof())
//			{
//				break;
//			}
//
//			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
//			{
//				fin.close();
//				return true;
//			}
//		}
//	}
//
//	fin.close();
//	return false;
//}
//
//void adminRegistration()
//{
//	fstream fs;
//	while (true)
//	{
//		fs.open("Admin.txt", fstream::in | fstream::out | fstream::app);
//
//		if (!fs.is_open())
//		{
//			cout << "������ �������� �����" << endl;
//		}
//		else
//		{
//			cout << "�������� �����: " << endl << endl
//				<< "1. ���������������� ������ ��������������" << endl
//				<< "2. ���������� ������ ���� ���������������" << endl << endl
//				<< "0. �����" << endl;
//
//			int choice;
//			cin >> choice;
//
//			system("CLS");
//
//			switch (choice)
//			{
//			case 1:
//			{
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "�����: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string password;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "������: ";
//
//					cin >> password;
//
//					if (password.length() >= 5 && password.length() <= 12)
//					{
//						password = encryptDecrypt(password);
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				system("CLS");
//
//				Admin admin(login, password);
//
//				fs << admin;
//
//				cout << "�������� ���������� ������ ��������������" << endl;
//
//				break;
//			}		
//
//			case 2:
//			{	
//				cout << setw(12) << "�����" << setw(12) << "������" << endl;
//
//				while (true)
//				{
//					Admin obj;
//					fs >> obj;
//
//					if (fs.eof())
//					{
//						break;
//					}
//
//					cout << obj;
//				}
//
//				break;
//			}
//
//			case 0:
//				return;
//			}
//
//			fs.close();
//		}
//
//	}
//
//
//}
//
//void userManage()
//{
//	fstream fs;
//	while (true)
//	{
//		fs.open("User.txt", fstream::in | fstream::out | fstream::app);
//
//		if (!fs.is_open())
//		{
//			cout << "������ �������� �����" << endl;
//		}
//		else
//		{
//			cout << "�������� �����: " << endl << endl
//				<< "1. ����������� ������ ���� �������������" << endl
//				<< "2. ����������� ������ ������������� ������������" << endl
//				<< "3. �������� ������ ������������" << endl << endl
//				<< "0. �����" << endl;
//
//			int choice;
//			cin >> choice;
//
//			system("CLS");
//
//			switch (choice)
//			{
//			case 1:
//			{
//				cout << setw(12) << "�����" << setw(12) << "������" << setw(10) << "�������" << setw(5) << "���" << setw(18) << "���.�����" << setw(22) << "�����" << endl;
//
//				while (true)
//				{
//					User obj;
//					fs >> obj;
//
//					if (fs.eof())
//					{
//						break;
//					}
//
//					cout << obj;
//				}
//
//				break;
//			}
//
//			case 2:
//			{
//				cout << setw(12) << "�����" << setw(12) << "������" << setw(10) << "�������" << setw(5) << "���" << setw(18) << "���.�����" << setw(22) << "�����" << endl;
//
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "����� ������������: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				while (true)
//				{
//					User obj;
//					fs >> obj;
//
//					if (fs.eof())
//					{
//						break;
//					}
//
//					if (obj.getLogin() == login)
//					{
//						cout << obj;
//						break;
//					}
//
//				}
//
//				break;
//			}
//
//			case 3:
//			{
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "�����: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string password;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "������: ";
//
//					cin >> password;
//
//					if (password.length() >= 5 && password.length() <= 12)
//					{
//						password = encryptDecrypt(password);
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				int age;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "�������: ";
//
//					cin >> age;
//
//					if (age >= 18 && age <= 120)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				char sex;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "��� (� - �������, � - �������): ";
//
//					cin >> sex;
//
//					if (sex == '�' || sex == '�' || sex == '�' || sex == '�')
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string phone;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "����� ���������� �������� (����. +375257712277): ";
//
//					cin >> phone;
//
//					if (phone.length() != 13 || phone[0] != '+')
//					{
//						system("CLS");
//						cout << "������������ ��������. ��������� ����: " << endl;
//					}
//
//					bool isAllDigit = true;
//					for (int i = 1; i < phone.length(); i++)
//					{
//						if (phone[i] < '0' || phone[i] > '9')
//						{
//							isAllDigit = false;
//							break;
//						}
//					}
//
//					if (isAllDigit)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}
//
//				string email;	
//				while (true)
//				{
//					cin.clear();
//
//					cout << "����� ����������� �����: ";
//					cin >> email;
//
//					bool isSign = false;
//					bool isPoint = false;
//					for (int i = 0; i < email.length(); i++)
//					{
//						if (email[i] == '@' && !isSign)
//						{
//							isSign = true;
//						}
//
//						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
//						{
//							isPoint = true;
//						}
//					}
//
//					if (isSign && isPoint)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "������������ ��������. ��������� ����: " << endl;
//				}			
//
//				system("CLS");
//
//				User user(login, password, age, sex, phone, email);
//
//				fs << user;
//
//				cout << "�������� ���������� ������ ������������" << endl;
//
//				break;
//			}
//
//			case 0:
//				return;
//			}
//		}
//
//		fs.close();
//	}
//}
//
//void adminFileCreating()
//{
//	ofstream fout;
//
//	fout.open("Admin.txt");
//
//	if (!fout.is_open())
//	{
//		cout << "������ �������� �����" << endl;
//	}
//	else
//	{
//		Admin admin("admin", encryptDecrypt("admin"));
//		fout << admin;
//	}
//
//	fout.close();
//}
//
//string encryptDecrypt(string toEncrypt)
//{
//	char key[3] = { 'K', 'C', 'Q' };
//	string output = toEncrypt;
//
//	for (int i = 0; i < toEncrypt.size(); i++)
//		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
//
//	return output;
//}