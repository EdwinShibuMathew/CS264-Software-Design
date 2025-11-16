#include <iostream>
#include "Matrix.h"
using namespace std;

// -------- Test Case 1: Constructor --------
void Test_Constructor() {
    Matrix m(2, 3);
    cout << "Constructor test:\n" << m.toStr() << endl;
}

// -------- Test Case 2: Copy Constructor --------
void Test_CopyConstructor() {
    Matrix a(2, 2);
    a.set(0,0,5);
    Matrix b(a);
    cout << "Copy constructor test:\n" << b.toStr() << endl;
}

// -------- Test Case 3: Array Constructor --------
void Test_ArrayConstructor() {
    int** arr = new int*[2];
    for(int i=0;i<2;i++){
        arr[i] = new int[2];
        arr[i][0] = i+1;
        arr[i][1] = i+3;
    }
    Matrix m(arr,2,2);
    cout << "Array constructor test:\n" << m.toStr() << endl;

    for(int i=0;i<2;i++) delete[] arr[i];
    delete[] arr;
}

// -------- Test Case 4: Get/Set --------
void Test_GetSet() {
    Matrix m(2,2);
    m.set(0,1,7);
    cout << "Get/Set test: " << m.get(0,1) << endl;
}

// -------- Test Case 5: Addition --------
void Test_Add() {
    Matrix a(2,2), b(2,2);
    a.set(0,0,1); b.set(0,0,2);
    Matrix c = a + b;
    cout << "Addition:\n" << c.toStr() << endl;
}

// -------- Test Case 6: Subtraction --------
void Test_Sub() {
    Matrix a(2,2), b(2,2);
    a.set(0,0,5); b.set(0,0,3);
    Matrix c = a - b;
    cout << "Subtraction:\n" << c.toStr() << endl;
}

// -------- Test Case 7: Multiplication --------
void Test_Multiply() {
    Matrix a(2,2), b(2,2);
    a.set(0,0,1); a.set(0,1,2);
    a.set(1,0,3); a.set(1,1,4);

    b.set(0,0,2); b.set(0,1,0);
    b.set(1,0,1); b.set(1,1,2);

    Matrix c = a * b;
    cout << "Multiplication:\n" << c.toStr() << endl;
}

// -------- Test Case 8: Transpose --------
void Test_Transpose() {
    Matrix a(2,3);
    a.set(0,1,9);
    Matrix t = ~a;
    cout << "Transpose:\n" << t.toStr() << endl;
}

// -------- Test Case 9: Equality --------
void Test_Equals() {
    Matrix a(2,2), b(2,2);
    cout << "Equality test: " << (a == b) << endl;
}

// -------- Test Case 10: toStr --------
void Test_toStr() {
    Matrix m(2,2);
    m.set(0,0,8);
    cout << "toStr test:\n" << m.toStr() << endl;
}

int main() {
    Test_Constructor();
    Test_CopyConstructor();
    Test_ArrayConstructor();
    Test_GetSet();
    Test_Add();
    Test_Sub();
    Test_Multiply();
    Test_Transpose();
    Test_Equals();
    Test_toStr();

    return 0;
}
