/*

Write a function that prints the largest of 3 numbers.


*/

#include <iostream>

using namespace std ; 


int largest(int a , int b , int c){
    if(a > b && a > c){
        return a ;
    }else if(b > c){
        return b;
    }else{
        return c ;
    }
}


int main(){
    int a , b ,c ;
    cout << " Enter first number :";
    cin >> a ; 
    cout << " Enter second number :";
    cin >> b ; 
    cout << " Enter third number :";
    cin >> c ; 
    cout << largest(a , b , c) << endl;
    return 0;
}