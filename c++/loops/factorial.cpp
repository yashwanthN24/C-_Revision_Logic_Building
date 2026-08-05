#include <iostream>

using namespace std; 

int main(){
    int n ; 
    cout << "Enter a number tp find factorial for  : " ; 
    cin >> n ; 

    int fact = 1 ; 
    for(int i =1 ; i<=n ; i++){
        fact *= i ; 
    }
    /*
    
    for(int i = n ; i>=1 ; i--){
        fact *= i ; 
    }

    */
    cout << "Factorial of " << n << " is : " << fact << endl ; 
    return 0 ; 

}