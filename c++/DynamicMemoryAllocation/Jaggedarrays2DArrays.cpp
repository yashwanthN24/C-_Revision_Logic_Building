#include <iostream>

using namespace std;

int main(){
    int cols[] = {3, 4, 2}; // Number of columns for each row

    int rows = 3;

    int **arr = new int*[rows]; // Dynamically allocate memory for the array of row pointers

    for(int i =0 ; i < rows; i++){
        arr[i] = new int[cols[i]]; // Dynamically allocate memory for each row based on the number of columns
    }

    int x = 1 ;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols[i]; j++){
            arr[i][j] = x++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   

    for(int i = 0; i < rows; i++){
        delete[] arr[i]; // Deallocate memory for each row
    }   
    delete[] arr; // Deallocate memory for the array of row pointers
    return 0;
}