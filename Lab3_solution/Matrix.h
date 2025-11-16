#ifndef MATRIX_H
#define MATRIX_H

#include <string>
using namespace std;

class Matrix {

private:
    unsigned int m_rows;
    unsigned int m_cols;
    int** data;

public:

    /**
     * Construct a matrix of size m x n with all elements set to 0.
     * @param m number of rows (read-only)
     * @param n number of columns (read-only)
     */
    Matrix(unsigned int m, unsigned int n);

    /**
     * Copy constructor.
     * Creates a deep copy of matrix mat.
     * @param mat reference to another matrix (read-only)
     */
    Matrix(const Matrix &mat);

    /**
     * Build a matrix using an existing 2D array.
     * Must deep-copy the provided array.
     * @param array 2D array of ints (read-only)
     * @param m number of rows
     * @param n number of columns
     */
    Matrix(int** array, unsigned int m, unsigned int n);

    /**
     * Destructor. Frees dynamically allocated memory.
     */
    ~Matrix();

    /**
     * @return number of rows in matrix (read-only)
     */
    unsigned int rows() const;

    /**
     * @return number of columns in matrix (read-only)
     */
    unsigned int columns() const;

    /**
     * Retrieve an element.
     * @param i row index (0-based)
     * @param j column index (0-based)
     * @return int value at position (i,j)
     */
    int get(unsigned i, unsigned j) const;

    /**
     * Set a matrix element.
     * @param i row index
     * @param j column index
     * @param value new integer value
     */
    void set(unsigned i, unsigned j, int value);

    /**
     * Add two matrices.
     * @param mat another matrix (read-only)
     * @return a new matrix representing this + mat
     */
    Matrix operator+(const Matrix &mat);

    /**
     * Subtract two matrices.
     * @param mat another matrix (read-only)
     * @return a new matrix representing this - mat
     */
    Matrix operator-(const Matrix &mat);

    /**
     * Multiply two matrices.
     * Standard matrix multiplication rules apply.
     * @param mat another matrix (read-only)
     * @return resulting matrix of multiplication
     */
    Matrix operator*(const Matrix &mat);

    /**
     * Transpose the matrix.
     * @return a new matrix that is the transpose
     */
    Matrix operator~() const;

    /**
     * Check if two matrices are identical.
     * Same size and same elements.
     * @param mat another matrix (read-only)
     * @return true if identical, false otherwise
     */
    bool operator==(const Matrix &mat);

    /**
     * Convert matrix to a string.
     * Each row printed on its own line.
     * @return string representation of matrix
     */
    string toStr() const;
};

#endif
