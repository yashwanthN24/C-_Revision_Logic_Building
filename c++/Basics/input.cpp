#include <iostream>

using namespace std;

int main(){
    int n1 , n2 , sum , mul , div , rem ; 
    cout << "Enter two numbers: " << endl;
    cout << "Enter first number: " << endl;
    cin >> n1;
    cout << "Enter second number: " << endl;
    cin >> n2;
    sum = n1 + n2;
    mul = n1*n2; 
    div = n1/n2 ; 
    rem = n1 % n2 ; 
    cout << "Sum of " << n1 << " and " << n2 << " is " << sum << endl;
    cout << sum << " "  << mul << " " << div <<  " " << rem << endl ; 

    return 0;

}