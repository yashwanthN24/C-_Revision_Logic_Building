#include <iostream>

using namespace std; 

int main(){

    int x = 10;
    int *p = &x;

    cout << p << endl; 
    cout << *p << endl; 

    cout << &x << " == " << p << endl ; 

    float a = 3.142; 
    float *ptr = &a ; 

    cout << " size of float pointer : " <<  sizeof(ptr) << endl; 
    cout << " size of int pointer : " <<  sizeof(p) << endl; 

    // *(int*)0 = 0 ;

    // int *ptr2 = 0;
    // *ptr2 = 0;

    cout << " Not excuted " << endl ; 

    int *b3 = nullptr;
    char *c = 0x0;
    double *f = NULL;

    cout << *b3 << *c << *f;
}