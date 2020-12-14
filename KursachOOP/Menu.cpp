#include "Menu.h"
#include "Interface.h"

void Menu::pointOfEntry()
{
	ifstream fin;

	fin.open("Admin.txt");

	if (!fin.is_open())
	{
		adminFileCreating();
	}

	fin.close();

	fin.open("User.txt");

	if (!fin.is_open())
	{
		userFileCreating();
	}

	fin.close();

	while (true)
	{
		cout << "�������� ��� �����: " << endl << endl
			<< "1. ������������" << endl
			<< "2. �������������" << endl << endl
			<< "0. �����" << endl;

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
				cout << "�� ����� � �������" << endl << endl;
				adminMenu();
			}
			else
			{
				cout << "�������� ����� ��� ������" << endl << endl;
			}
			break;

		case 0:
			return;
		}
	}
}

void Menu::typeChoosing()
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
			object.service();
		}
		break;

		case 2:
		{
			Interface<SecondaryHousing> object;
			object.service();
		}
		break;

		case 3:
		{
			Interface<Cottage> object;
			object.service();
		}
		break;

		case 4:
		{
			Interface<Country> object;
			object.service();
		}
		break;

		case 5:
		{
			Interface<Ground> object;
			object.service();
		}
		break;

		case 0:
			return;
		}
	}
}

void Menu::userMenu()
{
	while (true)
	{
		cout << "�������� �����: " << endl << endl
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
			viewEstateFile();
			break;

		case 2:
			searchEstateFile();
			break;

		case 3:
		{
			viewEstateFile();
			break;
		}

		case 0:
			return;
		}
	}
}

bool Menu::isUserAuthorization()
{
	cout << "�����: ";

	string login;
	cin >> login;

	cout << "������: ";

	string password;
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("User.txt");

	if (!fin.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		while (true)
		{
			User obj;
			fin >> obj;

			if (fin.eof())
			{
				break;
			}

			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
			{
				fin.close();
				return true;
			}
		}
	}

	fin.close();
	return false;
}

void Menu::userRegistration()
{
	fstream fs;

	while (true)
	{
		fs.open("User.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "�������� �����: " << endl << endl
				<< "1. �����������" << endl
				<< "2. �����������" << endl << endl
				<< "0. �����" << endl;

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
				while (true)
				{
					cin.clear();

					cout << "�����: ";

					cin >> login;

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				string password;
				while (true)
				{
					cin.clear();

					cout << "������: ";

					cin >> password;

					if (password.length() >= 5 && password.length() <= 12)
					{
						password = encryptDecrypt(password);
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				int age;
				while (true)
				{
					cin.clear();

					cout << "�������: ";

					cin >> age;

					if (age >= 18 && age <= 120)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				char sex;
				while (true)
				{
					cin.clear();

					cout << "��� (� - �������, � - �������): ";

					cin >> sex;

					if (sex == '�' || sex == '�' || sex == '�' || sex == '�')
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				string phone;
				while (true)
				{
					cin.clear();

					cout << "����� ���������� �������� (����. +375257712277): ";

					cin >> phone;

					if (phone.length() != 13 || phone[0] != '+')
					{
						system("CLS");
						cout << "������������ ��������. ��������� ����: " << endl;
					}

					bool isAllDigit = true;
					for (int i = 1; i < phone.length(); i++)
					{
						if (phone[i] < '0' || phone[i] > '9')
						{
							isAllDigit = false;
							break;
						}
					}

					if (isAllDigit)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				string email;
				while (true)
				{
					cin.clear();

					cout << "����� ����������� �����: ";
					cin >> email;

					bool isSign = false;
					bool isPoint = false;
					for (int i = 0; i < email.length(); i++)
					{
						if (email[i] == '@' && !isSign)
						{
							isSign = true;
						}

						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
						{
							isPoint = true;
						}
					}

					if (isSign && isPoint)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				system("CLS");

				User user(login, password, age, sex, phone, email);

				fs << user;

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

void Menu::userFileCreating()
{
	ofstream fout;

	fout.open("User.txt");

	if (!fout.is_open())
	{
		cout << "������ �������� �����" << endl;
	}

	fout.close();
}

void Menu::viewEstateFile()
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
			cout << "������ �������� �����" << endl;
		}
		else
		{
			char ch;
			while (fs.get(ch))
			{
				cout << ch;
			}
		}
	}
}

void Menu::searchEstateFile()
{
	while (true)
	{
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
		{
			Interface<NewBuilding> interface;
			interface.searchDataInFile();
			break;
		}
			
		case 2:
		{
			Interface<SecondaryHousing> interface;
			interface.searchDataInFile();
			break;
		}		

		case 3:
		{
			Interface<Cottage> interface;
			interface.searchDataInFile();
			break;
		}

		case 4:
		{
			Interface<Country> interface;
			interface.searchDataInFile();
			break;
		}

		case 5:
		{
			Interface<Ground> interface;
			interface.searchDataInFile();
			break;
		}
			
		case 0:
			return;
		}
	}		
}

void Menu::adminMenu()
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
			typeChoosing();
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

bool Menu::isAdminAuthorization()

{
	cout << "�����: ";

	string login;
	cin >> login;

	cout << "������: ";

	string password;
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("Admin.txt");

	if (!fin.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		while (true)
		{
			Admin obj;
			fin >> obj;

			if (fin.eof())
			{
				break;
			}

			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
			{
				fin.close();
				return true;
			}
		}
	}

	fin.close();
	return false;
}

void Menu::adminRegistration()
{
	fstream fs;
	while (true)
	{
		cout << "�������� �����: " << endl << endl
			<< "1. ���������������� ������ ��������������" << endl
			<< "2. ������� ���� ���������������" << endl 
			<< "3. ���������� ������ ���� ���������������" << endl << endl			
			<< "0. �����" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
		{
			fs.open("Admin.txt", fstream::out | fstream::app);

			string login;
			while (true)
			{
				cin.clear();

				cout << "�����: ";

				cin >> login;

				if (login.length() >= 5 && login.length() <= 12)
				{
					break;
				}

				system("CLS");
				cout << "������������ ��������. ��������� ����: " << endl;
			}

			string password;
			while (true)
			{
				cin.clear();

				cout << "������: ";

				cin >> password;

				if (password.length() >= 5 && password.length() <= 12)
				{
					password = encryptDecrypt(password);
					break;
				}

				system("CLS");
				cout << "������������ ��������. ��������� ����: " << endl;
			}

			system("CLS");

			Admin admin(login, password);

			fs << admin;

			cout << "�������� ���������� ������ ��������������" << endl;

			fs.close();
			break;
		}

		case 2:
		{
			adminFileCreating();

			cout << "������� �������" << endl;

			break;
		}

		case 3:
		{
			fs.open("Admin.txt", fstream::in);

			cout << setw(12) << "�����" << setw(12) << "������" << endl;

			while (true)
			{
				Admin obj;
				fs >> obj;

				if (fs.eof())
				{
					break;
				}

				cout << obj;
			}

			cout << endl;

			fs.close();
			break;
		}

		case 0:
			return;
		}
	}
}

void Menu::userManage()
{
	fstream fs;
	while (true)
	{
		fs.open("User.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "������ �������� �����" << endl;
		}
		else
		{
			cout << "�������� �����: " << endl << endl
				<< "1. ����������� ������ ���� �������������" << endl
				<< "2. ����������� ������ ������������� ������������" << endl
				<< "3. �������� ������ ������������" << endl
				<< "4. ������� ���� �������������" << endl << endl
				<< "0. �����" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				cout << setw(12) << "�����" << setw(12) << "������" << setw(10) << "�������" << setw(5) << "���" << setw(18) << "���.�����" << setw(22) << "�����" << endl;

				while (true)
				{
					User obj;
					fs >> obj;

					if (fs.eof())
					{
						break;
					}

					cout << obj;
				}

				cout << endl;

				break;
			}

			case 2:
			{
				string login;
				while (true)
				{
					cin.clear();

					cout << "����� ������������: ";

					cin >> login;
					system("CLS");

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					cout << "������������ ��������. ��������� ����: " << endl;
				}

				cout << setw(12) << "�����" << setw(12) << "������" << setw(10) << "�������" << setw(5) << "���" << setw(18) << "���.�����" << setw(22) << "�����" << endl;

				while (true)
				{
					User obj;
					fs >> obj;

					if (fs.eof())
					{
						break;
					}

					if (obj.getLogin() == login)
					{
						cout << obj;
						break;
					}

				}

				cout << endl;

				break;
			}

			case 3:
			{
				string login;
				while (true)
				{
					cin.clear();

					cout << "�����: ";

					cin >> login;

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				string password;
				while (true)
				{
					cin.clear();

					cout << "������: ";

					cin >> password;

					if (password.length() >= 5 && password.length() <= 12)
					{
						password = encryptDecrypt(password);
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				int age;
				while (true)
				{
					cin.clear();

					cout << "�������: ";

					cin >> age;

					if (age >= 18 && age <= 120)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				char sex;
				while (true)
				{
					cin.clear();

					cout << "��� (� - �������, � - �������): ";

					cin >> sex;

					if (sex == '�' || sex == '�' || sex == '�' || sex == '�')
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				string phone;
				while (true)
				{
					cin.clear();

					cout << "����� ���������� �������� (����. +375257712277): ";

					cin >> phone;

					if (phone.length() != 13 || phone[0] != '+')
					{
						system("CLS");
						cout << "������������ ��������. ��������� ����: " << endl;
					}

					bool isAllDigit = true;
					for (int i = 1; i < phone.length(); i++)
					{
						if (phone[i] < '0' || phone[i] > '9')
						{
							isAllDigit = false;
							break;
						}
					}

					if (isAllDigit)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				string email;
				while (true)
				{
					cin.clear();

					cout << "����� ����������� �����: ";
					cin >> email;

					bool isSign = false;
					bool isPoint = false;
					for (int i = 0; i < email.length(); i++)
					{
						if (email[i] == '@' && !isSign)
						{
							isSign = true;
						}

						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
						{
							isPoint = true;
						}
					}

					if (isSign && isPoint)
					{
						break;
					}

					system("CLS");
					cout << "������������ ��������. ��������� ����: " << endl;
				}

				system("CLS");

				User user(login, password, age, sex, phone, email);

				fs << user;

				cout << "�������� ���������� ������ ������������" << endl;

				break;
			}

			case 4:
			{
				userFileCreating();

				cout << "������� �������" << endl;

				break;
			}	

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void Menu::adminFileCreating()
{
	ofstream fout;

	fout.open("Admin.txt");

	if (!fout.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		Admin admin("admin", encryptDecrypt("admin"));
		fout << admin;
	}

	fout.close();
}

string Menu::encryptDecrypt(string toEncrypt)
{
	char key[3] = { 'K', 'C', 'Q' };
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}
