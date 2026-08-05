#include <iostream>

using namespace std ; 

int main(){

    int n ; 
    cout << "Enter a number: " ; 
    cin >> n ; 

    while(n){
        int digit = n % 10 ; 
        cout << digit ; 
        n /= 10 ;
    }
    
}