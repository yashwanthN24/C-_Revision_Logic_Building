#include <iostream>


using namespace std;    

int main(){

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate memory for a 2D array
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }

    // Initialize and print the 2D array
    int value = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = value++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the dynamically allocated memory for the 2D array
    for(int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}