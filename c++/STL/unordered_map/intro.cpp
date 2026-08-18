#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    unordered_map<string, int> m;

    m["india"] = 12; // internal the key string is getting converedt to a index of a n array as unordered map usesa hashtable which is a n array of linkedlists 
    m["Afganisthan"] = 17;
    m["Us"] = 17;

    cout << m["india"] << endl;

    m.erase("Afganisthan"); // to remoev that key value pair from thew map 

    if(m.contains("india")){
        cout << "india key present in map" << endl;
    }else{
        cout << "Indian not present in map" << endl;
    }

    // m.count return 0 if key not prresent in map 1 is key is present in  map 
    if(m.count("india") == 1){
        cout << "india key present in map" << endl; 
    }
    else{
        cout << "Indian not present in map" << endl;
    }

    for(pair<string , int> conutry: m ){
        cout << conutry.first << " , " << conutry.second << endl;
    } 

    // see we get random order as its unordered map (for map we get sortied order of keys i.e ascending order of keys)

    // verdict : use unordered_map when you want O(1) TC and order not maintained and random order of keys order is not gurantted used only for fast looksup not when you want keys tobe sorted (Like in topview of binary tree problem where we wanted the hd to be sorted as ketys when we print the map we directly get sorted ordertd of key hence the correct order of top view of biary treee)
}