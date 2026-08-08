#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char word[10];

    cin >> word ;  // ignores whitespace so reads only the first word and ignores the rest of the string after whitespace

    cout << word << endl;
    cout << strlen(word) << endl; // it will print the length of the string excluding the null character
    cin.ignore(); // to ignore the newline character left in the input buffer by cin >> word
    char sentence[50];
    cin.getline(sentence , 50 );
    cout << sentence << endl;
    cout << strlen(sentence) << endl;

    cin.getline(sentence , 50 , '.'); // till user enters . it will keep reading till there all characters
    cout << sentence << endl;
    cout << sentence[0] << endl;
    cout << "Ok" << endl; 


    // cin leave behind \n which cin.getline will consume so if your suing cin.getline after cin >> always precede cin.getline with cin.ignore() to ignore the leftout \n buffer

    // same qualities as arrays can access individual characters of string using index position and can also modify the individual characters of string using index position.

    // s[0]
}