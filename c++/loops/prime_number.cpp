#include <iostream>

using namespace std ; 

int main(){

    int n ; 
    cout << "Enter a number : " ; 
    cin >> n ; 

    for(int i = 2 ; i<n ; i++){
        if(n % i == 0 ){ // means found number that divides this number other than 1 and this number itsefl so its not a prime number as it has more than 2 factors 
            cout << n <<  "  is not a prime number its composite number "; 
            exit(0); 
        }
    }
    cout << n << " is a prime number." << endl ;
}