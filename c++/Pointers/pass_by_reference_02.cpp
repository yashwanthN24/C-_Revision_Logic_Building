#include <iostream>

using namespace std;

void change(int &);

int main(){

    int x = 10; 
    change(x);

    cout << x << endl;
}

void change(int &a){
    a = 20;
    cout << a << endl; 

}

// https://chatgpt.com/c/6a74c7ec-7840-83ee-975a-07de74e67054

// https://chatgpt.com/c/6a74c7ec-7840-83ee-975a-07de74e67054