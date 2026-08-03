#include <iostream>

using namespace std;

int main(){
    float n1 , n2 , n3 , res ; 
    cout << "Enter 3 numbers : " << endl ; 
    cin >> n1 >> n2 >> n3 ; 
    res = (n1+n2+n3)/3; 
    cout << "Average of " << n1 << " " << n2 << " " << n3 << " is : " << res << endl; 
    return 0 ; 
}