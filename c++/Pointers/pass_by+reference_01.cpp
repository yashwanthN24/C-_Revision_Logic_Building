#include <iostream>

using namespace std;

void change(int *p){
    *p = 20;
    cout << p << endl;
    cout << *p << endl;

}

int main(){
    int a = 10;
    change(&a);
    cout << a << endl;
}