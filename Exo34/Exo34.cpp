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

bool isVowel(char c1) {
    return ((c1 == 'a') || (c1 == 'e') || (c1 == 'i') || (c1 == 'o') || (c1 == 'u'));
}

void addVowelsInString(string s1, vector<char> &charInString) {
    for (short i = 0; i < s1.length(); i++) {
        if (isVowel(tolower(s1[i]))) {
            charInString.push_back(s1[i]);
        }
    }
}

void printVowelsInString(vector<char> charInString) {
    for (char& i : charInString) {
        cout << i << "\t";
    }
}




int main()
{
    string s1 = readString();
    vector<char> charInString;
    addVowelsInString(s1, charInString);
    printVowelsInString(charInString);
}

