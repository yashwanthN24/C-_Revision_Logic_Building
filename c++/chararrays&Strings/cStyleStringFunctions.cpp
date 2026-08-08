#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char s[100];
    strcpy(s , "Hello my name is yash");

    cout << s << endl;

    // char s1[] = "Hello"; 
    // char s1[10] = "Hello"; 
    char s1[15] = "Hello"; 

    strcpy(s1 , "Hello world");
    cout << s1 << endl;
    return 0 ; 

    
    return 0;
}