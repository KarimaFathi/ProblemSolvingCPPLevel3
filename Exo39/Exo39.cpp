#include <iostream>
#include <vector>
#include <string>
using namespace std;

string joinString(vector<string> vString, string delim) {
    string resultedString = "";
    for (string& str : vString) {
        str = str + delim;
        resultedString += str;
    }
    return resultedString.substr(0, (resultedString.length() - delim.length()));
}

int main()
{
    vector<string> vString = { "Ali", "Ahmed", "Omar", "Othman" };
    string delim = "###";
    cout << "String after joining delimiter to vector elements \n\n";
    cout << joinString(vString, delim) << endl;
}
