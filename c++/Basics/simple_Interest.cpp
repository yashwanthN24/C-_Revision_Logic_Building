#include <iostream>

using namespace std; 

int main(){
    float p , r , t , si ; 
    cout << "Enter principle amount: " << endl ; 
    cin >> p ; 
    cout << "Enter rate of interest: " << endl ; 
    cin >> r ; 
    cout << "Enter time in years: " << endl ; 
    cin >> t ; 

    si = (p*r*t)/100; 

    cout << "Simple Interest is : " << si << endl ; 
}