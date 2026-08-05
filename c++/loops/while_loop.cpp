#include <iostream>

using namespace std ; 

int main(){

    int i = 1 , n = 5 , sum = 0; 

    while( i <= n ){
        cout << i << " "  ; 
        sum += i ; 
        i++ ;   
    }
    cout << "\nSum of first " << n << " natural numbers is : " << sum << endl ; 


}