#include <iostream>

using namespace std;

void printPermutations(string &s , string permt){
    if(s.length() == 0){
        cout << permt << " ";
        return ;
    }

    for(int i = 0 ; i<s.length() ; i++){
        char ch = s[i]; // picking this character 
        // so remaining options  
        string restOfString = s.substr(0 , i) + s.substr(i+1 , s.length()-i-1); // remaining options
        printPermutations(restOfString , permt + ch);

    }
}

int main(){

    string s = "abc";
    printPermutations(s , "");
}