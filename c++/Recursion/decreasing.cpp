#include <iostream>

using namespace std;

void printDecreasing(int n){
    if(n == 1){
        cout << n << endl;
        return;
    }
    cout << n << " " ;
    printDecreasing(n-1);
}
void printIncreasing(int n){
    if(n == 1){
        cout << n <<  " ";
        return;
    }
    printIncreasing(n-1);
    cout << n << " " ;
}

int main(){
    int n = 5;
    printDecreasing(n);
    printIncreasing(n);
}