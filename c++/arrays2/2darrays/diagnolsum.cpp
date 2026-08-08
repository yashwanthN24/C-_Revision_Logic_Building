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

int diagnolsum(int arr[][3] , int n){
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum += arr[i][i]; // primary diagnol
        if(i != n-i-1){ // to avoid adding the intersecting element in case of odd size matrix
            sum += arr[i][n-i-1]; // secondary diagnol
        }
    }
    cout << "Sum of diagnols is : " << sum << endl;
    return sum;
}

int main(){
    // here matrix is always square matrix for this question we have to find sum of primary diagnol running from top-left to bottom-right and secondary diagnol running from top-right to bottom-left (excluding the intersecting element if the matrix is of odd size)

    int arr[3][3] = {{1 , 2 , 3},
                     {4 , 5 , 6},
                     {7 , 8 , 9}

                     };
    int n = 3 , m = 3;
    printarr(arr , n );
    diagnolsum(arr , n);
    
}