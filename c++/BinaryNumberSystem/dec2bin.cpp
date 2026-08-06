#include <iostream>
#include <cmath>


using namespace std;

int dec2bin(int n ){
    int binary = 0 , i = 0;
    while(n){
        int lastdigit = n % 2 ;
        binary +=  lastdigit*(pow(10 , i++));// 10^1*digit + 10^2*figit 
        n /= 2 ;
    }

    return binary;
}

int main(){
    int n ; 
    cout << "Enter a number :";
    cin >> n ; 

    cout << dec2bin(n) << endl;
}