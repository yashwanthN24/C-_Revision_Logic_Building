#include <iostream>

using namespace std ; 

int main(){
    int a = 10 , b = 20 ; 

    cout << "a && b : " << (a && b) << endl ; 
    cout << "a || b : " << (a || b) << endl ; 
    cout << "!a : " << (!a) << endl ;

    cout << ((10>9) && (10>5)) << endl ;
    cout << ((10>9) || (10>5)) << endl ;
    cout << ((1>5) && (10>5)) << endl ;
    cout << (!(10>9)) << endl ;
}