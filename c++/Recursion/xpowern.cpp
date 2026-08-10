#include <iostream>

using namespace std;

int xpowern(int x , int n ){
    if(n == 1){
        return x;
    }

    return x*xpowern(x , n-1);
}

int main(){
    int x = 2 , n = 3;
    cout << xpowern(x , n);
}