#include <iostream>

using namespace std;

int main(){
    string str; 
    cin >> str ; // same issue as c-style strings can read upto whitespace i,.e single word only 
    cout << str << endl;

    cin.ignore(); // to ignore the newline character left in the input buffer by cin >> str

    string str2;
    cout << str2 << endl;
    getline(cin , str2); // to read compete sentence consumes \n so preced it with cin.ignore when mixing with cin before this statementr
    cout << str2 << endl;

    string str3;
    getline(cin, str3 , '$');

    cout << str3 << endl;
    cout << str3[0] << endl;
    cout << str3[str3.length() - 1] << endl;

    return 0;
}