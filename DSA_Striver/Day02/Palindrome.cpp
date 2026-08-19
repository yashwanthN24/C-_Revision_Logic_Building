#include <iostream>

using namespace std;


int main(){
    int n = 121 , org = n , rev = 0;

    while(n){
        int digit = n % 10;
        rev = rev*10 + digit;
        n /= 10;
    }

    cout << (rev == org) ;
}