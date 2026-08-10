#include <iostream>

using namespace std;

int getIthBit(int n , int i){
    int bitmask = (1 << i); // 1 << i means 1 shifted left by i positions, which is 2^i in decimal
    int result = (n & bitmask); // this gets the ith bit of n (counting from 0) and checks if it is set or not
    return result != 0; // if the ith bit of n is set, result will be non-zero, otherwise it will be zero
}

int main(){
    int n = 5 ; 
    // int bitmask = (1 << 2); // 1 << 2 means 1 shifted left by 2 positions, which is 4 in decimal (binary: 100)
    // int result = (n & bitmask);// this gets the 2nd bit of n (counting from 0) and checks if it is set or not
    // cout << result << endl; // if the 2nd bit of n is set, result will be non-zero (4), otherwise it will be zero (0)
    cout << getIthBit(n , 2);

}