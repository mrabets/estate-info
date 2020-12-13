#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"
#include "Estate.h"

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
	
	float price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
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

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
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

	float price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
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

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
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

	float price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
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

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
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

	float price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
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

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
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

	float price;
	while (true)
	{
		cin.clear();

		cout << "������� ���� (� ��������): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
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