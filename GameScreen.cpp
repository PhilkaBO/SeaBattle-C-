void GameScreen::IsKill(int x, int y, Ships& Ship)
{

    bool iskill = true;
    int index = Ship.FindPos(x, y);

    for (int i = 0; i < Ship.GetSizeShip(index); i++)
    {
        if (EnemyField[Ship.GetX(index, i)][Ship.GetY(index, i)] == 1)
        {
            iskill = false;
        }
    }
  
    if (iskill)
    {
        for (int i = 0; i < Ship.GetSizeShip(index); i++)
        {
            EnemyField[Ship.GetX(index, i)][Ship.GetY(index, i)] = 3;
        }
    }
}

int GameScreen::II(Ships& myShip)
{
    int temp;
    int x, y = 0;
    int randomvalue;
    if (ModeII == -1)//режим поиска корабля
    {
        randomvalue = AvPos[rand() % AvPos.size()];
        x = randomvalue % 10;
        y = randomvalue / 10;

        direct = -1;//направление не выбрано

        DeleteVec(AvPos, randomvalue);

        if (myShip.FindPos(x, y) != -1)//Если попали
        {
            ModeII = randomvalue;//режим выбран
            SizeModeII = myShip.GetSizeShip(myShip.FindPos(x, y)) - 1;
            if (SizeModeII == 0)
            {
                ClearAround(myShip.FindPos(x, y), myShip);
                ModeII = -1;
                lasthit = -1;
                direct = -1;
                return randomvalue;
            }
            else {
                lasthit = ModeII;
                return lasthit;
            }
        }
        else//Если мимо
        {
            return randomvalue;
        }

    }
    else//корабль найден первое попадание
    {
        if (direct == -1)//направление не выбрано
        {
            RenewAvVec();//вектор направлений
            randomvalue = AvVec[rand() % AvVec.size()];

            x = randomvalue % 10;
            y = randomvalue / 10;

            DeleteVec(AvPos, randomvalue);

            if (myShip.FindPos(x, y) != -1)//если попал
            {
                SizeModeII--;
                if (SizeModeII == 0)
                {
                    ClearAround(myShip.FindPos(x, y), myShip);
                    ModeII = -1;
                    return randomvalue;
                }
                else
                {
                    direct = ChVect(randomvalue);
                    lasthit = randomvalue;
                    return randomvalue;
                }
            }
            else//Если мимо
            {
                //RenewAvVec();
                //DeleteVec(AvVec, randomvalue);
                direct = -1;
                return randomvalue;
            }

        }
        else if (direct == 0)//лево
        {
            lasthit = lasthit - 1;
            if (lasthit % 10 != 9)
            {
                if (FindVector(AvPos, lasthit))
                {
                    DeleteVec(AvPos, lasthit);
                    x = lasthit % 10;
                    y = lasthit / 10;
                    if (myShip.FindPos(x, y) != -1)
                    {
                        SizeModeII--;
                        if (SizeModeII == 0)
                        {
                            ClearAround(myShip.FindPos(x, y), myShip);
                            direct = -1;
                            ModeII = -1;
                            return lasthit;
                        }
                        else
                        {
                            return lasthit;
                        }
                    }
                    else
                    {
                        direct = 2;
                        temp = lasthit;
                        lasthit = ModeII;
                        return temp;
                    }
                }
                else
                {
                    direct = 2;
                    lasthit = ModeII;
                    II(myShip);
                }
            }
            else
            {
                direct = 2;
                lasthit = ModeII;
                II(myShip);
            }
        }
        else if (direct == 1)//Вверх
        {
            lasthit = lasthit - 10;

            if (FindVector(AvPos, lasthit))
            {
                DeleteVec(AvPos, lasthit);
                x = lasthit % 10;
                y = lasthit / 10;
                if (myShip.FindPos(x, y) != -1)
                {
                    SizeModeII--;
                    if (SizeModeII == 0)
                    {
                        ClearAround(myShip.FindPos(x, y), myShip);
                        direct = -1;
                        ModeII = -1;
                        return lasthit;
                    }
                    else
                    {
                        return lasthit;
                    }
                }
                else
                {
                    direct = 3;
                    temp = lasthit;
                    lasthit = ModeII;
                    return temp;
                }
            }
            else
            {
                direct = 3;
                lasthit = ModeII;
                II(myShip);
            }
        }
        else if (direct == 2)//Вправо
        {
            lasthit = lasthit + 1;
            if (lasthit % 10 != 0)
            {
                if (FindVector(AvPos, lasthit))
                {
                    DeleteVec(AvPos, lasthit);
                    x = lasthit % 10;
                    y = lasthit / 10;
                    if (myShip.FindPos(x, y) != -1)
                    {
                        SizeModeII--;
                        if (SizeModeII == 0)
                        {
                            ClearAround(myShip.FindPos(x, y), myShip);
                            direct = -1;
                            ModeII = -1;
                            return lasthit;
                        }
                        else
                        {
                            return lasthit;
                        }
                    }
                    else
                    {
                        direct = 0;
                        temp = lasthit;
                        lasthit = ModeII;
                        return temp;
                    }
                }
                else
                {
                    direct = 0;
                    lasthit = ModeII;
                    II(myShip);
                }
            }
            else
            {
                direct = 0;
                lasthit = ModeII;
                II(myShip);
            }
        }
        else if (direct == 3)//Вниз
        {
            lasthit = lasthit + 10;
            if (FindVector(AvPos, lasthit))
            {
                DeleteVec(AvPos, lasthit);
                x = lasthit % 10;
                y = lasthit / 10;
                if (myShip.FindPos(x, y) != -1)
                {
                    SizeModeII--;
                    if (SizeModeII == 0)
                    {
                        ClearAround(myShip.FindPos(x, y), myShip);
                        direct = -1;
                        ModeII = -1;
                        return lasthit;
                    }
                    else
                    {
                        return lasthit;
                    }
                }
                else
                {
                    direct = 1;
                    temp = lasthit;
                    lasthit = ModeII;
                    return temp;
                }
            }
            else
            {
                direct = 1;
                lasthit = ModeII;
                II(myShip);
            }
        }
    }
}

void GameScreen::DeleteVec(vector<int>& Vect, int value)
{
    for (int i = 0; i < Vect.size(); i++)
    {
        if (value == Vect[i])
        {
            Vect.erase(Vect.begin() + i);
        }
    }
}

void GameScreen::RenewAvVec()
{
    AvVec.clear();

    int right = ModeII + 1;
    int left = ModeII - 1;
    int up = ModeII - 10;
    int down = ModeII + 10;

    for (int i = 0; i < AvPos.size(); i++)
    {
        if (right == AvPos[i] && ModeII % 10 != 9)
        {
            AvVec.push_back(right);
        }
        if (left == AvPos[i] && ModeII % 10 != 0)
        {
            AvVec.push_back(left);
        }
        if (up == AvPos[i])
        {
            AvVec.push_back(up);
        }
        if (down == AvPos[i])
        {
            AvVec.push_back(down);
        }
    }
}

int GameScreen::ChVect(int RandomHit)
{
    switch (ModeII - RandomHit)
    {
    case (1):
        return 0;
    case (10):
        return 1;
    case (-1):
        return 2 ;
    case (-10):
        return 3;
    default:
        return -1;
    }
}

bool GameScreen::FindVector(vector<int>& Vect, int value)
{
    for (int i = 0; i < Vect.size(); i++)
    {
        if (value == Vect[i])
        {
            return true;
        }
    }
    return false;
}

void GameScreen::ClearAround(int index, Ships& myShip)
{
    int n;
    for (int i = 0; i < myShip.GetSizeShip(index); i++)
    {
        n = myShip.GetY(index, i) * 10 + myShip.GetX(index, i);
        
        if (n % 10 != 9)
        {
            DeleteVec(AvPos, n - 9);
            DeleteVec(AvPos, n + 1);
            DeleteVec(AvPos, n + 11);
        }
        if (n % 10 != 0)
        {
            DeleteVec(AvPos, n + 9);
            DeleteVec(AvPos, n - 1);
            DeleteVec(AvPos, n - 11);
        }
        DeleteVec(AvPos, n - 10);
        DeleteVec(AvPos, n + 10);
    }
}
