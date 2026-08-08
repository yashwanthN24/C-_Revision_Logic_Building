#include <iostream>

using namespace std;

int main(){
    char ch ; int a;
    cin >> ch;
    cin >> a;// works because cin ignore any whitespaces so even though \n is inbuffer after first cin it still works 

    // but for cin.getline() which doesnt ignore any whitehspaces we need to preced this with cin.ignore() to clear the whitepspace fi using immediately after a cin >> 
    cout <<ch  << " " << a << endl;
}