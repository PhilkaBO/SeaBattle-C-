#include "Ships.h"

int Сoordinates::GetX()
{
	return x;
}

int Сoordinates::GetY()
{
	return y;
}

void Сoordinates::SetX(int x)
{
	this->x = x;
}

void Сoordinates::SetY(int y)
{
	this->y = y;
}
int OneShip::GetSizeShip()
{
	return Position.size();
}

void OneShip::SetCoord(int x, int y)
{
	Сoordinates coord;
	coord.SetX(x);
	coord.SetY(y);
	Position.push_back(coord);
}

int OneShip::GetX(int i)
{
	return Position[i].GetX();
}

int OneShip::GetY(int i)
{
	return Position[i].GetY();
}

void OneShip::PrintCoordShips()
{
	for (int i = 0; i < GetSizeShip(); i++)
	{
		cout << Position[i].GetX() << " " << Position[i].GetY() << endl;
	}
}

void OneShip::ClearShip()
{
    Position.clear();
}

void OneShip::ClearPosIdex(int i)
{
    Position.erase(Position.begin() + i);
}

int Ships::GetX(int i, int k)
{
    return ships[i].GetX(k);
}

int Ships::GetY(int i, int k)
{
    return ships[i].GetY(k);
}
void Ships::SetCoord(int i, int x, int y)
{
    if (FindCoord(i, x, y)) 
    {
        ships[i].SetCoord(x, y);
    }
    else {
        cout << "lox";
    }
}
void Ships::ClearPosition(int numship, int index)
{
    ships[numship].ClearPosIdex(index);
}
int Ships::GetSizeShip(int i)
{
    return ships[i].GetSizeShip();
}
int Ships::CheckType(int size)
{
    int result = 0;
    for (int i = 0; i < 10; i++) {
        if (size == ships[i].GetSizeShip()) 
        {
            result++;
        }
    }
    return result;
}