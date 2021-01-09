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