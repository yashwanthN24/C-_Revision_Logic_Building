/*

WAP to input a number and check whether the number is an Armstrong
number or not.
An Armstrong number is a number that is equal to the sum of cubes of its digits.

*/

#include <iostream>

using namespace std; 

int main(){

    int n ; 
    cout << "Enter a number : " ; 
    cin  >> n ; 

    int orignal = n , num =0 ; 

    while(n){
        int digit = n % 10 ; 
        num += (digit * digit * digit);
        n /= 10 ; 
    }

    cout << n << endl ; 
    cout << num << endl ; 
    cout << orignal << endl; 

    if(num == orignal){
        cout << orignal << " is an armstrong number " << endl ; 
    }else{
        cout << orignal << " is not a armstrong number " << endl ; 

    }
    return 0 ; 
}