#include <iostream>
#include <cmath>

using namespace std; 

int main(){

    int n ; 
    cout << "Enter a number :" << endl; 
    cin >> n ; 

    // print prime number between 2 and this num,ber N 
    for(int j = 2 ; j<= n ; j++){
        bool isPrime = true ;
    for(int i = 2 ; i<=sqrt(j) ; i++){
        if(j%i == 0){
            // cout << n <<  " is not prime number " << endl; 
            isPrime = false;
            break ; 
        }
    }

    if(isPrime) cout << j << " is prime number " << endl; 
     
  }

    return 0 ; 
}