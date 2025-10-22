#include <iostream>
using namespace std;

 int reverseInteger(int num) {
    int reverseNum = 0;
    // algorithm that takes the last digit and puts that into reverseNum
    while(num != 0) {
        /* 
         reverseNum contains last number inserted
         we multiply reverseNum by 10
         then add on the second last number 
         And we go on until the first digit of original number is reached 
         that is number becomes 0 as we divide by 10
        */
        reverseNum = reverseNum * 10 + num % 10;
        num = num / 10;
    }
    return reverseNum;
}

 int gcd(int firstNum, int secondNum) {
    // smaller number is selected using ternary operator

    int smallerNum = (firstNum < secondNum) ? firstNum : secondNum;

    // the loop runs starting from descending order with the smaller number as start
    // returns the first value that meets the condition
    // As it wont be greatest in the coming iteration since i is reduced by 1 each time
    // condition is that both are divided

    for(int i = smallerNum; i >= 1; i--){
        if(firstNum % i == 0 && secondNum % i == 0){
            return i;
        }
    }
    return 1;
}

 bool isPalindrome(int checkNum) {
    if (checkNum < 0) return false;           // treat negatives as not palindromic
    int original = checkNum;                  // save original value
    int reverseOfNum = reverseInteger(checkNum); // finds the reverse using the previously made reverse function
    return original == reverseOfNum;
}

 double powerCalculate(double base, int exponent) {
    // any value raise to zero is 1;
    if(exponent == 0){
        return 1;
    }

    //handling negative exponent by taking inverse of base and absolute value of exponent

    if(exponent < 0){
        base = 1 / base;
        exponent = -1 * exponent;
    }

    //taking half recursively to reduce run time from O(n) to O(log(n))
    //by using the divide and conquer approach

    double half = powerCalculate(base, exponent / 2);

    //the if else handles the odd exponent or even exponent seperately
    //if returns the first half and second half as a product
    //else also goes onto multiply the base once again to account for the odd = even + 1

    if(exponent % 2 == 0) {
        return half * half;
    } else {
        return base * half * half;
    }
}

 bool isPowerOfTwo(int checkNumTwo){

    //base case for recursion

    if(checkNumTwo == 1) return true;

    //Since zero cannot be a power of any number
    //And when odd number remains we return false as it has to keep being even

    if(checkNumTwo == 0 || checkNumTwo % 2 != 0) return false;

    //recursive call that keeps going till it becomes 1 or gets returned false mid way

    return isPowerOfTwo(checkNumTwo / 2);
}

int main() {
    // intitalise and takes input for number to reversed
    int num;

    cout <<"Enter a valid integer to be reversed: \n";
    cin >> num;

    int reversed = reverseInteger(num); 
    cout << "Reversed integer : " << reversed << endl;
    // task 1 input and output ends here

    // task 2 starts here
    int firstNum, secondNum;

    cout << "Enter first number of the two required to check for greatest common divisor: \n";
    cin >> firstNum;

    cout << "Enter second number of the two required to check for greatest common divisor: \n";
    cin >> secondNum;

    int greatestCommonDivisor = gcd(firstNum, secondNum); 

    cout << "The greatest common divisor of the two numbers is : " << greatestCommonDivisor << endl;
    //task 2 ends here

    //task 3 starts here

    int checkNum;
    cout << "Enter number to check if it is palindrome : \n";
    cin >> checkNum;

    cout << "Palindrome status : " << (isPalindrome(checkNum) ? "True" : "False") << endl;
    //task 3 ends here

    //task 4 starts here
    double base;
    int exponent;
    cout << "Enter the base for calculating its power : \n";
    cin >> base;
    cout << "Enter the exponent for calculating its power with its base : \n";
    cin >> exponent;

    cout << "The correspoding base and power outputs : " << powerCalculate(base, exponent) << endl;
    //task 4 ends here

    //task 5 starts here 
    int checkNumTwo;
    cout << "Enter number to check if it is power of 2 : \n";
    cin >> checkNumTwo;

    cout << (isPowerOfTwo(checkNumTwo) ? "True, it is a power of 2" : "False, it is not a power of 2") << endl;

    //all tasks end here

}