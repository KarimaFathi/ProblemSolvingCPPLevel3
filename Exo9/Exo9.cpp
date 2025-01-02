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
            printf(" %0*d    ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

void printMiddleRow(int arr[3][3], short rows, short cols) {
    short middle = rows / 2;
            for (int j = 0; j < cols; j++) {
                printf(" %0*d    ", 2, arr[middle][j]);
            }
}

void printMiddleCol(int arr[3][3], short rows, short cols) {
    short middle = cols / 2;
    for (int i = 0; i < rows; i++) {
        printf(" %0*d    ", 2, arr[i][middle]);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    cout << "The following is a 3x3 matrix : \n";
    generateMatrixWithRandomNumbers(arr, 3, 3);
    printMatrix(arr, 3, 3);
    cout << "\nMiddle row of matrix is :\n";
    printMiddleRow(arr, 3, 3);
    cout << "\nMiddle col of matrix is :\n";
    printMiddleCol(arr, 3, 3);

}
