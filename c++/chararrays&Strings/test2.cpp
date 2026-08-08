#include <iostream>

using namespace std;

int main(){
    string str = "bank";
    cout << str << endl;
    swap(str[0] , str[3]); // inc++ strinbg is mutable as it more of a dynamic character array so we can swap the characters in the string using the swap function
    cout << str << endl;
}