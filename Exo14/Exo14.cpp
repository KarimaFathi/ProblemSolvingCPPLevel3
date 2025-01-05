#include <iostream>
using namespace std;


bool isScalarMatrix(int arr[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (i == j && arr[i][j] != arr[0][0]){
                return 0;
            } 
            else if (i != j && arr[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
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

void printResult(bool isScalarMatrix) {
    if (isScalarMatrix) {
        cout << "\nYes, it is a scalar matrix.\n";
    }
    else cout << "\nNo, it isn't a scalar matrix.\n";
}


int main()
{
    int arr[3][3] = { {9,0,0} , {0,9,0} , {0,0,9} };
    printMatrix(arr, 3, 3);
    printResult(isScalarMatrix(arr, 3, 3));
    return 0;
}


