#include <iostream>

using namespace std;


void printAllSubsets(string str , string subset , int i ){
    if(i == str.length()){
        if(subset.empty()){
            cout << "Phi" << endl;
        }else{
            cout << subset << endl;
            
        }
        return ;
    }

    char ch = str.at(i);
    // case when current character included in subset 
    printAllSubsets(str , subset + ch , i+1);

    // case when current character not want to be part of subset
    printAllSubsets(str , subset , i+1);
    

}

int main(){
    string str = "abc";

    printAllSubsets(str , "" , 0);
}