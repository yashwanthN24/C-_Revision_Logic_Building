#include <iostream>

#include <stack>

using namespace std;

bool isDuplicateParenthesis(string str){
    stack<char> st;
    for(int i = 0 ; i < str.length() ; i++){
        char ch = str[i];
        if(ch != ')'){
            // if it is any operand operator or opening parethesis puhs ntop stack
            st.push(ch);
        }else{

            // since its a closing parethesis we will check if there is a immeidtae matching pair if so its a dulicate 
            if(st.top() == '('){
                return true;
            }

            // else we will pop all the elements till we get the matching opening parethesis
            while(st.top() != '('){
                st.pop();
            }
            st.pop(); // pop the opening parenthesis

        }

    }
    return false; // if we reach here then there is no duplicate parenthesis
}


int main(){
    string str = "((a+b))";

    cout << isDuplicateParenthesis(str) << endl;
}