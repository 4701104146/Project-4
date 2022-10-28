#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define NUB 30
#define NUB2 NUB * 2
#define SPACE(i) for (int j = 0; j < i ; j++,(cout << ' '))
#define NEWLINE(i) for (int j = 0; j < i ; j++,(cout << '\n'))

#define WIDTH 1
#define TOP 5
#define BOTTOM 3
#define VER(i) for (int j = 0 ; j < i ; j++,(cout << '|'))
#define HOR(i) for (int j = 0; j < i ; j++,(cout << '_'))
#define SP1 13
#define SP2 23
#define SP3 33


class Item
{
    string _strCode = "";
    string _strName = "";
    string _strProductionPlace = "";
    string _strColor = "";
    int _iPrice = 0;
    string _strDayIn = "";
    int _iProducts = 0;


public:
    friend ifstream& operator >> (ifstream& is, Item& h);
    friend ofstream& operator << (ofstream& os,  Item& h);
    friend ostream& operator << (ostream& os, const Item& h);
    friend istream& operator >> (istream& is, Item& i);


    string getCode();
    int getNumber();
    string getName();
    void update(int products);
    void setCode(const string& code);
    string getProductionPlace();
    string getColor();
    string getDay();
    int getPrice();
    int getProduct();
};

