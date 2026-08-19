#include <iostream>

using namespace std;

void printN(int count , int n ){
    if(count == n + 1) return;

    printN(count + 1 , n);
    cout << count << " ";
}

int main (){

    int n = 5;

    printN(1 , n );
}