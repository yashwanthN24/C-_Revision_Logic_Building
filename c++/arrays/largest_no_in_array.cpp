#include <iostream>

using namespace std;

int main(){
    int arr[] = { 7 , 0 , 2 , 9 , 1};
    int min = arr[0] ,  max = arr[0];
    int size = sizeof(arr) / sizeof(int);
    for(int i = 1 ; i<size ; i++){
        if(arr[i] > max){
            max = arr[i];
        }else if(arr[i] < min){
            min = arr[i];
        }
    } 

    cout << "smallest element in array is : " << min << endl;
    cout << "largest element in array is : " << max << endl;

    return 0 ; 
}