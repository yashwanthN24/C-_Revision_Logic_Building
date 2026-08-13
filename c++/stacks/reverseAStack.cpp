#include <iostream>
#include <stack>

using namespace std;

void pushAtBottomOfStack(stack<int> &s , int data){
    if(s.empty()){
        s.push(data);
        return ;
    }

    int topelement = s.top();
    s.pop();
    pushAtBottomOfStack(s , data);
    s.push(topelement);

}


void reverseStack(stack<int> &s){
    if(s.empty()){
        return ;
    }

    int topelement = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottomOfStack(s , topelement);    

}

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

int main(){
    stack<int> s;

    s.push(5);  
    s.push(11);
    s.push(15); 

    printStack(s);

    reverseStack(s);
    cout << endl;

    // while(!s.empty()){
    //     cout << s.top() << endl;
    //     s.pop();
    // }   

    printStack(s);

    return 0;


}

// https://chatgpt.com/c/6a7d7b1f-5414-83ea-84a3-3a81bf9fed19