#include <iostream>

using namespace std;

int main(){

    // int arr[] = { 12 , 99 , 23 , 89 , 1};

    // int arr[] = {10 , 90 , 17 , 6 , 100};

    int arr[] = { 10 , 90 , 17 , 100 , 100};


    int size = sizeof(arr)/sizeof(int);
    int max = arr[0] , secmax = max;

    for(int i = 1 ; i<size ; i++){
        if(arr[i]> max){
            secmax = max;
            max =arr[i];

        }else if (arr[i]>secmax && arr[i] !=max){
            secmax = arr[i];
        }
        
    } 

    cout << secmax << " " << max << endl;
}