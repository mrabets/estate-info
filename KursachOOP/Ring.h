#pragma once

#include <typeinfo>
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Ring
{
public:
	Ring();
	~Ring();

	void addToEmpty(T data);
	void addToBegin(T data);
	void addToEnd(T data);
	void addByIndex(T value, int index);

	void deleteFirst();
	void deleteLast();
	void deleteByIndex(int index);

	void changeData(int index);
	void saveDataToFile();
	void display();

	int getSize();

	void clear();

private:
	template<class T>
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node<T>* head;

	void displayBase();
	void saveDataToFileBase(string fileName);
};

template<class T>
Ring<T>::Ring()
{
	size = 0;
	head = nullptr;
}

template<class T>
Ring<T>::~Ring()
{
	clear();
}

template<class T>
void Ring<T>::addToEnd(T data)
{
	if (head == nullptr)
	{
		addToEmpty(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->next != head)
		{
			current = current->next;
		}

		current->next = new Node<T>(data, head);

		size++;
	}
}

template<class T>
void Ring<T>::addToEmpty(T data)
{
	head = new Node<T>(data);
	head->next = head;

	size++;
}

template<class T>
void Ring<T>::addToBegin(T data)
{
	if (head == nullptr)
	{
		addToEmpty(data);
	}
	else
	{
		Node<T>* current = head;

		while (current->next != head)
		{
			current = current->next;
		}

		head = new Node<T>(data, head);
		current->next = head;

		size++;
	}
}

template<class T>
void Ring<T>::addByIndex(T value, int index)
{
	if (index == 0)
	{
		addToBegin(value);
		return;
	}

	if (index == size - 1)
	{
		addToEnd(value);
		return;
	}

	Node<T>* previous = head;

	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->next;
	}

	Node<T>* newNode = new Node<T>(value, previous->next);
	previous->next = newNode;

	size++;
}

template<class T>
void Ring<T>::deleteByIndex(int index)
{
	if (head == nullptr)
	{
		cout << "������� �����" << endl;
		return;
	}

	if (index == 0)
	{
		deleteFirst();
		return;
	}

	Node<T>* previous = head;

	if (previous->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T>* temp = previous->next;

		previous->next = temp->next;
		delete temp;
	}

	size--;
}

template<class T>
void Ring<T>::deleteFirst()
{
	if (head == nullptr)
	{
		cout << "������� �����" << endl;
		return;
	}

	Node<T>* current = head;

	if (current->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		while (current->next != head)
		{
			current = current->next;
		}

		Node<T>* temp = head;

		head = head->next;
		current->next = head;

		delete temp;
	}

	size--;
}

template<class T>
void Ring<T>::deleteLast()
{
	deleteByIndex(size - 1);
}

template<class T>
void Ring<T>::clear()
{
	if (head == nullptr)
	{
		return;
	}

	while (size)
	{
		deleteFirst();
	}

	cout << "������� �������" << endl << endl;
}

template<class T>
void Ring<T>::displayBase()
{
	if (head == nullptr)
	{
		cout << setw(20) << "..." << endl;
		return;
	}

	Node<T>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
}

template<class T>
void Ring<T>::display()
{
	displayBase();
}

template<>
void Ring<NewBuilding>::display()
{
	cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
		<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(12) << "��������" << endl;

	displayBase();
}

template<>
void Ring<SecondaryHousing>::display()
{
	cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
		<< setw(10) << "����" << setw(20) << "���-�� ������" << setw(18) << "��� �������" << endl;

	displayBase();
}

template<>
void Ring<Cottage>::display()
{
	cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
		<< setw(20) << "���-�� ������" << setw(15) << "��Ѩ���" << endl;

	displayBase();
}

template<>
void Ring<Country>::display()
{
	cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(18) << "���. �������" << setw(18) << "��� ���������"
		<< setw(20) << "���-�� ������" << setw(25) << "���������� �� ������" << endl;

	displayBase();
}

template<>
void Ring<Ground>::display()
{
	cout << setw(20) << "�����" << setw(20) << "��������" << setw(10) << "����" << setw(20) << "������� �������" << endl;

	displayBase();
}

template<class T>
int Ring<T>::getSize()
{
	return size;
}

template <class T>
void Ring<T>::changeData(int index)
{
	Node<T>* current = head;

	if (current->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		T data;

		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		cin >> data;
		current->data = data;
	}
}

template<class T>
void Ring<T>::saveDataToFileBase(string fileName)
{
	fstream fs;

	while (true)
	{
		cout << "�������� ����� ��� ������ � ���� ������: " << endl << endl
			<< "1. �������� ������" << endl
			<< "2. ������������ ������" << endl
			<< "3. ������� ������" << endl
			<< "4. ������� ������ �� �����" << endl
			<< "5. ������� ������" << endl << endl
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		string info;
		switch (choice)
		{
		case 1:
		{
			fs.open(fileName, fstream::out | fstream::app);

			if (!fs.is_open())
			{
				cout << "������ �������� �����" << endl;
			}
			else
			{
				if (head == nullptr)
				{
					cout << "������� �����" << endl;
					break;
				}

				Node<T>* current = head;

				while (current->next != head)
				{
					fs << current->data;
					current = current->next;
				}

				fs << current->data;

				cout << "������ ������� ��������� � ���� ������" << endl << endl;
			}

			fs.close();
			break;
		}

		case 2:
		{
			fs.open(fileName, fstream::out | fstream::trunc);

			if (!fs.is_open())
			{
				cout << "������ �������� �����" << endl;
			}
			else
			{
				if (head == nullptr)
				{
					cout << "������� �����" << endl;
					break;
				}

				Node<T>* current = head;
				while (current->next != head)
				{
					fs << current->data;
					current = current->next;
				}

				fs << current->data;

				cout << "������ ������� ������������ � ���� ������" << endl << endl;
			}

			fs.close();
			break;
		}

		case 3:
		{
			fs.open(fileName, fstream::in);

			if (!fs.is_open())
			{
				cout << "������ �������� �����" << endl;
			}
			else
			{
				while (true)
				{
					T object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					addToEnd(object);
				}

				cout << "������ ������� ��������� �� ���� ������" << endl << endl;
			}

			fs.close();
			break;
		}

		case 4:
		{
			fs.open(fileName, fstream::in);

			if (!fs.is_open())
			{
				cout << "������ �������� �����" << endl;
			}
			else
			{
				while (true)
				{
					T object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					cout << object;
				}
			}

			fs.close();
			break;
		}

		case 5:
		{
			fs.open(fileName, fstream::out | fstream::trunc);
			fs.close();
			break;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<NewBuilding>::saveDataToFile()
{
	saveDataToFileBase("NewBuilding.txt");
}

template<>
void Ring<SecondaryHousing>::saveDataToFile()
{
	saveDataToFileBase("SecondaryHousing.txt");
}

template<>
void Ring<Cottage>::saveDataToFile()
{
	saveDataToFileBase("Cottage.txt");
}

template<>
void Ring<Country>::saveDataToFile()
{
	saveDataToFileBase("Country.txt");
}

template<>
void Ring<Ground>::saveDataToFile()
{
	saveDataToFileBase("Ground.txt");
}

template<>
void Ring<NewBuilding>::changeData(int index)
{
	Node<NewBuilding>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "��������� ��������:" << endl
			<< "1. �����" << endl
			<< "2. ��������" << endl
			<< "3. ����" << endl
			<< "4. ����� �������" << endl
			<< "5. ��� ���������" << endl
			<< "6. ���-�� ������" << endl
			<< "7. ����" << endl
			<< "8. ��������" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "������� ����� �����: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "������� ������ ���������: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "������� ����� ����: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}		

		case 4:
		{
			cout << "������� ����� ����� �������: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "������� ����� ��� ���������: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "������� ����� ���-�� ������: ";
			int newRoomsAmount;
			cin >> newRoomsAmount;
			current->data.setRoomsAmount(newRoomsAmount);
			return;
		}

		case 7:
		{
			cout << "������� ����� ����: ";
			int newFloor;
			cin >> newFloor;
			current->data.setFloor(newFloor);
			return;
		}

		case 8:
		{
			cout << "������� ����� ��������: ";
			int newWarranty;
			cin >> newWarranty;
			current->data.setWarranty(newWarranty);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<SecondaryHousing>::changeData(int index)
{
	Node<SecondaryHousing>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "��������� ��������:" << endl
			<< "1. �����" << endl
			<< "2. ��������" << endl
			<< "3. ����" << endl
			<< "4. ����� �������" << endl
			<< "5. ��� ���������" << endl
			<< "6. ���-�� ������" << endl
			<< "7. ����" << endl
			<< "8. ��� �������" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "������� ����� �����: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "������� ������ ���������: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "������� ����� ����: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "������� ����� ����� �������: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "������� ����� ��� ���������: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "������� ����� ���-�� ������: ";
			int newRoomsAmount;
			cin >> newRoomsAmount;
			current->data.setRoomsAmount(newRoomsAmount);
			return;
		}

		case 7:
		{
			cout << "������� ����� ����: ";
			int newFloor;
			cin >> newFloor;
			current->data.setFloor(newFloor);
			return;
		}

		case 8:
		{
			cout << "������� ����� ��� �������: ";
			string newTypeOfRepair;
			cin >> newTypeOfRepair;
			current->data.setTypeOfRepair(newTypeOfRepair);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<Cottage>::changeData(int index)
{
	Node<Cottage>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "��������� ��������:" << endl
			<< "1. �����" << endl
			<< "2. ��������" << endl
			<< "3. ����" << endl
			<< "4. ����� �������" << endl
			<< "5. ��� ���������" << endl
			<< "6. ���-�� ������" << endl
			<< "7. ��� ������" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "������� ����� �����: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "������� ������ ���������: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "������� ����� ����: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "������� ����� ����� �������: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "������� ����� ��� ���������: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "������� ����� ���-�� ������: ";
			int newFloorsAmount;
			cin >> newFloorsAmount;
			current->data.setFloorsAmount(newFloorsAmount);
			return;
		}

		case 7:
		{
			cout << "������� ����� ��� ������: ";
			string newNameOfVillage;
			cin >> newNameOfVillage;
			current->data.setNameOfVillage(newNameOfVillage);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<Country>::changeData(int index)
{
	Node<Country>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "��������� ��������:" << endl
			<< "1. �����" << endl
			<< "2. ��������" << endl
			<< "3. ����" << endl
			<< "4. ����� �������" << endl
			<< "5. ��� ���������" << endl
			<< "6. ���-�� ������" << endl
			<< "7. ���������� �� ������" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "������� ����� �����: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "������� ������ ���������: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "������� ����� ����: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "������� ����� ����� �������: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "������� ����� ��� ���������: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "������� ����� ���-�� ������: ";
			int newFloorsAmount;
			cin >> newFloorsAmount;
			current->data.setFloorsAmount(newFloorsAmount);
			return;
		}

		case 7:
		{
			cout << "������� ����� ���������� �� ������: ";
			int newDistanceFromCity;
			cin >> newDistanceFromCity;
			current->data.setDistanceFromCity(newDistanceFromCity);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<Ground>::changeData(int index)
{
	Node<Ground>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "��������� ��������:" << endl
			<< "1. �����" << endl
			<< "2. ��������" << endl
			<< "3. ����" << endl
			<< "4. ������� ���������� �������" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "������� ����� �����: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "������� ������ ���������: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "������� ����� ����: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "������� ����� ������� ���������� �������: ";
			float newLandSquare;
			cin >> newLandSquare;
			current->data.setLandSquare(newLandSquare);
			return;
		}

		case 0:
			return;
		}
	}
}