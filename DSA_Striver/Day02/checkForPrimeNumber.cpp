// A prime number is a that is divisble by 1 and number itslf 

// A compositre number has more than 2 factors divisible 1 and itself and multiple factors 

// 1 is neither prime nor composite number (its a odd number)

#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int a = 6;
    bool isPrime = true;

    for(int i =2 ; i<sqrt(a) ; i++){
        if(a % i == 0){
            isPrime = false; 
            break;
        }
    }

    cout << isPrime << endl;
}

// upto sqrt beacuse the factor repeat like we saw in divisors problem so if we cover upto sqrt(n) factors enoigh because they repeat again ex for 6 2* 3 and 3 *2 so uif we check 2 enough  as itself is any extra factor  apart from 1 and the number itself that makes it non-prime number 