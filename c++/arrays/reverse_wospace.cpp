#include <iostream>

using namespace std; 

// void swap(int arr[] , int first , int last){
//     int temp = arr[first];
//     arr[first] = arr[last];
//     arr[last] = temp;
// }

int main(){
    int arr[] = { 5 , 4 , 3 , 2  , 1 , 1};
    int size = sizeof(arr)/sizeof(int);
    int first = 0;
    int last = size -1;

    while(first < last){
        // swap(arr , first , last); 

    // or can use inbuilt swap method of c++
    // swap(val1 , val2);
        swap(arr[first] , arr[last]);
        first++;
        last--;
    }

    for(int i = 0 ; i<size ; i++){
        cout << arr[i] <<  " " ; 
    }

}