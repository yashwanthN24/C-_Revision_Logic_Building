#include <iostream>

using namespace std;


void printN(int n ){
    if(n  == 0){
        return ;
    }

    cout << n << " ";
    printN(n-1);
}

int main(){

    int n =  5;

    printN(n);
}