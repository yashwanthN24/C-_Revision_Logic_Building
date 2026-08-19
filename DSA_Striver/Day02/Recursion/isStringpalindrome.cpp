#include <iostream>

using namespace std;

bool isPalindrome(string str , int start , int end ){
    if(start > end){
        return true;
    }

    if(str[start] != str[end]){
        return false;
    }

    return  isPalindrome(str , start+1 , end-1);
}

int main(){

    // string str = "madan";
    string str = "madam";
    int n = str.length();
    bool isPalin = true ;
    for(int i = 0 ; i<n/2 ; i++){
        if(str.at(i) != str.at(n-i-1)){
            isPalin = false;
            break;
        }
    }


    // other method two pointer while(start < end) s[start++] != s[end--]

    cout << isPalin << endl;


    cout << isPalindrome(str , 0 , str.length()-1) << endl;
}