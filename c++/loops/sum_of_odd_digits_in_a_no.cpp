#include <iostream>

using namespace std ; 

int main(){
    int n ; 
    cout << "Enter a number :"  ;
    cin >> n ; 

    int sum = 0 ; 
    while(n){
    int digit = n % 10 ; 
    if(digit % 2 != 0 )
        sum += digit ;
    n /= 10 ;
    }
    cout << "Sum of odd digits is : " << sum << endl ;
}