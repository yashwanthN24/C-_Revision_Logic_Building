#include <iostream>

using namespace std;

template<size_t N>
void printArray(int (&arr)[N]){
    for(int i = 0 ; i<N ; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void reverse(int *arr , int size , int start  , int end ){
    if(start >= end){
        return ;
    }

    swap(arr[start] , arr[end]);
    reverse(arr , size , start+1 , end-1);
}

int main(){

    int arr[] = { 1 , 2 , 5 , 8 , 10};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    printArray(arr);
    
    reverse(arr , n ,  0 , n-1);

    printArray(arr);

}

// https://chatgpt.com/c/6a856082-b5bc-83e8-9fd2-b3baba6a7daf