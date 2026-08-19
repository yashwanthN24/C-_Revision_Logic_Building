/*
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:



*

**

***

****

*****



Print the pattern in the function given to you. 
*/


#include <bits/stdc++.h>  // header file for all common things in competitive programming includes everything stl data structures and algorithms

using namespace std;

int main(){

    int n;
    cin>>n; // take input from user
    for(int i=1;i<=n;i++){ // loop for rows
        for(int j=1;j<=i;j++){ // loop for columns
            cout<<"*"; // print * in each column
        }
        cout<<endl; // after each row print new line
    }
    return 0;
}   


// https://chatgpt.com/c/6a84aa03-7198-83e8-813a-e0d2c449b65e