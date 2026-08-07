#include <iostream>

using namespace std; 

int main(){

    int arr[] = { 2 , 6 , 8 , 9 , 5};
    int size = sizeof(arr)/sizeof(int);
    int copyarr[size]; 

    for(int i = 0 ; i<size ; i++){
        int lastindex = size - 1 - i ;
        copyarr[i] = arr[lastindex];
    }

    for(int i = 0; i<size ; i++){
        arr[i] = copyarr[i];
    }

    for(int i = 0 ; i<size ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}