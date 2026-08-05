#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n ; 
    cout << "Enter a number :" ; 
    cin >> n ;

    // check prime 

    bool isPrime = true ; 

    // why upto sqrt(n) because the factors repeat after that so if we just check only one factor other than 1 and thenumber itself enough 
    for(int i = 2 ; i<= sqrt(n) ; i++){
        if(n % i == 0 ){
            isPrime = false; 
            break ;
        }
    }

    isPrime ? cout <<  n << " is Prime number " : cout << n << " is not prime number ";
}