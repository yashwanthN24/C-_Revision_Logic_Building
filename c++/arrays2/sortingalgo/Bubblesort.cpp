#include <iostream>

using namespace std;

void printarr(int *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}

void bubblesort(int *arr , int n ){

    for(int i = 0 ;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

// optimization for bubble sort when array is already sorted 
void bubblesort2(int *arr , int n ){

    for(int i = 0 ;i<n-1;i++){
        bool isSwap = false;
        cout << "Outer loop" << endl;
        for(int j = 0;j<n-1-i;j++){
            cout << "Inner loop" << endl;
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                isSwap = true;
            }
        }

        if(!isSwap){
            cout << "Array is already sorted " << endl;
            return ;
        }
    }
}

int main(){

    // int arr[] = { 10 , 1 , 45 , 78 , 102 , 98};
    int arr[] = { 10 , 20 , 30 , 40 , 50 };

    int n = sizeof(arr) /sizeof(int);
    printarr(arr , n);
    bubblesort2(arr , n);
    printarr(arr , n);
}