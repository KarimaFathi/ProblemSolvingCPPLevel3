#include <iostream>
#include <iomanip>
using namespace std;

void fillMatrixWithOrderedNum(int arr[3][3], short rows, short cols) {
    short length = 0;
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            length++;
            arr[i][j] = length;
            
        }
    }
}

void printMatrix(int arr[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3];
    fillMatrixWithOrderedNum(arr, 3, 3);
    cout << "The following is 3x3 ordered matrix: \n";
    printMatrix(arr, 3, 3);
}


