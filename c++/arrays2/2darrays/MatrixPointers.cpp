#include <iostream>

using namespace std;

void printarr(int arr[][3] , int n ){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0;j<n ;j++){
            cout << arr[i][j] <<  " ";
        }
        cout << endl;
    }
}
void printarr(char (*arr)[3], int n ){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0;j<n ;j++){
            cout << arr[i][j] <<  " ";
        }
        cout << endl;
    }
}



int main(){
   

    int arr[3][3] = {{1 , 2 , 3},
                     {4 , 5 , 6},
                     {7 , 8 , 9}

                     };
    int n = 3 , m = 3;
    printarr(arr , n );
   
    // 2d arrays when passed to function becomes pointer to array of size 3 (in this case) and hence we can use pointer notation to access the elements of the array so arr denotes the base address of first 1D array and arr[i] denotes the base address of the ith 1D array and arr[i][j] denotes the jth element of the ith 1D array. Hence we can use pointer notation to access the elements of the 2D array as shown below.
}