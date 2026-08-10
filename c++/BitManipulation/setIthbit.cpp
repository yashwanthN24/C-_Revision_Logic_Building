#include <iostream>

using namespace std ; 

int setIthBit(int n , int i){
    int bitmask = (1 << i); // 1 << i means 1 shifted left by i positions, which is 2^i in decimal
    int result = (n | bitmask); // this sets the ith bit of n (counting from 0) to 1
    return result; // return the new number with the ith bit set to 1
}

int clearIthBit(int n , int i){
    int bitmask = ~(1 << i); // 1 << i means 1 shifted left by i positions, which is 2^i in decimal, and ~ negates the bits
    int result = (n & bitmask); // this clears the ith bit of n (counting from 0) to 0
    return result; // return the new number with the ith bit cleared to 0
}

bool isPowerOf2(int n){
    return (n & (n-1)) == 0; // if n is a power of 2, then n & (n-1) will be 0
}   

int clearIthBits(int n , int i){
    int bitmask = (~0 << i); // ~0 is all 1s, shifting left by i positions will create a mask with the last i bits as 0 and the rest as 1
    int result = (n & bitmask); // this clears the last i bits of n (counting from 0) to 0
    return result; // return the new number with the last i bits cleared to 0
}

int countSetBits(int n ){
    int count = 0 ; 
    while(n > 0){
        if(n & 1){ // check if the last bit is set
            count++; // increment count if it is set
        }
        n = n >> 1; // right shift n by 1 to check the next bit
    }
    return count; // return the total count of set bits
}

int main(){
    int n = 5 ;
    int i = 1;
    cout << setIthBit(n , i) << endl; // this will set the 1st bit of 5 (binary: 101) to 1, resulting in 7 (binary: 111)
    cout << setIthBit(6 , 3) << endl; // this will set the 1st bit of 5 (binary: 101) to 1, resulting in 7 (binary: 111)

    // we start from right to left 210 ith bits counting 

    cout << clearIthBit(n , i-1) << endl; // this will clear the 1st bit of 5 (binary: 101) to 0, resulting in 5 (binary: 101)

    cout << isPowerOf2(8) << endl; // this will check if 8 is a power of 2, which it is, so it will return true (1)

    cout << isPowerOf2(4) << endl;

    cout << clearIthBits(15 , 2) << endl; // this will clear the last 2 bits of 15 (binary: 1111) to 0, resulting in 12 (binary: 1100)
}