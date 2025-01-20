#include <iostream>
#include <string>
using namespace std;

string readString() {
	string s1;
	cout << "Please enter your string ?\n";
	getline(cin, s1);
	return s1;
}
//method 1
//string trimLeft(string s1) {
//	for (short i = 0; i < s1.length(); i++) {
//		if (s1[i] == ' ') {
//			s1.erase(i, 1);
//			i--;
//		} 
//		else if (s1[i] != ' ' && i + 1 < s1.length() && s1[i + 1] == ' ') {
//			break;
//		}
//
//	}
//	return s1;
//}
//
//string trimRight(string s1) {
//	for (short i = s1.length(); i > 0; i--) {
//		if (s1[i] == ' ') {
//			s1.erase(i, 1);
//			i++;
//		}
//		else if (s1[i] != ' ' && i - 1 > 0 && s1[i - 1] == ' ') {
//			break;
//		}
//	}
//	return s1;
//}



string trimLeft(string s1) {
	for (short i = 0; i < s1.length(); i++) {
		if (s1[i] != ' ') {
			return s1.substr(i, s1.length() - i);
		}
	}
	return s1;
}

string trimRight(string s1) {
	for (short i = s1.length(); i > 0; i--) {
		if (s1[i] != ' ') {
			return s1.substr(0, i + 1);
		}
	}
	return s1;
}


int main()
{
	string s1 = readString();
	cout << "String    : " << s1 << endl << endl;
	cout << "Trim Left : " << trimLeft(s1) << endl;
	cout << "Trim Right: " << trimRight(s1) << endl;
	cout << "Trim      : " << trimRight(trimLeft(s1));
	
}
