#include <iostream>

using namespace std;

int binarySearch(int *arr , int low , int high , int key){
    if(low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if(arr[mid] == key){
        return mid;
    }else if(key > arr[mid]){
        return binarySearch(arr , mid+1 , high , key);
    }else{
        return binarySearch(arr , low , mid-1 , key);
    }

}

int main(){
    int arr[5] = {1 , 2 , 3 , 4 , 5};   

    cout << binarySearch(arr , 0 , 4 , 3) << endl;
}