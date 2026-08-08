#include <iostream>

using namespace std;

void printarr(int (*arr)[4] , int n , int m ){
    for(int i = 0 ; i<n ;i++){
        for(int j = 0 ; j<m ; j++){
            cout << arr[i][j] << " " ;
        }
        cout << endl;
    }
}
void printarr(int (*arr)[3] , int n , int m ){
    for(int i = 0 ; i<n ;i++){
        for(int j = 0 ; j<m ; j++){
            cout << arr[i][j] << " " ;
        }
        cout << endl;
    }
}

  void transpose(int (*arr)[4] , int n , int m  , int (*trans)[3]){

    
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            trans[j][i] = arr[i][j];
            
        }
    }
}

int main(){
    int arr[3][4] = {
        {1 , 2 , 4 , 5},
        {12 , 45 , 56 , 67},
        {78 , 23 , 45 , 12},
    };

    int trans[4][3] = {{0}};

    printarr(arr , 3 , 4);

    cout << endl;
    transpose(arr , 3 , 4 , trans);

    

    printarr(trans , 4, 3);
}