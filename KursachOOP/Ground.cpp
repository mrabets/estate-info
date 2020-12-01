#include "Ground.h"

Ground::Ground() : Estate()
{
    this->landSquare = 0.0f;
}

Ground::Ground(float landSquare, string address, string owner, float price)
    : Estate(address, owner, price)
{
    this->landSquare = landSquare;
}

float Ground::getLandSquare()
{
    return landSquare;
}

void Ground::setLandSquare(float landSquare)
{
    this->landSquare = landSquare;
}

ostream& operator<<(ostream& out, Ground& obj)
{
    return out << dynamic_cast<Estate&>(obj) << setw(20) << obj.landSquare << endl;
}

istream& operator>>(istream& in, Ground& obj)
{
    in >> dynamic_cast<Estate&>(obj);

    cout << "������� ���������� �������: ";
    in >> obj.landSquare;

    return in;
}
