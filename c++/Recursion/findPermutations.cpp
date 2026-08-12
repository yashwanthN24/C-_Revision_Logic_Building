#include <iostream>
#include <vector>

using namespace std;

void findPermutations(string str , vector<string> &ans  , string finstr){

    int n = str.size(); 
    if(n == 0){
        ans.push_back(finstr);
        return ;
    }

    for(int i =0; i<n ; i++){
        char ch = str.at(i);
        string nextstr = str.substr(0 , i) + str.substr(i+1 , n);                 
        findPermutations(nextstr , ans , finstr + ch);
    }
}

int main(){

    string str = "abc";
    vector<string> permutations;
    findPermutations(str , permutations , "");

    for(string s: permutations){
        cout << s << " " << endl;
    }


}