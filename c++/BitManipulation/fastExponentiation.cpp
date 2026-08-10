#include <iostream>

using namespace std;

int fastExponentation(int a , int n){
    int x = 1 ; 
    while(n > 0){
        if(n & 1){ // check if n is odd
            x = x * a ; 
        }
        a = a * a ; // square the base
        n = n >> 1; // divide n by 2
    }
    return x;
}

int main(){
    int a = 3 ;
    int n = 5;
    cout << fastExponentation(a , n) << endl;
}