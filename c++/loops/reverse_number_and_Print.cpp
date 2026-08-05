#include <iostream>

using namespace std ; 

int main(){
    int n ; 
    cout << " Enter a number : " ; 
    cin >> n ; 

    // get last digit and place it in its correct decimal place and print it 
    // so last digit * 10^0 + second last digit * 10^1 + third last digit * 10^2 + ...

    // because take any number 123 is eqivanlent to 3*10^0 + 2*10^1 + 1*10^2 = 3 + 20 + 100 = 123

    int reverse = 0  ; 
    while(n){
    int digit = n % 10 ; 
    reverse = reverse * 10 + digit ;
    n /= 10 ;
    }
    cout << "Reverse of the number is : " << reverse << endl ;
}