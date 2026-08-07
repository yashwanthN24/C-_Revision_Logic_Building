#include <iostream>

using namespace std;


void printarr(int *arr , int n ){
    for(int i = 0 ; i<n ; i++){
        cout << *arr++ << " ";
    }
    cout << endl;
}
// for descendng same logic just change the sign to >
void selectionsort(int *arr , int n){

    for(int i = 0 ;i<n-1 ; i++){
        int minpos = i;
        for(int j = i+1 ; j<n;j++){
            if(arr[j] < arr[minpos]){
                minpos = j;
            }
        }
        swap(arr[i] , arr[minpos] );
    }

}

int main(){

    int arr[] = { 12 , 8 , 89 , 34,90};
    int n = sizeof(arr)/sizeof(int);

    printarr(arr , n);
    
    selectionsort(arr , n);

    printarr(arr , n);

}