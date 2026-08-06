#include <iostream>

using namespace std;

int factorial(int n ){
    int fact =1 ; 
    for(int i = 1 ; i<=n ; i++){
        fact *= i ; 
    }
    return fact;
}

int binCoeff(int n , int r){
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main(){
    int n , r ;
    cout << "Enter total items:"; 
    cin >> n; 
    cout << "Enter no of items you want from those";
    cin >> r ;
    cout << binCoeff(n , r) << endl; 
    return 0 ;
}