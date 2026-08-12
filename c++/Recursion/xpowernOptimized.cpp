#include <iostream>

using namespace std;

int xpowerN(int x ,int n){
    if(n==1){
        return x;
    }

    int haffsquares = xpowerN(x , n/2);

    if(n % 2 != 0){
        return  x * haffsquares * haffsquares;
    }

    // works for even power for odd power should multipy by x again 
    return haffsquares * haffsquares;
}

int main(){
    int x = 3 ;
    int n = 3;
    cout << xpowerN(x , n) << endl;
}