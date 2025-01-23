#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

string removePunctuations(string &s1) {
    for (int i = 0; i < s1.length(); i++) {
        if (ispunct(s1[i])) {
            s1.erase(i, 1);
            i--;
        }
    }
    return s1;

}


int main()
{
    string s1 = readString();
    cout << endl << removePunctuations(s1) << endl;

}
