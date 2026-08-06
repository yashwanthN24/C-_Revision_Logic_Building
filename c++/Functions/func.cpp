#include <iostream>

using namespace std;

void sayHello();

int sum(int a , int b=1){

    // defaut paraneter must akways be the last parameter in the function declaration
    int c = a + b ;
    return c ; 
}

int main(){
    sayHello();

    int s = sum(5, 6);
    cout << s << endl; 
    return 0 ; 

}

void sayHello(){
    cout << "Hello World" << endl;
}   

// https://chatgpt.com/c/6a730648-5788-83ee-8ac8-123c0fd4748c

// https://chatgpt.com/c/6a730648-5788-83ee-8ac8-123c0fd4748c

