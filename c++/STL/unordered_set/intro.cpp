#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << s.size() << endl;


    s.insert(1);
    s.insert(1); // duplicate value will not be inserted in the set as set only stores unique values


    cout << s.size() << endl;

    if(s.contains(1)){
        cout << "1 is present in the set" << endl;  
    }

    if(s.find(1) != s.end()){
        cout << "1 is present in the set" << endl;  
    }   

    if(s.count(1) == 1){
        cout << "1 is present in the set" << endl;         
    }

    s.erase(1);

    for(auto it : s){
        cout << it << " "; 
    } // see random order that why its called unordered set as order is not gurantted each time used for fast loopup if element exists in the set or not and order is not important
}