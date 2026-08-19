#include <iostream>

using namespace std;

int fib(int n){
    // if(n == 0 || n == 1){
    //     return n ;
    // } 

    // above one wghen your counting terms from 0th term so first terms start from 0 and second 1 and third 2 ..... 


    // below if we count terms from 1 

    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}


int main(){

    int n = 5;

    // print first 5 fibonacci numbers
    
    int a = 0 , b = 1;
    for(int i = 0 ; i<n ; i++){
        cout << a << " ";

        int c = a + b;
        a = b;
        b = c;
    }

    cout << endl << fib(5) << endl;
}