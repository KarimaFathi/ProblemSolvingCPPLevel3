#include <iostream>
#include <string>
using namespace std;





string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

char changeCase(char c1) {
    return (isupper(c1) ? tolower(c1) : toupper(c1));

}


string invertStringAllLettersCase(string s1) {
    cout << "\nstring after inverting all its letters case : \n";
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != ' ') {
            s1[i] = changeCase(s1[i]);
        }
    }
    return s1;
}

int main()
{
    cout << invertStringAllLettersCase(readString());
}

