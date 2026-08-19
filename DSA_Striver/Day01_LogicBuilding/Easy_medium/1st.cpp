/*

    Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:



*****

*****

*****

*****

*****



Print the pattern in the function given to you.


*/
#include <bits/stdc++.h>  // header file for all common things in competitive programming includes everything stl data structures and algorithms

using namespace std;

int main(){

    int n;
    cin>>n; // take input from user
    for(int i=0;i<n;i++){ // loop for rows
        for(int j=0;j<n;j++){ // loop for columns
            cout<<"*"; // print * in each column
        }
        cout<<endl; // after each row print new line
    }
    return 0;
}
