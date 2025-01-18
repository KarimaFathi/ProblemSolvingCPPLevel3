#include <iostream>
#include <string>
using namespace std;

string readString() {
    string s1;
    cout << "Please enter your string ?\n";
    getline(cin, s1);
    return s1;
}

short printWordByWord(string s1) {
    string concat = "";
    short counter = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != ' ') {
            concat += s1[i];
        }
        else if ( s1[i - 1] != ' ') {
            counter++;
            concat = "";
        }
    }
    if (concat != "") {
        counter++;
    }
    return counter;
}

short countWordsInString(string s1) {
    string delim = " ";
    short pos;
    string word;
    short counter = 0;
    cout << "\nThe number of words in your string is : ";
    while ((pos = s1.find(delim)) != std::string::npos) {
        word = s1.substr(0, pos);
        if (word != "") {
            counter++;
            s1.erase(0, pos + delim.length());
        }
    }
    if (s1 != "") {
        counter++;
    }
    return counter;
}

int main()
{
    string s1 = readString();
    //cout << countWordsInString(s1);
    cout << printWordByWord(s1);

    return 0;
}
