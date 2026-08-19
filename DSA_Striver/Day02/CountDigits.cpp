#include <iostream>
// #include <algorithm>
#include <cmath>

using namespace std;

int main(){

    int N = -10 , count = 0;

    int org = N;
    while(N){
        count++;
        N /= 10;
    }

    cout << count << " " ;


    // This O(n) solution where n is the length of the digit 


    // even simpler approach is 
    int count2 = 0;
    count2 = (int)(log10(org) +1);  //  1 to handle powers of 2 case 

    cout << count2; 

    // in java use 

    // https://chatgpt.com/c/6a852dbc-8248-83ee-99fa-b304d56dd3b1

    // Math.log10(N) // but gives -infoty for  N = 0 so handle that case  same for c++ also so bot h case 
}

// https://chatgpt.com/c/6a852ec5-6960-83e8-bf92-6d88ccdb2b4a