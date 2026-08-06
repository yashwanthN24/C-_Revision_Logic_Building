/*

Write a function that accepts a character (ch) as parameters & returns
the character that occurs after ch in the English alphabet.
Eg : input = ‘c’, return value = ‘d’



*/


#include <iostream>

using namespace std; 

char nextOccurence(char ch){
    char base  = (ch >= 'a') ? 'a' : 'A';
    char next = (ch -base + 1) % 26 + base;
    return next;
}

char getNextChar(char ch){
    if(ch == 'z'){
        return 'a';
    }else if(ch == 'Z'){
        return 'A';
    }else{
        return ch + 1 ;
    }


}

int main(){
    char ch; 
    cout << "Enter a alphabet in English Alphabet"; 
    cin >> ch;

    while(!isalpha(ch)){
        cin >> ch;
    }

    cout << ch << endl;
    cout << nextOccurence(ch) << endl;
    cout << getNextChar(ch) << endl;
}