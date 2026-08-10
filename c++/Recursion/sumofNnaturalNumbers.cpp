#include <iostream>

using namespace std;

int printNNaturalSum(int n){
    if(n == 1){
        return 1;
    }
    return n + printNNaturalSum(n-1);
}

int main(){
    int n = 5;
    cout << printNNaturalSum(n) << endl;
}