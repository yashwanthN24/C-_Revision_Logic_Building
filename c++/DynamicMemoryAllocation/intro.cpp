#include <iostream>

using namespace std;

int main(){
    int size; 
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocate memory for the array 
    int *arr = new int[size];

    cout << *arr << endl; // This will print the value of the first element in the array (which is uninitialized)
    int x = 1;
    for(int i = 0 ; i < size; i++){
        arr[i] = x++;
        // arr[i] = i++;  undefined behvaiour never write this in c++ and c 
        cout << arr[i] << " ";
        // x++;
    }
    delete[] arr; // Deallocate the dynamically allocated memory

    cout << endl;
    int *p = new int(10); // Dynamically allocate memory for a single integer and initialize it to 10

    cout << *p << endl; // This will print the value of the dynamically allocated integer (which is 10)

    delete p; // Deallocate the dynamically allocated memory for the single integer 

    p = nullptr; // Set the pointer to nullptr after deallocation to avoid dangling pointer
    
    return 0;
}