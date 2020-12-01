#include "Estate.h"

Estate::Estate()
{
	this->address = "None";
	this->owner = "None";
	this->price = 0;
}

Estate::Estate(string address, string owner, float price)
{
	this->address = address;
	this->owner = owner;
	this->price = price;
}

string Estate::getAddress()
{
	return address;
}

string Estate::getOwner()
{
	return owner;
}

float Estate::getPrice()
{
	return price;
}

void Estate::setAddress(string address)
{
	this->address = address;
}

void Estate::setOwner(string owner)
{
	this->owner = owner;
}

void Estate::setPrice(float price)
{
	this->price = price;
}

ostream& operator<<(ostream& out, Estate& obj)
{
	return out << setw(20) << obj.address << setw(20) << obj.owner << setw(10) << obj.price;
}

istream& operator>>(istream& in, Estate& obj)
{
	cout << "�����: ";
	rewind stdin;
	getline(in, obj.address);

	cout << "��������: ";
	rewind stdin;
	getline(in, obj.owner);
	

	cout << "����: ";
	in >> obj.price;

	return in;
}
