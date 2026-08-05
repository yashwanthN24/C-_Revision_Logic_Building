#include <iostream>

using namespace std ; 

int main(){
    int n ;
    while(true){
        cout << "Enter a number : " ; 
        int count = scanf("%d", &n) ;
        if (count != 1) {
            while (getchar() != '\n');   // discard invalid input
            continue;
        }
        if(n % 10 == 0 ){
            break ;     
        }
    }

    cout << "You Entered" << n << " which is divisible by 10." << endl ;    
}


