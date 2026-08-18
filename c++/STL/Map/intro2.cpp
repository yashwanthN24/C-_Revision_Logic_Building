#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std; 

int main(){
    map<string, int> m;

    m["england"] = 67;
    m["india"] = 12;
    m["Afganisthan"] = 17;

    cout << m["india"] << endl;

    if(m.count("india") == 1){
        cout << "ok" << endl;
    }else{
        cout << "yes" << endl;
    }

    // m.erase("Afganisthan");

    for(pair<string , int> conutry: m ){
        cout << conutry.first << " , " << conutry.second << endl;
    }

    // keys are sorted in ascending order  see sosorted order of countries
}