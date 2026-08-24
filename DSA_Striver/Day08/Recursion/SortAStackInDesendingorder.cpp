#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void insertAtDescendingSort(stack<int> &st , int value){
        if(st.empty() || st.top() <= value ){
            st.push(value);
            return;
        }

        int elem = st.top();
        st.pop();
        insertAtDescendingSort(st , value);
        st.push(elem);
    }
    
    void sortStack(stack<int> &st) {
        // Your code goes here
        if(st.empty()) return;

        int elem = st.top();
        st.pop();

        sortStack(st);

        insertAtDescendingSort(st , elem);
        
    }
};