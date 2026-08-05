#include <iostream> 

using namespace std ; 

int main(){
    int a , b ; 
    cout << "Enter first number :"  ;
    cin >> a ; 
    cout << "Enter second number :"  ; 
    cin >> b ; 
 
    int largest = (a > b) ? a : b ;
    cout << largest << " is the largest number." << endl ;  

    int smallest = (a < b) ? a : b ; 
    cout << smallest << " is the smallest number." << endl ;

    int num ; 
    cin >> num ; 

    bool isEven = (num % 2 == 0) ? true : false ;
    cout << num << " is " << (isEven ? "" : "not ") << "even." << endl ;

    int age ; 
    cin >> age ; 

    bool isAdult = (age >= 18) ? true : false ;
    cout << isAdult << " is " << (isAdult ? "" : "not ") << "an adult." << endl ;

    return 0 ;
}