#include <iostream>

using namespace std;

int main(){

    char ch = 'A';
    cout << "Size of char datatype is : " << sizeof(ch) << endl;
    cout << ch << endl; 
    cout << (int) ch << endl; // to print the ascii value of char datatype we have to typecast it to int datatype

    cout << (ch - 'A') << endl;// to print the index position of alpahbet in 26 alphabets we can subtract the char with 'A' and it will give us the index position of the alphabet in 26 alphabets

    char ch1 = '\n';
    cout << ch1 << endl; // to print the new line character we can use the escape sequence '\n' and it will print the new line character
}