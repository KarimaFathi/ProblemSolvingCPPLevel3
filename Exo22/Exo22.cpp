#include <iostream>
using namespace std;


void recursiveFibonacci(short length, short prev1, short prev2) {
	int fibonacciNum = 0;
	if (length > 0) {
		fibonacciNum = prev1 + prev2;
		cout << fibonacciNum << "     ";
		prev2 = prev1;
		prev1 = fibonacciNum;
		length--;
		recursiveFibonacci(length, prev1, prev2);
	}
}


int main()
{
    recursiveFibonacci(10, 1, 0);
    cout << endl;
    return 0;
}

