#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printMatrix(int arr[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int reverseNumber(int num) {
    int rest;
    int  remainder;
    int result = 0;
    do {
        rest = num / 10;
        remainder = num % 10;
        result = result * 10 + remainder;
        num = rest;
    } while (rest > 0);
    return result;
}

bool isPalindromeNumber(int num) {
    return num == reverseNumber(num);
}


string concatenateRow(int arr[3][3], short row, short cols) {
    string concatRow;
    for (int i = 0; i < cols; i++) {
        concatRow += to_string(arr[row][i]);
    }
    return concatRow;
}

bool isMatrixPalindrome(int arr[3][3], short rows, short cols) {
    short palindromeRowsCounter = 0;
    
    for (int i = 0; i < cols; i++) {
            if (isPalindromeNumber(stoi(concatenateRow(arr, i, cols)))) {
                palindromeRowsCounter++;

        }
    }
    if (palindromeRowsCounter == rows) {
        return true;
    }
    else return false;
}

void printResult(bool isPalindrome) {
    if (isPalindrome == true) {
        cout << "Yes, matrix is palindrome.\n";
    }
    else {
        cout << "No, matrix is not palindrome.\n";
    }
}



int main()
{
    int arr[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7} };
    cout << "Matrix 1:\n";
    printMatrix(arr, 3, 3);
    printResult(isMatrixPalindrome(arr, 3, 3));

    return 0;

}


