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

string joinString(string arr[100], short length, string delim) {
    string resultedString = "";
    for (short i = 0; i < length; i++) {
        arr[i] = arr[i] + delim;
        resultedString += arr[i];
    }
    return resultedString.substr(0, (resultedString.length() - delim.length()));
}


int main()
{
    vector<string> vString = { "Ali", "Ahmed", "Omar", "Othman" };
    string arr[100] = { "Ali", "Ahmed", "Omar", "Othman" };
    string delim = "###";
    cout << "String after joining delimiter to vector elements \n\n";
    cout << joinString(vString, delim) << endl << endl;
    cout << "String after joining delimiter to array elements \n\n";
    cout << joinString(arr, 4, delim) << endl << endl;


}