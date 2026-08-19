#include <iostream>

using namespace std;


void print1ToN(int n){
    if(n == 0){
        return ;
    }
    print1ToN(n-1 );
    cout << n << " ";   
}

int main(){

    int n = 5;

    print1ToN(n);
}