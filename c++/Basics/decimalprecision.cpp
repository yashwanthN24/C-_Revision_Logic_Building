#include <iostream>
#include <iomanip>


using namespace std;

int main(){
    float a = 1.12345678901234567890;
    double b = 1.12345678901234567890;

    cout << "Value of float a: " << a << endl;
    cout << "Value of double b: " << b << endl; 


    // cout can print max 5 characters by default to change this we can use setprecision() function from iomanip library

    cout << setprecision(20) << "Value of float a with setprecision: " << a << endl; // Now we are saying cout that you can print max 20 characters in total 

    cout << setprecision(20) << "Value of double b with setprecision: " << b << endl; // Now we are saying cout that you can print max 20 characters in total

    // see output you will see float output not according in precision for decimal values but double output is according to precision for decimal values as float has 6 digits precision for decimal over double which has 15 digits precision for decimal values
}