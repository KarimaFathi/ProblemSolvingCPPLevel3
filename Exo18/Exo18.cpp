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

void findIntersectedNumInMatrix(int arr1[3][3], int arr2[3][3], int resArr[9], short rows, short cols, short &IntersCounter) {
    IntersCounter = 0;
    int number;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            number = arr1[i][j];
            if (isNumberExistsInMatrix(arr2, 3, 3, number)) {
                resArr[IntersCounter] = number;
                IntersCounter++;
            }
        }
    }

}

void EliminateRedundantFromArray(int arr[9], int arrRes[9], short Length, short &finalLength) {
    finalLength = 0;
    bool isRedundant = false;
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j < Length; j++) {
            if ((i != j) && (arr[j] == arr[i])) {
                isRedundant = true;
                break;
            }
        }
        if (isRedundant == false) {
            arrRes[finalLength] = arr[i];
            finalLength++;
        }
    }
}

int main()
{
    int arr1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
    int arr2[3][3] = { {5, 80, 90}, {22, 77, 1}, {10, 8, 33} };
    int resArr[9];
    int resArrFinal[9];
    short resLength = 0;
    short interCounter = 0;


    cout << "Matrix 1:\n";
    printMatrix(arr1, 3, 3);

    cout << "Matrix 2:\n";
    printMatrix(arr2, 3, 3);

    findIntersectedNumInMatrix(arr1, arr2, resArr, 3, 3, interCounter);
    EliminateRedundantFromArray(resArr, resArrFinal, 9, resLength);

    cout << "\nIntersected Numbers are: \n";
    for (int i = 0; i < resLength + 1; i++) {
        cout << resArr[i] << "\t";
    }

    return 0;
}


