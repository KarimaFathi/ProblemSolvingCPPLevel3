#include <iostream>
using namespace std;


bool checkMatrixIdentity(int arr[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (i == j) {
                if (arr[i][j] != 1) {
                    return 0;
                }
            } 
            else if (i != j) {
                if (arr[i][j] != 0) {
                    return 0;
                }
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

void printResult(bool isIdentityMatrix) {
    if (isIdentityMatrix) {
        cout << "\nYes, it is an identity matrix!\n";
    }
    else cout << "\nNo, it isn't an identity matrix!\n";
}


int main()
{
    int arr[3][3] = { {1,0,0} , {0,1,0} , {0,0,1} };
    printMatrix(arr, 3, 3);
    printResult(checkMatrixIdentity(arr, 3, 3));
    return 0;
}


