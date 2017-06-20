/*
 * test.cpp
 * Copyright (C) 2017 Hans <Hans@Hans-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

void circle(int i)
{
    for (int k = 0; k < 10000000; k++)
    {
        if (k == 10000000 - 1)
            cout << i << endl;
    }
}
    
int main(int argc, char* argv[])
{

    for (int i = 0; i < 100; i++)
    {
        circle(i);
    }
   
    return 0;
}
