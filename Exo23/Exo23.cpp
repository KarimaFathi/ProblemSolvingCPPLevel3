#include <iostream>
#include <string>
using namespace std;




string readString() {
	string stringToManipulate;
	cout << "Please enter your string ?\n";
	getline(cin,stringToManipulate);
	return stringToManipulate;
}

void printFirstLetterOfStringWords(string stringToManipulate) {
	for (short i = 0; i < stringToManipulate.length(); i++) {
		if (i == 0) {
			cout << endl << stringToManipulate.at(i) << endl;
		}
		else if (stringToManipulate[i] == ' ' && stringToManipulate[i + 1] != ' ') {
				cout << stringToManipulate.at(i + 1) << endl;
		}
	}
}


//method 2
//void printFirstLetterOfStringWords(string stringToManipulate) {
//	bool isFirstLetter = true;
//	for (short i = 0; i < stringToManipulate.length(); i++) {
//		if (stringToManipulate[i] != ' ' && isFirstLetter) {
//			cout << stringToManipulate[i] << endl;
//		}
//		isFirstLetter = (stringToManipulate[i] == ' ' ? true : false);
//	}
//}



int main()
{
	printFirstLetterOfStringWords(readString());
}

