#include <iostream>
#include <iomanip>
#include "MyCustomString.h"
using namespace std;

int main()
{
    MyCustomString empty;
    cout << empty << endl;
    MyCustomString name = "Larry and Barry\nand Bolly";
    cout << name << endl;
    MyCustomString another_name = name;
    cout << another_name << endl;
    another_name = "My name";
    cout << another_name << endl;
    name = another_name;
    name=name + name+another_name;
    name = +name;
    cout << name << endl;
    name = name * 0;
    cout << name << endl;
    cin >> name;
    name *= 5;
    cout << name;
}

