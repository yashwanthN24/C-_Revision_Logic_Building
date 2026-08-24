#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void pushAtBottom(stack<int> &st , int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }

        int item = st.top();
        st.pop();
        pushAtBottom(st , ele);
        st.push(item);
    }
    void reverseStack(stack<int> &st) {
        // Your code goes here
        if(st.empty()) return;

            int elem = st.top();
        st.pop();
        reverseStack(st);
    
        pushAtBottom(st , elem);

    }
};