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
//METHOD 1
//vector<string> splitString(string s1, string delim) {
//	short pos;
//	vector<string> vString;
//	string word;
//	while ((pos = s1.find(delim)) != s1.npos) {
//		word = s1.substr(0, pos);
//		if (word != "") {
//			vString.push_back(word);
//			s1.erase(0, pos + delim.length());
//		}
//	}
//	if (s1 != "") {
//		vString.push_back(s1);
//	}
//	return vString;
//}
//
//string replaceString(string s1, string wordToReplace, string newWord) {
//	string s2 = "";
//	vector<string> vString = splitString(s1, " ");
//	vector<string>::iterator iter;
//	for (iter = vString.begin(); iter != vString.end(); iter++) {
//		if (*iter == wordToReplace) {
//			s2 += newWord + " ";
//		}
//		else s2 += *iter + " ";
//	}
//	return s2;
//}


//METHOD 2
string replaceString(string s1, string wordToReplace, string newWord) {
	short pos = s1.find(wordToReplace);
	while (pos != std::string::npos) {
		s1 = s1.replace(pos, wordToReplace.length(), newWord);
		pos = s1.find(wordToReplace);
	}
	return s1;
}


int main()
{
	string s1 = readString();
	cout << endl << "String after replacing :" << endl << replaceString(s1, "Morocco", "Jordan");
    
}


