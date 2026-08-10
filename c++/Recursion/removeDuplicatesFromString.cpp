#include <iostream>

using namespace std;

string removeDuplicates(string str , bool *freq , int i , string ans){

    if(i == str.length()){
        return ans;
    }

    char ch = str.at(i);
    if(!freq[ch-'a']){
        freq[ch-'a'] = true;
        return removeDuplicates(str , freq , i+1 , ans + ch);
    }else{
        return removeDuplicates(str , freq , i+1 , ans );
    }




}

string removeDuplicates2(string str, bool *freq , string ans ){

    if(str.length() == 0){
        return ans;
    }

    char ch = str.at(str.length()-1);
    if(freq[ch-'a']){
        return removeDuplicates2(str.substr(0 , str.length()-1) , freq , ans );
    }

    freq[ch-'a'] = true;
    return removeDuplicates2(str.substr(0 , str.length()-1) , freq , ch + ans);
}
    
int main(){

    string str = "yasshhwanth";
    bool freq[26] = {false};
    string ans = "";
    cout << removeDuplicates(str , freq , 0 , ans) << endl;
    cout << ans ;
    bool freq2[26] = {false};
    cout << removeDuplicates2(str  , freq2 ,  ans) << endl;
}

// https://chatgpt.com/c/6a798ed5-a1fc-83ee-884a-c9affc14c02e