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
	void searchData();

	void searchDataInFile(string fileName);

private:
	void enterData(T* data);	
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
			enterData(&value);
			object.addToBegin(value);
			break;

		case 2:
			enterData(&value);
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

			enterData(&value);
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
			object.fileService();
			break;

		case 0:
			return;
		}

		cout << endl;
	}
}

template<>
void Interface<NewBuilding>::searchDataInFile(string fileName)
{
	fstream fs;

	while (true)
	{
		fs.open(fileName, fstream::in);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{


			cout << "��������� ��������:" << endl
				<< "1. �����" << endl
				<< "2. ��������" << endl
				<< "3. ����" << endl
				<< "4. ����� �������" << endl
				<< "5. ��� ���������" << endl
				<< "6. ���-�� ������" << endl
				<< "7. ����" << endl
				<< "8. ��������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if ()
					{
						cout << object;
					}

				}
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			case 8:
				break;

			case 0:
				return;
			}
		}

		fs.close();
	}

	
}

template<class T>
void Interface<T>::searchData()
{

}

template<class T>
void Interface<T>::enterData(T* object)
{
	(*object).enterData();
}