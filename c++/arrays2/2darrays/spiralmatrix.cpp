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

void spiralmatrix(int arr[][4], int n, int m){
    int srow = 0 , scol = 0 , erow = n-1 , ecol = m-1;
    while(srow <= erow && scol <= ecol){
        // top 
        for(int i = scol ; i<=ecol ; i++){
            cout << arr[srow][i] << " ";
        }   
        // right
        for(int i = srow+1 ; i<=erow ; i++){
            cout << arr[i][ecol] << " ";
        }
        // bottom
        for(int i = ecol-1 ; i>=scol ; i--){
            if(srow == erow){
                break;
            }
            cout << arr[erow][i] << " ";
        }
        // left
        for(int i = erow-1 ; i>srow ; i--){
            cout << arr[i][scol] << " ";
        }
        srow++ , scol++ , erow-- , ecol--;
    }
}

int main(){
    int arr[4][4] = {{1 , 2 , 3 , 4},
                   {5 , 6 , 7 , 8},
                   {9 , 10 , 11 , 12},
                   {13 , 14 , 15 , 16}
                 };
    // int arr[][4] = {{1 , 2 , 3 , 4},
    //                {5 , 6 , 7 , 8},
    //                {9 , 10 , 11 , 12},
    //                {13 , 14 , 15 , 16}
    //              };
    int n = 4 , m = 4;
    printarr(arr , n , m);
    cout<<endl;

    spiralmatrix(arr , n , m);
    // printarr(arr , n , m);
    return 0;
}