#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int random(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void generateMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            arr[i][j] = random(1, 100);
        }
    }
}

void printMatrix(int arr[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int sumMatrix(int arr[3][3], short rows, short cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}



int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3];
    generateMatrixWithRandomNumbers(arr1, 3, 3);
    generateMatrixWithRandomNumbers(arr2, 3, 3);
    cout << "Matrix 1 : \n";
    printMatrix(arr1, 3, 3);
    cout << "\nMatrix 2 : \n";
    printMatrix(arr2, 3, 3);
    if (sumMatrix(arr1, 3, 3) != sumMatrix(arr2, 3, 3)) {
        cout << "\nNo: matrices are not equal.\n";
    }
    else {
        cout << "\nYes: matrices are equal.\n";
    }
}


