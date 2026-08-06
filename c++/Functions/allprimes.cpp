#include <iostream>

using namespace std; 

bool checkPrime(int num){
    bool isPrime = true ;
        for(int j = 2 ; j*j <= num; j++){
            if(num % j == 0){
                isPrime = false;
                break;
            }
        }
        return isPrime ?  true :  false ; 
}

void getAllPrimes(int n ){

    if(n== 1){
        cout << "No prime numbers 1 is not a prime number either";
        return ;
    }

    for(int i = 2 ; i<=n ; i++){
        if(checkPrime(i))
            cout << i <<  "  ";
    }

}

int main(){
    int n ; 
    cout << "Enter n value upto to which you want all prime numbers: " ;
    cin >> n ;
    
    getAllPrimes(n);

}