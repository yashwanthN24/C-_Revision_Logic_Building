#include <iostream>

using namespace std;

void fact(int f , int n){
    if( n == 1) {
        cout << f << endl;
        return;
    } 

    fact(f*n , n-1);
}

int main(){
    int n = 5;

    fact(1 , n);
}