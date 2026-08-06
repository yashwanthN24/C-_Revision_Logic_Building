/*

 Write a function which takes 2 numbers as parameters (a & b) and
outputs : a^2 + b^2 + 2*ab.


*/

#include <iostream>

using namespace std;

int calculate(int a , int b ){
    return (a*a + b*b + 2*a*b);
}

int main(){
    int a , b ; 
    cout << "Enter a value : "; 
    cin >> a ; 
    cout << "Enter b value : ";
    cin >> b;
    cout << "Result : " << calculate(a,b) << endl;
    return 0;
}