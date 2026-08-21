#include <bits/stdc++.h>

using namespace std;


// first loop for transposing 

// 2nd loop for reversing each row 
class Solution {
public:
    // void reverse(vector<int> &arr){
    //     int start = 0 , end = arr.size()-1;
    //     while(start<end){
    //         swap(arr[start++] , arr[end--]);
    //     }
    // }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0 ; i<=n-2 ; i++){
            for(int j = i+1 ; j<=n-1 ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }

           
        }

        for (int i = 0; i < n; ++i) {
            // Reverse the current row to complete clockwise rotation
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};