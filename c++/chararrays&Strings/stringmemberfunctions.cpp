#include <iostream>

using namespace std;

int main(){
    string s = "yashwanth";
    cout << s << endl;

    cout << s.length() << endl; // it will print the length of the string excluding the null character

    cout << s[3] << endl;
    cout << s.at(3) << endl; // it will print the character at index 3 of the string    

    string str = "hello world";
    cout << str.substr(6 , 5) << endl; // it will print the substring of the string starting from index 6 and of length 5   

    str.find("c++") ;// returns first occurence of the word c++

    str.find("c++" , 5); // returns first occurence of the word c++ after index 5 (so find starts searching fromindex 5 )

    str.find("python") ; // return -1 if the word is not found in the string
}