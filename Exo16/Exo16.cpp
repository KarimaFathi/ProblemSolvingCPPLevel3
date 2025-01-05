#include <iostream>
using namespace std;


bool isMatrixSparse(int arr[3][3], short rows, short cols) {
    short zeroCounter = 0, numberCounter = 0;
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                zeroCounter++;
            }
            else numberCounter++;
        }
    }

    if (zeroCounter >= numberCounter) {
        return 1;
    }
    else return 0;
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

void printResult(bool isIdentityMatrix) {
    if (isIdentityMatrix) {
        cout << "\nYes, it is sparse.\n";
    }
    else cout << "\nNo, it isn't sparse.\n";
}


int main()
{
    int arr[3][3] = { {5,4,6} , {3,7,0} , {0,0,2} };
    printMatrix(arr, 3, 3);
    printResult(isMatrixSparse(arr, 3, 3));
    return 0;
}




