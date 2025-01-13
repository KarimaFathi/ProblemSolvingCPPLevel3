#include <iostream>
#include <string>
using namespace std;

char readChar() {
    char c1;
    cout << "Please enter a character ?\n";
    cin >> c1;
    return c1;
}

char changeCase(char c1) {
    /*cout << "\nChar after inverting case: \n";
    if (c1 == tolower(c1)) {
        return toupper(c1);
    }
    else return tolower(c1);*/
    cout << "\nChar after inverting case: \n";
    return (isupper(c1) ? tolower(c1) : toupper(c1));

}


int main()
{
   
    cout << changeCase(readChar());
    system("pause > 0");
  
}

