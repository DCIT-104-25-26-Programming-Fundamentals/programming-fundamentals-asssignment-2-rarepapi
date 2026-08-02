// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// ---------------------------------------------------------------------------
// Utility functions: read and print a matrix
// ---------------------------------------------------------------------------

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter " << name << " element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// ---------------------------------------------------------------------------
// PART A — Transpose
// ---------------------------------------------------------------------------

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// ---------------------------------------------------------------------------
// PART B — Addition
// ---------------------------------------------------------------------------

void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// ---------------------------------------------------------------------------
// PART C — Multiplication
// ---------------------------------------------------------------------------

void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------

int main() {
    int matA[MAX_SIZE][MAX_SIZE];
    int matB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

     // ---------------- PART A: Transpose ----------------
    cout << "=== PART A: Transpose a Matrix ===" << endl;

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    readMatrix(matA, rows, cols, "matrix");

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, rows, cols);

    transposeMatrix(matA, rows, cols, result);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows); // note: dimensions swap

    // ---------------- PART B: Addition ----------------
    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    cout << "(Using the same dimensions as above: " << rows << " x " << cols << ")" << endl;

    cout << "\nEnter values for Matrix A:" << endl;
    readMatrix(matA, rows, cols, "A");

    cout << "\nEnter values for Matrix B (same size as A):" << endl;
    readMatrix(matB, rows, cols, "B");

    addMatrices(matA, matB, rows, cols, result);

    cout << "\nMatrix A:" << endl;
    printMatrix(matA, rows, cols);
    cout << "\nMatrix B:" << endl;
    printMatrix(matB, rows, cols);
    cout << "\nSum (A + B):" << endl;
    printMatrix(result, rows, cols);

     // ---------------- PART C: Multiplication ----------------
    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;

    int rowsA, colsA, rowsB, colsB;
    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for Matrix A: ";
    cin >> colsA;

    if (rowsA <= 0 || colsA <= 0 || rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    if (rowsB <= 0 || colsB <= 0 || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A (" << colsA
             << ") must equal number of rows in B (" << rowsB << ")." << endl;
        return 0;
    }

    cout << "\nEnter values for Matrix A (" << rowsA << " x " << colsA << "):" << endl;
    readMatrix(matA, rowsA, colsA, "A");

    cout << "\nEnter values for Matrix B (" << rowsB << " x " << colsB << "):" << endl;
    readMatrix(matB, rowsB, colsB, "B");

    multiplyMatrices(matA, matB, rowsA, colsA, colsB, result);

    cout << "\nMatrix A:" << endl;
    printMatrix(matA, rowsA, colsA);
    cout << "\nMatrix B:" << endl;
    printMatrix(matB, rowsB, colsB);
    cout << "\nProduct (A x B):" << endl;
    printMatrix(result, rowsA, colsB);

    return 0;
}