#include <iostream>
#include <string>
using namespace std;

char readChar() {
    char c1;
    cout << "Please enter a character ?\n";
    cin >> c1;
    return c1;
}

bool isVowel(char c1) {
    return ((c1 == 'a') || (c1 == 'e') || (c1 == 'i') || (c1 == 'o') || (c1 == 'u'));
}


int main()
{
    char c1 = readChar();
    if (isVowel(tolower(c1))) {
        cout << "\nYes " << c1 << " is a vowel.\n";
    }
    else cout << "\nNo " << c1 << " is not a vowel.\n";
}

