/*
==============================================================
CS264 Assignment 2 – String Function Implementations
Author: Edwin Shibu Mathew
Description:
    This program implements basic string operations in C++
    without using any built-in C++ string library functions.
==============================================================
*/

#include <iostream>
using namespace std;

/*--------------------------------------------------------------
  Helper: equality check for C-strings 
   -> This function helps do the checks in the testcases written
--------------------------------------------------------------*/
bool equals(const char* a, const char* b) {
    if (!a || !b) return a == b;
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

/*--------------------------------------------------------------
  1. length
  --------------------------------------------------------------
  Description:
      Returns the number of characters in a null-terminated
      C-string, not counting the '\0' terminator.

  Arguments:
      str – pointer to a null-terminated character array.

  Return:
      Unsigned int representing the string length.
--------------------------------------------------------------*/
unsigned int length(const char* str) {
    if (!str) return 0;
    int count = 0;                 
    while (str[count] != '\0') {
        count++;
    }
    return (unsigned int)count;    // type casting for return 
}

/*--------------------------------------------------------------
  2. copy
  --------------------------------------------------------------
  Description:
      Copies the contents of src (including '\0') into dest.
      The copy happens only if dest is large enough to hold src;
      otherwise the function returns NULL.

  Arguments:
      dest – pointer to destination buffer.
      src  – pointer to source string.

  Return:
      dest pointer on success; NULL if dest too small.
--------------------------------------------------------------*/
char* copy(char* dest, const char* src) {
    if (!dest || !src) return NULL;

    //type casting to int to ensure no garbage effects the output

    int srcLen  = (int)length(src);   
    int destLen = (int)length(dest);  

    if (destLen < srcLen) return NULL;

    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/*--------------------------------------------------------------
  3. indexOf
  --------------------------------------------------------------
  Description:
      Returns the first index position of character c in str.
      Returns −1 if c is not found.

  Arguments:
      c   – character to look for.
      str – input C-string.

  Return:
      Index (0-based) of first occurrence of c; −1 if not found.
--------------------------------------------------------------*/
int indexOf(char c, const char* str) {
    if (!str) return -1;
    int i = 0;                      
    while (str[i] != '\0') {
        if (str[i] == c)
            return i;
        i++;
    }
    return -1;
}

/*--------------------------------------------------------------
  4. substring
  --------------------------------------------------------------
  Description:
      Returns a new substring of str starting at index i
      and ending at index j − 1.
      Returns NULL if i or j are out of range or invalid.

  Arguments:
      i, j – start and end indices.
      str  – source C-string.

  Return:
      Newly allocated char* containing substring.
      Caller must delete[] the returned pointer.
--------------------------------------------------------------*/
char* substring(int i, int j, const char* str) {
    if (!str || i < 0 || j < i) return NULL;

    //type casting to signed int to avoid garbage affecting output
    int n = (int)length(str);       
    if (i > n) return NULL;
    if (j > n) j = n;

    int len = j - i;                
    char* sub = new char[len + 1];

    for (int k = 0; k < len; k++) { 
        sub[k] = str[i + k];
    }
    sub[len] = '\0';
    return sub;
}

/*--------------------------------------------------------------
  5. replace
  --------------------------------------------------------------
  Description:
      Returns a new string identical to str except that every
      occurrence of character c is replaced by p.
      If c does not appear, returns a copy of str.

  Arguments:
      c, p – characters to replace (from c to p).
      str  – input C-string.

  Return:
      Newly allocated char* with replacements.
      Caller must delete[] the returned pointer.
--------------------------------------------------------------*/
char* replace(char c, char p, const char* str) {
    if (!str) return NULL;

    int n = (int)length(str);       
    char* newStr = new char[n + 1];

    for (int i = 0; i < n; i++) {   
        newStr[i] = (str[i] == c) ? p : str[i];
    }
    newStr[n] = '\0';
    return newStr;
}

/*--------------------------------------------------------------
  TEST CASES WITH PASS/FAIL OUTPUT 
--------------------------------------------------------------*/
void length_test_case_1() {
    unsigned int result = length("string");
    bool pass = (result == 6u);
    cout << "length_test_case_1: got " << result << " (Expected 6) "<< (pass ? "✅ PASSED\n" : "❌ FAILED\n");
}

void copy_test_case_1() {
    char dest[20] = "................";   // ensures length(dest) >= length("CS264")
    char* res = copy(dest, "CS264");
    bool pass = (res != NULL) && equals(dest, "CS264");
    cout << "copy_test_case_1: got \"" << dest << "\" (Expected CS264) "<< (pass ? "✅ PASSED\n" : "❌ FAILED\n");
}

void indexOf_test_case_1() {
    int result = indexOf('i', "string");
    bool pass = (result == 3);
    cout << "indexOf_test_case_1: got " << result << " (Expected 3) "<< (pass ? "✅ PASSED\n" : "❌ FAILED\n");
}

void substring_test_case_1() {
    char* sub = substring(0, 3, "string");
    bool pass = (sub != NULL) && equals(sub, "str");
    cout << "substring_test_case_1: got \"" << (sub ? sub : "NULL") << "\" (Expected str) " << (pass ? "✅ PASSED\n" : "❌ FAILED\n");
    if (sub) delete[] sub;
}

void replace_test_case_1() {
    char* rep = replace('i', 'x', "string");
    bool pass = (rep != NULL) && equals(rep, "strxng");
    cout << "replace_test_case_1: got \"" << (rep ? rep : "NULL")<< "\" (Expected strxng) " << (pass ? "✅ PASSED\n" : "❌ FAILED\n");
    if (rep) delete[] rep;
}

/*--------------------------------------------------------------
  main
--------------------------------------------------------------*/
int main() {
    cout << "==== Running CS264 Assignment 2 Tests ====\n\n";

    length_test_case_1();
    copy_test_case_1();
    indexOf_test_case_1();
    substring_test_case_1();
    replace_test_case_1();

    cout << "\n==== Tests Completed ====\n";
    return 0;
}
