#include <iostream>

using namespace std ; 

int main(){
    int a ,b ; 
    cout << "Enter first number :"  ;
    cin >> a ; 
    cout << "Enter second number :"  ; 
    cin >> b ; 

    if(a > b){
        cout << a << " is the largest number." << endl ; 
    }
    else{
        cout << b << " is the largest number." << endl ; 
    }

    return 0 ; 
}