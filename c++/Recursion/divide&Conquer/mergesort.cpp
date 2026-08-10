#include <iostream>
#include <vector>

using namespace std;

void printArr(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr , int low , int high , int mid){
    int i = low ; 
    int j = mid+1;

    vector<int> temp;
    temp.reserve(high-low+1);

    int k = 0;
    while(i<=mid && j <= high){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }   

    while(j<=high){
        temp.push_back (arr[j++]);
    }   

    for(int i = low , k = 0 ; k<temp.size() ; i++ , k++){
        arr[i] = temp[k];
    }
}

void mergesort(int *arr , int low , int high){
    if(low >= high){
        return;
    }

    int mid = (low + high)/2;
    mergesort(arr , low , mid);
    mergesort(arr , mid+1 , high);
    merge(arr , low , high , mid);
}

int main(){

    int arr[] = { 23 , 2 , 12 , 7 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n);

    mergesort(arr , 0 , n-1);

    printArr(arr , n);
    return 0;
}