#include <iostream>

using namespace std;


int main(){
    int a = 3 , b = 5;
    cout << (a&b) << endl; // bitwise AND operator
    cout << (a|b) << endl; // bitwise OR operator
    cout << (a^b) << endl; // bitwise XOR operator

    cout << ~a << endl;
    
    cout << (a<<1) << endl; // left shift operator

    cout << (a>>1) << endl; // right shift operator

    cout << (8>>1) << endl; 

    cout << ~4 << endl;

    return 0;
}