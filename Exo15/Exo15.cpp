#include <iostream>
using namespace std;


int getNumber() {
    int number;
    cout << "Enter the number to count in matrix ?\n";
    cin >> number;
    return number;

}


short CountNumFrequencyInMatrix(int arr[3][3], short rows, short cols, int num) {
    short counter = 0;
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (arr[i][j] == num) {
                counter++;
            }
        }
    }
    return counter;
}

void printMatrix(int arr[3][3], short rows, short cols) {
    cout << "Matrix: \n";
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            printf("  %d     ", arr[i][j]);
        }
        cout << endl;
    }
}



int main()
{
    int arr[3][3] = { {9,1,12} , {0,9,1} , {0,9,9} };
    int number = getNumber();
    printMatrix(arr, 3, 3);
    cout << "\nNumber " << number << " count in matrix is " << CountNumFrequencyInMatrix(arr, 3, 3, number);
    return 0;
}

