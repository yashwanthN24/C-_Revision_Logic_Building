#include <iostream>
#include <map>


using namespace std; 

int main(){
    map<int , string> mp ;

    mp[101] = "neha";
    mp[102] = "neha";
    mp[131] ="shetty";

    cout << mp[101] << endl;

    mp[101] = "rajat" ; // overides the value of key 101  

    cout << mp[101] << endl;

    cout << mp.count(101) << endl; // returns 1 if key is present else 0 

    cout << mp.count(100) << endl; // returns 1 if key is present else 0      
    
    cout << mp.size() << endl; // returns the size of the map       

    cout << mp.empty() << endl; // returns 1 if map is empty else 0 

    // cout << mp << endl;
    for(auto it = mp.begin() ; it != mp.end() ; it++){
        cout << it->first << " " << it->second << endl;
    }   


    cout << endl;

    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }   

    // map sorted keys in ascending order by default and unique keys only if we try to insert duplicate key then it will override the value of the key with new value. 

    // map key are always unique vbalue can be duplicate 
}