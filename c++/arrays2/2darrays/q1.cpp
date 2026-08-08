#include <iostream> 

using namespace std; 

void print7ssum(int arr[][3] , int n , int m){
    int count = 0 ; 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr[i][j] == 7){
                count += 1;
            }
        }

    }
    cout << "Sum of 7s in the matrix is : " << count << endl  ;
}

int main(){
     int arr[ ][ 3] = { {4,7,8}, {8,8,7} };

     
    
     print7ssum(arr , 2 , 3);

}