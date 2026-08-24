#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void binaryStrings(int n , string str , vector<string> &ans){
    if(n == 0){
        // cout << str << endl;
        ans.push_back(str);
        return;
    }
    if(str[str.size()-1] != '1'){
        binaryStrings(n-1 , str + "0" , ans);
        binaryStrings(n-1 , str + "1" , ans); 
    }else{
        binaryStrings(n-1 , str + "0" , ans);
    }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        // Your code goes here
        binaryStrings(n , "" , ans);
        return ans;
    }
};
