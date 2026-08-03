#include <iostream>

using namespace std;

int main(){
    // implicit
    cout << 10/3 << endl ; 
    cout << 10/3.0f << endl ; 

    cout << 'A' + 1 << endl ; 
    float b = 4.0f;
    cout << b << endl ; 

    // Explicit 

    cout << (char) 'A' + 1 << endl ; 
    cout << (char) ('A' + 1) << endl ; 
}