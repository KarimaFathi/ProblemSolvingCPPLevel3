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

int colSum(int arr[3][3], short colNumber, short rows) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += arr[i][colNumber];
    }
    return sum;
}

void sumMatrixColsInArr(int arr[3][3], short rows, int arrSum[3], short cols) {
    for (int i = 0; i < cols; i++) {
        arrSum[i] = colSum(arr, i, rows);
    }
}

void printColsSumArray(int arr[3], short length) {
    cout << "\nThe following are the sum of each column in the matrix: \n";
    for (int i = 0; i < length; i++) {
        cout << "Column " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrSum[3];
    cout << "The following is a 3x3 matrix : \n";
    generateMatrixWithRandomNumbers(arr, 3, 3);
    printMatrix(arr, 3, 3);
    sumMatrixColsInArr(arr, 3, arrSum, 3);
    printColsSumArray(arrSum, 3);
}


