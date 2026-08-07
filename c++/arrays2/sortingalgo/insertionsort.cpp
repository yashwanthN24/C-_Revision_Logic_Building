#include <iostream>

using namespace std;

void printarr(int *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}

void insertionsort(int *arr , int n ){

    for(int i = 1 ; i<n ; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main(){
    int arr[] = {18 , 1 , 78 , 102 , 90};
    int n = sizeof(arr)/sizeof(int);

    printarr(arr , n );
    insertionsort(arr , n);
    printarr(arr , n);
}