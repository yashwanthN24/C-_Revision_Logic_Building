#include <iostream>

using namespace std;

void printOneToN(int n , int count){
    if(count == n){
        return ;
    }
    cout << count + 1 << " ";
    printOneToN(n , count + 1);
}

int main(){

    int n = 5;

    printOneToN(n , 0);
}