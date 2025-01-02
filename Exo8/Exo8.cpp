#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int random(int from, int to) {
    return rand() % (to - from + 1) + from;
}



void generateMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = random(1, 100);
        }
    }
}


void printMatrix(int arr[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void multiplyTwoMatrices(int arr1[3][3], int arr2[3][3], int mulArr[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mulArr[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3], mulArr[3][3];
    cout << "The following is a 3x3 matrix : \n";
    generateMatrixWithRandomNumbers(arr1, 3, 3);
    generateMatrixWithRandomNumbers(arr2, 3, 3);
    cout << "\nMatrix 1: \n";
    printMatrix(arr1, 3, 3);
    cout << "\nMatrix 2: \n";
    printMatrix(arr2, 3, 3);
    multiplyTwoMatrices(arr1, arr2, mulArr, 3, 3);
    cout << "\nResults : \n";
    printMatrix(mulArr, 3, 3);

}