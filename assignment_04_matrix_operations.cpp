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
// rows by columns; i by j
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << "Enter element [" << i << "][" << j << "]: ";
    cin >> matrix[i][j];
    }
  }
}

//matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << setw(5) << matrix[i][j];
    }
    cout << endl;
  }
}

//transpose
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[j][i] = matrix[i][j];
    }
  }
}


//addition of two matrices
void addMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = a[i][j] + b[i][j];
    }
  }
}


//multiplication of two matrices
void multiplyMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      result[i][j] = 0;
      for (int k = 0; k < n; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
} 



int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    
    // PART A
    cout << "---- TRANSPOSE ----" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix: " << endl;
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols, transposed);

    cout << "\nTransposed Matrix: " << endl;
    printMatrix(transposed, cols, rows);

    //PART B
    cout << "\n---- ADDITION ----" << endl;
    int addRows, addCols;
    cout << "Enter number of rows for both matrices: ";
    cin >> addRows;
    cout << "Enter number of columns for both matrices: ";
    cin >> addCols;

    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE], sumResult[MAX_SIZE][MAX_SIZE];

    cout << "Enter Matrix A: " <<endl;
    readMatrix(matA, addRows, addCols);

    cout << "Enter Matrix B: " <<endl;
    readMatrix(matB, addRows, addCols);

    addMatrix(matA, matB, addRows, addCols, sumResult);
    cout << "\nSum of Matrices A and B: " << endl;
    printMatrix(sumResult, addRows, addCols);

    //PART C
    cout << "\n---- MULTIPLICATION ----" <<endl;
    int m, n, p;

    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A or Rows of Matrix B: ";
    cin >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    int mulA[MAX_SIZE][MAX_SIZE], mulB[MAX_SIZE][MAX_SIZE], mulResult[MAX_SIZE][MAX_SIZE];
    
    cout << "Enter Matrix A (" << m << "x" << n << "): " << endl;
    readMatrix(mulA, m, n);

    cout << "Enter Matrix B (" << n << "x" << p << "): " << endl;
    readMatrix(mulB, n, p);

    multiplyMatrix(mulA, mulB, m, n, p, mulResult);

    cout << "\nProduct of Matrices A x B: " << endl;
    printMatrix(mulResult, m, p);

    return 0;
}