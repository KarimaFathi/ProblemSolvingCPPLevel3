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




string invertStringAllLettersCase(string s1) {
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != ' ') {
			s1[i] = tolower(s1[i]);
		}
	}
	return s1;
}

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

string replaceString(string s1, string wordToReplace, string newWord, bool matchCase) {
	string s2 = "";
	vector<string> vString = splitString(s1, " ");
	vector<string>::iterator iter;
	for (iter = vString.begin(); iter != vString.end(); iter++) {
		if (matchCase) {
			if (*iter == wordToReplace) {
				s2 += newWord + " ";
			}
			else s2 += *iter + " ";
		}
		else {
			*iter = invertStringAllLettersCase(*iter);
			wordToReplace = invertStringAllLettersCase(wordToReplace);
			if (*iter == wordToReplace) {
				s2 += newWord + " ";
			}
			else s2 += *iter + " ";
			
		}
	}
	return s2;
}





int main()
{
	string s1 = readString();
	cout << endl << "Replace with match case :" << endl << replaceString(s1, "Morocco", "Jordan", true) << endl;
	cout << endl << "Replace without match case :" << endl << replaceString(s1, "Morocco", "Jordan", false);

}