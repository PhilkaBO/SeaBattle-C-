#pragma once
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Сoordinates
{
private:
    int x;
    int y;
public:
    int GetX();
    int GetY();
    void SetX(int x);
    void SetY(int y);
};
class OneShip
{
private:
    vector <Сoordinates> Position;
public:
    int GetSizeShip();
    void SetCoord(int x, int y);
    int GetX(int i);
    int GetY(int i);
    void PrintCoordShips();
    void ClearShip();
    void ClearPosIdex(int i);

};
class Ships
{
public:
    int ShipsSize();
    void ClearShip(int i);
    void Print();
    int CheckType(int size);
    int GetSizeShip(int i);
    int GetX(int i, int k);
    int GetY(int i, int k);
    void ClearPosition(int numship, int index);
    void SetCoord(int i, int x, int y);
};