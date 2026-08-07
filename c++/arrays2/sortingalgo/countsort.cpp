#include <iostream>

using namespace std;

void printarr(int *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}

void countingSort(int *arr , int n){
    // find max element in array
    int largest = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        largest = max(largest , arr[i]);
    }

    int count[largest+1]= {};
    for(int i = 0 ; i<n ; i++){
        count[arr[i]]++;
    }
    int j = 0;
    int countarraylength = sizeof(count)/sizeof(int);
    for(int i = 0;i<countarraylength;i++){
        while(count[i]>0){
            arr[j++] = i;
            count[i]--;
        }
    }
}

int main(){
    int arr[] = { 45 , 8 , 67 , 98 , 2};
    // int arr[] = { 4 , 1 , 3 , 2 , 4 , 3 , 7};
    int n = sizeof(arr)/sizeof(int);

    printarr(arr , n);
    countingSort(arr , n); // works well only for positive numbers with smaller numbersrange like rooll number or marks 90-100 max dont run it for lemn havingvalues over 1000
    printarr(arr , n);

}
