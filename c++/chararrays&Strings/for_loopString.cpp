#include <iostream>

using namespace std; 

int main(){
    string str = "yash"; 

    for(int i = 0 ; i<str.length() ; i++){
        cout << str[i] << " ";  
    }
    cout << endl; 

    // for each loop in c++ we can use the range based for loop to iterate over the elements of the string and print them. 

    for(char ch : str){
        cout << ch << " ";
    }

    cout << endl;
}