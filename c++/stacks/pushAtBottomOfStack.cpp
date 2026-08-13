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

int main(){
    stack<int> s ;

    s.push(5);
    s.push(10);
    s.push(15);

    pushAtBottomOfStack(s , 1);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }


}