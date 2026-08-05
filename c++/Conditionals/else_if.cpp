#include <iostream>

using namespace std ; 

int main(){
    int marks ; 
    cout << "Enter your marks :" ; 
    cin >> marks ; 

    if(marks > 80){
        cout << "pass" << endl ; 
    }else if (marks > 60){
        cout << "average" << endl ;
    }else{
        cout << "fail" << endl ; 
    }
    return 0 ; 
}