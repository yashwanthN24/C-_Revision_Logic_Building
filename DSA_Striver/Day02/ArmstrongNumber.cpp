#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // Arm strong is a number which is equal to its each digit raised to number of digit sum all these digit must be equal to the number uitself 

    int n = 153;
    int org = n , sum = 0;
    int k = to_string(n).length(); // get number of digits

    while(n){
        int digit = n % 10;
        sum += pow(digit , k);
        n /= 10;
    }

    cout << (sum == org) << endl;



}