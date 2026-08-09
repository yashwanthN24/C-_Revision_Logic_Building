#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> matrix = {{1 , 2 , 3} , { 4 , 5 , 6} , {7, 8 ,9}};

    for(int i = 0 ;i<matrix.size(); i++){
        for(int j = 0 ; j<matrix[i].size() ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> jaggedarray = {{1 ,2 , 3} , {5 , 6} , {9}};
    // in 2D array we cant do this however 2D dynamic arrays in heap we cn do this and even in vectors we can injava we can do all because its all in heap 

    for(int i = 0 ; i< jaggedarray.size() ; i++){
        for(int j = 0;j<jaggedarray[i].size(); j++){
            cout << jaggedarray[i][j] << " ";
        }
        cout << endl;
    }
}