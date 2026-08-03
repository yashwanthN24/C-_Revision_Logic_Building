#include <iostream>

using namespace std; 

int main(){
    printf("%d %d %d %d %d" , sizeof(int) , sizeof(float) , sizeof(double) , sizeof(char) , sizeof(bool));

    cout << endl << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    return 0 ;      
}