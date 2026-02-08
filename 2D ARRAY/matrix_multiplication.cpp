
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // You can adjust this based on your needs

// Function to multiply two matrices
void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowsA >> colsA;

    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible. Columns of matrix A must be equal to rows of matrix B." << endl;
        return 1;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> matrixB[i][j];
        }
    }

    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);

    cout << "Resultant matrix (A * B):" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}