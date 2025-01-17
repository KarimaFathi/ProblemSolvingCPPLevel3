#include <iostream>
#include <string>
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

short countVowelsInString(string s1) {
    short counter = 0;
    for (short i = 0; i < s1.length(); i++) {
        if (isVowel(tolower(s1[i]))) {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string s1 = readString();
    cout << "Number of vowels is: " << countVowelsInString(s1);
}