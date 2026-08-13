#include <iostream>
#include <stack>

using namespace std;

bool isValidParenthesis(string str){

    stack<char> st;

    for(int i = 0 ; i < str.length() ; i++){
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            // insufficient open parenthesis case stack is empty so repturn faslse
            if(st.empty()){
                return false;
            }

            // check for pair valid paid () {} [] 
            char top = st.top();
            if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                st.pop();
            }
            else{
                return false;
            }   


        }
        
        
        
    }
    return st.empty(); // if stack is empty then all parenthesis are valid else invalid so left insufficent closed parenthesis so few open  parenthesis left over
}
    

int main(){
 string str = "({[]})";
    cout << str << endl;

    string st2 = "({[})";
    string st3 = "({[]}";
     cout << isValidParenthesis(str) << endl;
     cout << isValidParenthesis(st2) << endl;
     cout << isValidParenthesis(st3) << endl;
    return 0;
}