#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

bool isBinary(int n) {
    // if (n == 0)
    //     return true;

    while (n > 0) {
        int digit = n % 10;

        if (digit != 0 && digit != 1)
            return false;

        n /= 10;
    }

    return true;
}

int bin2dec(int n){
    int dec = 0 , i=0;

    while(n){
        int digit = n % 10 ; 
        dec += digit*(pow(2,i++));
        n /=10;
    }

    return dec;
}
int bin2dec2(int n){
    int dec = 0 , pow = 1;

    while(n){
        int digit = n % 10 ; 
        dec += digit*pow;
        pow *= 2 ;
        n /=10;
    }

    return dec;
}


int main(){
    unsigned short int n ;
    cout << "Enter a binary number " << endl; 
    cin >> n ; 

    while(!isBinary(n)){
        cin >> n ;
    }

    cout << bin2dec(n) << endl;
    cout << bin2dec2(n) << endl;

    cout << n << endl; 
}