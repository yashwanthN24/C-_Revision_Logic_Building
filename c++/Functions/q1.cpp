/*

Write a function to check if a number is a palindrome in C++

*/


#include <iostream>

using namespace std;

void checkPalindrome(int n){

    int orginal = n , rev = 0; 

    while(n){
        int digit = n % 10;
        rev = rev*10 + digit;
        n/=10;
    }
    if(rev == orginal){
        cout << orginal << " is a palindrome number "; 
    }else{
        cout << orginal << " is not a palindrome number ";
    }
}

int main(){
    int n ; 
    cout << "Enter a number : ";
    cin >> n ; 
    
    checkPalindrome(n);
    return 0;

}