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
     int nums[ ][3 ] = { {1,4,9}, {11,4,3}, {2,2,3} };
     int sum = 0;
     for(int i = 0;i<3 ; i++){
        cout <<  nums[1][i] <<  " ";
        sum += nums[1][i];
     }

     cout << endl;
     cout << " Sum of 2nd row : " << sum << endl;

     return 0 ; 
}