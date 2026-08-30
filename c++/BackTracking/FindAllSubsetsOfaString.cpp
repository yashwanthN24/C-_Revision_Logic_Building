#include <iostream>

using namespace std;

// string &str wont work becayse that substr what we get is a temprory string so this string &refrence cant bind to non-const (i.e temporary trings )

// so adding const allwas us to refers to temporary strngs 
void printSubsets(const string &str , string subset ){
    if(str.length() == 0){
        if(subset.length() == 0){
            cout << "phi "  ;
        }else{
            cout << subset << " " ;
        }
        return ;    
    }

    char ch = str[0];
    // str[0] = 'a'; ssee this wont work as the string is cnst we know weare only using string for readng puroises not modifying or writing to the same string 
    
    // wnt to be opart of subset
    printSubsets(str.substr(1 , str.size()-1) , subset + ch);

    // not to be part of subset 
    printSubsets(str.substr(1 , str.size()-1) , subset);
}

int main(){

    string str = "abc";
    printSubsets(str , "");
}

// https://chatgpt.com/c/6a943ca9-065c-83e8-b9e5-df58a5d607bc