#include <iostream>

using namespace std; 

int main(){
    int val = 1 ; 

    do{
        cout << " Hello in do-while loop " << endl ; 
    }while(val > 5 );

    while(val > 5 ){
        cout << " Hello in while loop " << endl ; 
    }
    return 0 ; 
}