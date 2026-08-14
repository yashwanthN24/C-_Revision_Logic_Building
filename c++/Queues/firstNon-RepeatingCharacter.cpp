#include <iostream>
#include <queue>

using namespace std;

void nonRepeatingCharacter(string str){
    int freq[26] = {0};
    
    queue<char> q;

    for(int i = 0 ; i < str.length() ; i++){
        char ch = str[i];
        q.push(ch);
        
        freq[ch-'a']++;

        while(!q.empty() && freq[q.front()-'a'] > 1){
            q.pop();
        }

        if(q.empty()){
            cout << " -1 \n" ; 
        }else{
            cout << q.front() << endl;
        }
    }
}




int main(){
    string str = "aabccxb";
    nonRepeatingCharacter(str);
    return 0;
}