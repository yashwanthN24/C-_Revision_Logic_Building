#include <iostream>
#include <vector>


using namespace std;

int main(){

    int n = 6;

    vector<int> f(n+1 , 0);

    f[0] = 0;
    f[1] = 1;

    for(int i = 2 ; i<=n ; i++){// must include n as we want to update he fibnoci of n element as weell as the fib arry is of size n +1 
        f[i] = f[i-1] + f[i-2];
    }

    cout << f[n] << endl;
}