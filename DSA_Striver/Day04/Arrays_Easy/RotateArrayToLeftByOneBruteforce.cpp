#include <iostream>

using namespace std;

void printArray(int *arr , int size){

    for(int i = 0 ; i<size ; i++){

        cout << arr[i] <<   " " ;
    } 
    cout << endl;
}

void RotateArrayByLeftByOne(int *arr , int n ){

    int tempArr[n]; // fine even with GV (Garvaage value as we will assign value not increment or decremnt 

    int firstEle = arr[0];

    for(int i = 1 ; i<n ; i++){
        tempArr[i-1] = arr[i];
    }

    tempArr[n-1] = firstEle;


    // print temparr or copy back to arr for inplace 

    printArray(tempArr , n );


    for(int i = 0; i< n ; i++){

        arr[i] = tempArr[i];
    }




}

int main(){


    int arr[] = { 1 , 2 , 3 , 4 , 5};

    int n = sizeof(arr)/sizeof(int);    

    printArray(arr , n );

    RotateArrayByLeftByOne(arr , n);

    printArray(arr , n);
}