#include <iostream>
#include <string>
using namespace std;

string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

char readChar() {
    char c1;
    cout << "\nPlease enter a character ?\n";
    cin >> c1;
    return c1;
}

short countCharInString(string s1, char c1) {
    short charCounter = 0;
    for (short i = 0; i < s1.length(); i++) {
        if (s1[i] == c1) {
            charCounter++;
        }
    }
    return charCounter;
}



int main()
{
    string s1 = readString();
    char c1 = readChar();
    cout << "\nletter '" << c1 << "' count : " << countCharInString(s1, c1) << endl;
    return 0;

}

