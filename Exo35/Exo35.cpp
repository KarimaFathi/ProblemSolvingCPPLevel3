#include <iostream>
#include <string>
using namespace std;

string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

// my method
//void printWordByWord(string &s1) {
//    string concat = "";
//    for (int i = 0; i < s1.length(); i++) {
//        if (s1[i] != ' ') {
//            concat += s1[i];
//        }
//        else if ( s1[i - 1] != ' ') {
//            cout << endl << concat;
//            concat = "";
//        }
//    }
//    cout << endl << concat;
//}

void printWordByWord(string& s1) {
    string delim = " ";
    short pos;
    string word;
    cout << "\nYour string words are : \n\n";
    while ((pos = s1.find(delim)) != std::string::npos) {
        word = s1.substr(0, pos);
        if (word != "") {
            cout << word << endl;
            s1.erase(0, pos + delim.length());
        }
    }
    if (s1 != "") {
        cout << s1 << endl;
    }
}

int main()
{
    string s1 = readString();
    printWordByWord(s1);

    return 0;
}
