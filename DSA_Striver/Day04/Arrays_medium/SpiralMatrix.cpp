// Spiral traversal on matrix 
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startrow = 0 , endrow = matrix.size()-1 , startcol = 0 , endcol = matrix[0].size()-1;

        vector<int> result;

        while(startrow <= endrow && startcol <= endcol){

        
        // top 
        for(int i = startcol ; i<=endcol ; i++){
            result.push_back(matrix[startrow][i]);
        }

        // right 
        for(int i = startrow + 1 ; i<=endrow ; i++){
            result.push_back(matrix[i][endcol]);
        }

        // bottom 
        for(int i = endcol-1 ; i>=startcol ; i--){
            if(startrow == endrow) break;
            result.push_back(matrix[endrow][i]);
        }


        // left 
        for(int i = endrow -1 ; i>=startrow+1 ; i--){
            if(startcol == endcol) break;
            result.push_back(matrix[i][startcol]);
        }
        startrow++;
        startcol++;
        endcol--;
        endrow--;
        }
        return result;
    }
};