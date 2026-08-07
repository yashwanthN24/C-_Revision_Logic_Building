// array is a constant pointer cant make it point to anyting else even arr++ also error 


#include <iostream>

using namespace std; 

int main(){

    int arr[] = { 1 , 2 , 3 , 4};
    cout << arr << endl; 
    // cout << arr++ << endl; // same constant pointer
    int arr2[] = { 1 , 67 , 890 , 78};
    // arr = arr2; // error as arr is a constant poiinter 

    int a = 7;
    int * const p = &a; // now p also constant pointer means you can change value piinted by p but cant make p to point anything else as the popiter is const 



    *p = 20; //valid as we are modifying the value pointed by the pointer p 
    cout << *p << " " << a << endl;
    // p = nullptr;// error as constant pointer 
}
