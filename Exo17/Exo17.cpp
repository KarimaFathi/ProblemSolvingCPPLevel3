#include <iostream>
using namespace std;


int getNumber() {
    int number;
    cout << "Please enter the number to look for in matrix ?\n";
    cin >> number;
    return number;

}

bool isNumberExistsInMatrix(int arr[3][3], short rows, short cols, int number) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (arr[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

void printMatrix(int arr[3][3], short rows, short cols) {
    cout << "Matrix: \n";
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            printf("  %0.2d     ", arr[i][j]);
        }
        cout << endl;
    }
}

void printResult(bool isNumInMatrix) {
    if (isNumInMatrix == false) {
        cout << "\nNo, it isn't there!\n";
    }
    else cout << "\nYes, it is there!\n";
}


int main()
{
    int num = getNumber();
    int arr[3][3] = { {10,67,33} , {50,12,3} , {86,99,41} };
    printMatrix(arr, 3, 3);
    printResult(isNumberExistsInMatrix(arr, 3, 3, num));
    return 0;
}

