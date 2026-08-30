#include <iostream>

using namespace std;


template<size_t N> // template to hanldle array reference to any array size  
void printArray(int (&arr)[N]){
    for(int i = 0 ; i<N; i++ ){
        cout<<arr[i]<<" ";  
    }
    cout << endl;
}

void changeArray(int (&arr)[5] , int i){ // arr reference to actuyal array of exact 5 elements 
    if(i == 5){
        printArray(arr);
        return ;
    }

    arr[i] = i+1;
    changeArray(arr , i+1);
    // arr[i] = arr[i] -2; or 
    arr[i] -= 2;

}

int main(){
    int arr[5] = {0};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr);
    // changeArray(arr , size , 0);
    changeArray(arr , 0);
    printArray(arr);

}


// https://chatgpt.com/c/6a93e642-fde8-83ee-b1bd-e7b20c5f71dd

// https://chatgpt.com/c/6a93e642-fde8-83ee-b1bd-e7b20c5f71dd

