#include <iostream>

using namespace std;

int gcd(int a , int b ){
    if(b == 0){
        return a ;
    }

    return gcd(b , a%b);
}

int LCM(int a , int b){
    return (a*b)/gcd(a , b);
    //  because gcd means hcf 
    // product of any two positive numbers = HCf * LCM 
    // so LCM = product of two nymbers / HCF 
}   

int main(){
    int a = 8 , b = 4;

//    HCF means highest number that divides both the numbers 

// LCM means smallest number that is a multiple of all the numbers here a and b 

//  Dividend the number being divided 
// didvisor the number being didvie by  ex /2 
// dividend = diviosr * quotient + remainder 
// Ex : 13/2 = here 13 is didviden = 2 is divisor  = 6 is quotient and 1 is remainder
// so 6 * 2 + 1 = 13  ie quotient * divisor + remainder = dividend  

    cout << a << endl;

    cout << gcd(a , b) << endl;
    cout << LCM(a, b) << endl;
}