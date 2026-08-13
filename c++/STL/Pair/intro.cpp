#include <iostream>
#include <vector>

using namespace std;

// #pair is used to store 2 objects 

int main(){
    vector<pair<int , int>> v(3 , make_pair(0 , 0)); // vector of pairs of size 3 and initialized with pair of (0 , "abc")
    v[0] = make_pair(1 , 2);
    v[1] = make_pair(3 , 4);
    v[2] = make_pair(5 , 6);

    for(auto p: v){
        cout << p.first << " " << p.second << endl;
    }       
}