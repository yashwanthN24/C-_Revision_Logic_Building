#include <iostream>

using namespace std;

void printArr(int *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;       
}

int partition(int *arr , int low , int high){
    int pivot = arr[high]; // pivot element is last index element 

    int i =  low-1 ;  // to point to one element before the start 

    for(int j = low ; j<high ; j++){

        if(arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    i++;
    swap(arr[i] , arr[high]); 
    return i ; 
}


void quickSort(int *arr , int low , int high){
    if(low >= high){
        return ;
    }

    int pivotindex = partition(arr , low , high);
    quickSort(arr , low , pivotindex-1);
    quickSort(arr , pivotindex+1 , high);
}

int main(){
    int arr[] = {6 , 2 , 4 , 1 , 5 , 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArr(arr , n);

    quickSort(arr , 0 , n-1);

    printArr(arr , n);

    // strings in c++ are mutable string each time new string bobject creatd for any small modification  so we can take it as reference like string &s then you dealing with the same string each time 

    // just like stringbuilder in java  that is same string all time 
    
    






}