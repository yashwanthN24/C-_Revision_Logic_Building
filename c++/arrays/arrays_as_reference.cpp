#include <iostream>

using namespace std; 

void printarr(int arr[] , int n ){
    cout << sizeof(arr) << endl; // 8 as arrays decay to pointer when pased to functions 

    for(int i = 0 ; i<n ; i++){
        cout << arr[i] <<  " ";
    }
}

int main(){
    int arr[] = { 10 , 20 , 30 };
    cout << sizeof(arr) << endl;

    int n = sizeof(arr) /sizeof(int);
    printarr(arr , n);
}