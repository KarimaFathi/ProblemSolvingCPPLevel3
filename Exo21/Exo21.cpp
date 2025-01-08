#include <iostream>
using namespace std;


void printFibonacci(short length) {
    int prev1 = 1;
    int prev2 = 0;
    int fiboNumber = 0;
    cout << "1     ";
    for (short i = 2; i <= length; i++) {
        fiboNumber = prev1 + prev2;
        cout << fiboNumber << "     ";
        prev2 = prev1;
        prev1 = fiboNumber;
      
   }
}



int main()
{
   printFibonacci(10);
   cout << endl;
   return 0;
}


