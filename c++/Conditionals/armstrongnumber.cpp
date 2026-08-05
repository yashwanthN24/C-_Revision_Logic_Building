#include <iostream> 

using namespace std ;

int main(){
    int n ; 
    cout << "Enter a number :"  ;
    cin >> n ; 
    int original = n , sum = 0 ; 
    while(n){
        int digit = n % 10 ; 
        int cube = digit * digit * digit ; 
        sum += cube ;
        n /= 10 ;
    }
    if(sum == original){
        cout << original << " is an Armstrong number." << endl ;
    }
    else{
        cout << original << " is not an Armstrong number." << endl ;
    }

}