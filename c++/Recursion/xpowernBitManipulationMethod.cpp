#include <iostream>

using namespace std;

int xpoweredN(int x , int n ){
    int ans = 1 ; 

    while(n>0){
        if((n&1) !=0){
            ans *= x;
        }
        x= x*x;
        n = n >> 1 ;
    }

    return ans;
}

int main(){

    int x = 3;
    int n = 5;

    cout << xpoweredN(x , n);
}