#include <iostream>

using namespace std;

int fib(int n ){
    if(n == 0 || n == 1){
        return n;   
    }

    return fib(n-1) + fib(n-2);
}

// but 2^n as multiple calculation of same redeundant calls of fb(2) , fib(3) ... at each level 

int main(){

    int n = 6;
    
    cout << fib(n) << endl;

}