#include <bits/stdc++.h>  // header file for all common things in competitive programming includes everything stl data structures and algorithms

using namespace std;

int main(){
    int N = 5;

    vector<int> v;

    v.pop_back(); // This will cause undefined behavior since the vector is empty
    v.front(); // This will also cause undefined behavior since the vector is empty
}