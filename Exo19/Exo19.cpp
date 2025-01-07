#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int arr[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}


int findMaxInMatrix(int arr[3][3], short rows, short cols) {
    int maxNum = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxNum) {
                maxNum = arr[i][j];
            }
        }
    }
    return maxNum;
}

int findMinInMatrix(int arr[3][3], short rows, short cols) {
    int minNum = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < minNum) {
                minNum = arr[i][j];
            }
        }
    }
    return minNum;
}



int main()
{
    int arr[3][3] = { {77, 5, 12}, {22, 20, 6}, {14, 3, 9} };
    cout << "Matrix 1:\n";
    printMatrix(arr, 3, 3);
    cout << "\nMinimum number is: " << findMinInMatrix(arr, 3, 3);
    cout << "\nMaximum number is: " << findMaxInMatrix(arr, 3, 3);
   
    return 0;

}

