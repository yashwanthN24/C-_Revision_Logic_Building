#include <iostream>
#include <stack>

using namespace std;

int evaluate(string expression) {
    stack<int> st;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression.at(i);

        switch (ch) {

        case '+': {
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            st.push(op1 + op2);
            break;
        }

        case '-': {
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            st.push(op2 - op1);
            break;
        }

        case '*': {
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            st.push(op1 * op2);
            break;
        }

        case '/': {
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            st.push(op1 / op2);
            break;
        }

        default:
            st.push(ch - '0');
            break;
        }
    }

    return st.top();
}

int main() {
    string s = "645-5*+";

    cout << evaluate(s) << endl;
}