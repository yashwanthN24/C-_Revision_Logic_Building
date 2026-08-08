#include <iostream>

using namespace std;

void printarr(int arr[][4] , int n , int m){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0;j<m ;j++){
            cout << arr[i][j] <<  " ";
        }
        cout << endl;
    }
}   

int searchInSortedArray(int arr[][4] , int n , int m , int key){
    int row = n-1 , col = 0;
    while(row >= 0 && col < m){
        if(arr[row][col] == key){
            cout << "Found at : " << row << " , " << col << endl;
            return 1;
        }else if(arr[row][col] > key){
            row--;
        }else{
            col++;
        }
    }   
    cout << "Element not found" << endl;
    return 0;
}

int main(){
    int arr[4][4] = {
        {10 , 20 , 30 , 40},
        {15 , 25 , 35 , 45},
        {27 , 29 , 37 , 48},
        {32 , 33 , 39 , 50}
    };

    printarr(arr , 4 , 4);
    cout <<  searchInSortedArray(arr , 4 , 4 , 29);
    
}