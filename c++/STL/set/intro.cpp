#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << s.size() << endl;

    s.erase(3);

    if(s.find(2) !=s.end()){
        cout << " 2 exists " << endl;
    }else{
        cout << " 2 doesn't exist " << endl;
    }

    for(auto it : s){
        cout << it << " "; 
    } // prints in ordered way that is ascedning order as set is ordered set and only unique values are stored in the set (internall same as map where key is unique and sorted value is some garbaeg value)

    // unordered_set also same as unordered_map with duplicate GV values as value key uniqye not ordered nopt sorted 
}