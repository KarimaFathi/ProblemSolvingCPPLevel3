// Exo24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string readString() {
	string stringToManipulate;
	cout << "Please enter your string ?\n";
	getline(cin, stringToManipulate);
	return stringToManipulate;
}


string capitalizeFirstLetter(string s) {
	bool isFirstLetter = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ' && isFirstLetter) {
			s[i] = toupper(s[i]);
		}
		isFirstLetter = (s[i] == ' ' ? true : false);
	}
	return s;
}


int main()
{
	cout << endl << capitalizeFirstLetter(readString());
}

