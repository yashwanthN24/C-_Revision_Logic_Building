#include <iostream>

using namespace std;

int main(){
    int n = 4;
    char c = 'A';
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << c++ << " ";
        }
        cout << endl;
    }
} 

// https://chatgpt.com/c/6a72d7a6-7a30-83ee-b05e-5136758748c3