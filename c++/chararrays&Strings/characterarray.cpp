#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char s[5] = {'a' , 'b' , 'c' , 'd' , 'e'};
    cout << s << endl; // it will print the string till it encounters the null character
    // unlike oother array character array print the elements itselfinstead of printing base address 

    char a[5] = {'a' , 'b' , 'c' , 'd' , '\0'};
    cout << a << endl; // it will print the string till it encounters the null character
   
    char name[] = "yashwanth";

    cout << name << endl;

    char names[50] = { 'y' , 'a' }; 
    cout << names << endl; // it will print the string till it encounters the null character

    cout << strlen(name) << endl; // it will print the length of the string excluding the null character
}