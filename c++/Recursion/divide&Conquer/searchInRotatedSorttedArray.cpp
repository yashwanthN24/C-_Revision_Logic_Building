#include <iostream>

using namespace std;

int searchRotatedSortedArray(int *arr , int low , int high , int key){
    if(low > high){
        return -1;
    }

    int mid = low + (high - low)/2;

    if(arr[mid] == key){
        return mid;
    }   

    if(arr[low] <= arr[mid]){
        if(key >= arr[low] && key <= arr[mid]){
            return searchRotatedSortedArray(arr , low , mid-1 , key);
        }else{
            return searchRotatedSortedArray(arr , mid+1 , high , key);
        }
    }else{
        if(key >= arr[mid] && key <= arr[high]){
            return searchRotatedSortedArray(arr , mid+1 , high , key);
        }else{
            return searchRotatedSortedArray(arr , low , mid-1 , key);
        }
    }
}
    

int main(){
    int arr[] = {4 , 5  , 6 , 7 , 0 , 1 , 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << searchRotatedSortedArray(arr , 0 , n-1   , 7) << endl;
}