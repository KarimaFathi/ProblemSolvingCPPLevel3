#include <iostream>
#include <string>
using namespace std;

struct stCounterCase {
    short stringLength = 0;
    short capitalCounter = 0;
    short lowerCounter = 0;
};

string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

stCounterCase countLetterCase(string s1, stCounterCase &counterCase) {
    counterCase.stringLength = s1.length();
    for (short i = 0; i < s1.length(); i++) {
        if (isupper(s1[i])) {
            counterCase.capitalCounter++;
        }
        else if (islower(s1[i])) {
            counterCase.lowerCounter++;
        }
        else continue;
    }
    return counterCase;
}


void printResult(stCounterCase counterCase) {
    cout << "\nStringLength = " << counterCase.stringLength << endl;
    cout << "Capital Letters Count = " << counterCase.capitalCounter << endl;
    cout << "Small Letters Count = " << counterCase.lowerCounter << endl;
}


int main()
{
    string s1 = readString();
    stCounterCase counterCase;
    countLetterCase(s1, counterCase);
    printResult(counterCase);

}
