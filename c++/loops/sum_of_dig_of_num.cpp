#include <iostream>

using namespace std; 

int main(){
    int n ; 
    cout << "Enter a number :"  ; 
    cin >> n ; 

    int sum = 0 ; 
    // for(; n ; ){
    //     int digit = n % 10 ; 
    //     sum += digit ; 
    //     n /= 10 ; 
    // }

    while(n){
        int digit = n % 10 ; 
        sum += digit ; 
        n /= 10 ; 
    }
    cout << "Sum of digits of the number is : " << sum << endl ;
    return 0 ; 
}