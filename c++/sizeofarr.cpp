#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int arr[]  { 10 , 20 , 30 , 40 , 50};

    int n = *(&arr + 1) - arr; // because &arr + 1 gives u next array address of offset 5 elements here and we rederefnce and we get the actual array which address of first lemenet in the address so difference between that and this is 
    
    

    cout << n << " " << endl;


    char s[] = "hello";
    cout << sizeof(s) << " " <<  strlen(s) << endl; // sizeof counts size of the enrtire array including \0 charatcer for srrings and strlen calculates only the actuall length excluding the \o charActer 

    // Arrays.fill(arr , -1) fills all values with -1 value
    // int arr[] = new int[10];

    cout << "\\n" << endl ; // to print \n \escaoes trghe second\


    // in java 

    // #define true 0 

    // #define H printf


    // print hello without using printf 

    // #define H printf("Hello World"); // in man jys do H done 
}