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

short countCharInString(string s1, char c1, bool matchCase = true) {
    short charCounter = 0;
    for (short i = 0; i < s1.length(); i++) {
        if (matchCase) {
            if (s1[i] == c1) {
                charCounter++;
            }
        }
        else {
            if (tolower(s1[i]) == tolower(c1)) {
                charCounter++;
            }
        }
    }

    return charCounter;
}

int main()
{
    string s1 = readString();
    char c1 = readChar();
    cout << "\n\nletter '" << c1 << "' count : " << countCharInString(s1, c1) << endl;
    cout << "\nletter '" << (char)tolower(c1) << "' Or '" << (char)toupper(c1) << "' count : " << countCharInString(s1, c1, false) << endl;
    return 0;

}
