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

void printResult(vector<string> vString) {
	cout << "Tokens = " << vString.size() << endl;
	for (string& i : vString) {
		cout << i << endl;
	}
	
}

int main()
{
	string str = readString();
	printResult(splitString(str, " "));
   
}

