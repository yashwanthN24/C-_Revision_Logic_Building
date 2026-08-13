#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void nextGreaterElement(vector<int> &arr , vector<int> &ans){

    stack<int> st;

    // ans[arr.size() - 1] = -1; 
    // st.push(arr[arr.size() - 1]);  
    for(int i = arr.size() - 1 ; i >= 0 ; i--){
        int curr = arr[i];

        while(!st.empty() && curr >= st.top()){
            st.pop();
        }

        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }

        st.push(curr);
    }
}


        
        



int main(){
    // vector<int> arr = {4, 5, 2, 25};
    vector<int> arr = {6 , 8 , 0 , 1 , 3};

    vector<int> ans(arr.size() , 0);

    nextGreaterElement(arr , ans);

    for(int c: ans){
        cout << c << " ";   
    }

    return 0;
}
