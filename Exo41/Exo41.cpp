#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString() {
	string s1;
	cout << "Please enter your string ?\n";
	getline(cin, s1);
	return s1;
}


//method 1
//void splitString(string arr1[100], short &counter, string s1, string delim) {
//	short pos;
//	string word;
//	counter = 0;
//	while ((pos = s1.find(delim)) != s1.npos) {
//		word = s1.substr(0, pos);
//		if (word != "") {
//			arr1[counter] = word;
//			counter++;
//			s1.erase(0, pos + delim.length());
//		}
//	}
//	if (s1 != "") {
//		arr1[counter] = s1;
//	}
//}
//void printResult(string arr1[100], short counter, string delim) {
//	cout << "String after reversing words : "  << endl;
//	for (short i = counter; i >= 0; i--) {
//		cout <<arr1[i] << delim;
//	}
//
//}


//method 2
vector<string> splitString(string s1, string delim) {
	short pos;
	vector<string> vString;
	string word;
	while ((pos = s1.find(delim)) != s1.npos) {
		word = s1.substr(0, pos);
		if (word != "") {
			vString.push_back(word);
			s1.erase(0, pos + delim.length());
		}
	}
	if (s1 != "") {
		vString.push_back(s1);
	}
	return vString;
}


string reverseWordInString(string s1) {
	string s2 = "";
	vector<string> vString = splitString(s1, " ");
	vector <string>::iterator iter = vString.end();
	while (iter != vString.begin()) {
		iter--;
		s2 += *iter + " ";
	}
	return s2;
}



int main()
{
	string s1 = readString();
	cout << endl << "string reversed : " << endl << reverseWordInString(s1);
	/*string arr[100];
	short counter;
	string delim = " ";
	splitString(arr, counter, s1, delim);
	printResult(arr, counter, delim);*/

}

