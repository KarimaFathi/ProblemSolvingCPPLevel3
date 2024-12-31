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
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    cout << "The following is a 3x3 matrix : \n";
    generateMatrixWithRandomNumbers(arr, 3, 3);
    printMatrix(arr, 3, 3);
    
}
