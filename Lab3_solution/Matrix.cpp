#include "Matrix.h"
#include <sstream>
#include <iostream>

Matrix::Matrix(unsigned int m, unsigned int n) {
    m_rows = m;
    m_cols = n;

    data = new int*[m_rows];
    for (unsigned int i = 0; i < m_rows; i++) {
        data[i] = new int[m_cols];
        for (unsigned int j = 0; j < m_cols; j++) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &mat) {
    m_rows = mat.m_rows;
    m_cols = mat.m_cols;

    data = new int*[m_rows];
    for (unsigned int i = 0; i < m_rows; i++) {
        data[i] = new int[m_cols];
        for (unsigned int j = 0; j < m_cols; j++) {
            data[i][j] = mat.data[i][j];
        }
    }
}

Matrix::Matrix(int** array, unsigned int m, unsigned int n) {
    m_rows = m;
    m_cols = n;

    data = new int*[m_rows];
    for (unsigned int i = 0; i < m_rows; i++) {
        data[i] = new int[m_cols];
        for (unsigned int j = 0; j < m_cols; j++) {
            data[i][j] = array[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m_rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

unsigned int Matrix::rows() const {
    return m_rows;
}

unsigned int Matrix::columns() const {
    return m_cols;
}

int Matrix::get(unsigned i, unsigned j) const {
    return data[i][j];
}

void Matrix::set(unsigned i, unsigned j, int value) {
    data[i][j] = value;
}

Matrix Matrix::operator+(const Matrix &mat) {
    Matrix res(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            res.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix &mat) {
    Matrix res(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            res.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix &mat) {
    Matrix res(m_rows, mat.m_cols);

    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < mat.m_cols; j++) {
            int sum = 0;
            for (unsigned int k = 0; k < m_cols; k++) {
                sum += data[i][k] * mat.data[k][j];
            }
            res.data[i][j] = sum;
        }
    }
    return res;
}

Matrix Matrix::operator~() const {
    Matrix res(m_cols, m_rows);
    for (unsigned int i = 0; i < m_cols; i++) {
        for (unsigned int j = 0; j < m_rows; j++) {
            res.data[i][j] = data[j][i];
        }
    }
    return res;
}

bool Matrix::operator==(const Matrix &mat) {
    if (m_rows != mat.m_rows || m_cols != mat.m_cols)
        return false;

    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            if (data[i][j] != mat.data[i][j]) return false;
        }
    }
    return true;
}

string Matrix::toStr() const {
    stringstream ss;
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < m_cols; j++) {
            ss << data[i][j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}
