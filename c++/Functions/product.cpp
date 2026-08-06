#include <iostream>

using namespace std;

int product(int a , int b){
    return a*b ; 
}

bool isEven(int n ){
    return n % 2 ==0 ;
}


int factorial(int n ){
    int fact = 1 ; 

    for(int i = 1 ; i<=n ; i++){
        fact *= i;
    }
    return fact;
}

int main(){
    int a = 5 , b = 6 ;

    cout << product(a , b) << endl ;   
    cout << isEven(34) << endl;
    cout << isEven(13) << endl;

    cout << factorial(5) << endl ;  
    cout << factorial(2) << endl;
    cout << factorial(0) << endl;

    cout << factorial(1) << endl;
}