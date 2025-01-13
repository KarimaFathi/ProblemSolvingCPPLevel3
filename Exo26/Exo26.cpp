#include <iostream>
#include <string>
#include "myLib.h";
using namespace std;

string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

int main()
{
    string s1 = readString();
    cout << "\nString after upper:\n";
    cout << myLib::toUpperString(s1) << endl;
    cout << "\nString after lower:\n";
    cout << myLib::toLowerString(s1);
}

