#include <iostream>

using namespace std;

void printSumofN(int i , int n , int sum ){
    if(i == n + 1){
        cout << sum << endl;
        return ;
    }

    printSumofN(i+1 , n , sum + i);

}

int main(){

    int n = 5;

    int sum = 0;

    printSumofN(0 , n , sum);
}