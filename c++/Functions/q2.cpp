/*

Write a function to calculate the sum of digits of a number.

*/

#include <iostream>

using namespace std;

int sumOfdig(int n ){

    int sum = 0 ; 
    while(n){
        int digit = n % 10 ; 
        sum += digit;
        n /= 10;
    }

    return sum;

}

int main(){
    int n ; 
    cout << "Enter a number : " ;
    cin >> n ;

    cout << sumOfdig(n) << endl;
    return 0;
}