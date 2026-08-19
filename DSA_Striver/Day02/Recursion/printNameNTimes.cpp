// print your name N times on console using recursion 

#include <iostream>

using namespace std;

void printName(int n , string name ){
    if(n==0){
        return ;
    }
    cout << name << " ";
    printName(n-1, name);
}

int main(){
    int n = 2;

    string name = "yash";

    printName(n , name);
}

// https://chatgpt.com/c/6a853451-89d4-83e8-b20a-54be958fe34a


