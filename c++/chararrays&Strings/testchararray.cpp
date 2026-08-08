#include <iostream>

using namespace std;

void change(char *s){
    cout << *s << endl;
    s = nullptr;
    // cout << s << endl;
}

int main(){
    char s[] = "yash"; 
    change(s);
    // s = nullptr; // this will give error because s is an array and we cannot assign nullptr to an array
    cout << s << endl;
}