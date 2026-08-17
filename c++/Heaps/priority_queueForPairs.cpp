#include <iostream>
#include <queue>


using namespace std;

struct ComparePair{
    bool operator () (pair<string , int> &p1 , pair<string , int> &p2){
        return p1.first > p2.first; // minheap based on first parameter 
    }
};

int main(){
    // priority_queue<pair<string, int> , vector<pair<string , int>> , ComparePair> pq;

    priority_queue<pair<string, int>> pq;


    // by defAult priority_queue<pair<anydatatype , anydataype>  creates a max heap based on pair first value  if this  custom comparator not passed 
    pq.push(make_pair("yash" , 23));
    pq.push(make_pair("test" , 12));
    pq.push(make_pair("guis" , 23));
    pq.push(make_pair("zuis" , 23));
    pq.push(make_pair("xuis" , 23));

    // see clear for pairs c+ creates max heap nbased on pair.first value 

    while(!pq.empty()){
        cout << pq.top().first <<  " "  <<  pq.top().second<< endl;
        pq.pop();
    }
}