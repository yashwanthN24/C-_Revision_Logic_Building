#include <iostream>

using namespace std;

void binaryStrings(int n , string str){
    if(n == 0){
        cout << str << endl;
        return;
    }
    if(str[str.size()-1] != '1'){
        binaryStrings(n-1 , str + "0");
        binaryStrings(n-1 , str + "1"); 
    }else{
        binaryStrings(n-1 , str + "0");
    }

   
}

int main(){
    string ans = "";
    binaryStrings(3 , ans);
}