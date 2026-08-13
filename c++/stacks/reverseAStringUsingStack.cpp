#include <iostream>
#include <stack>

using namespace std;

string reverseString(string s){
    stack<char> st;
    for(int i = 0 ; i < s.length() ; i++){
        st.push(s[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans; 
}

int main(){
    string str = "abdcdef";

    cout << reverseString(str) << endl;

}

// TC: O(n) where n is the length of the string.
// SC: O(n) where n is the length of the string. for the stack used to store the characters of the string.