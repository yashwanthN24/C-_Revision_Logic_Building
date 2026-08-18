#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


pair<int , int> pairSum(vector<int> arr , int target){

    unordered_map<int , int> mp; // key is the number and value is the index of the number in the array     

    for(int i = 0 ; i<arr.size() ; i++){

        if(mp.contains(target-arr[i])){
            return make_pair(mp[target-arr[i]] , i);
        }

        // mp.insert({arr[i] , i});

        mp[arr[i]] = i;

    }

    return make_pair(0 ,0);

}


int main(){

    vector<int> arr = {1  , 2 , 7 , 8 , 10 , 5};
    int target = 9;

    int n = arr.size();

    pair<int , int > p = pairSum(arr , target);

   
        cout << p.first << " " << p.second << endl;
    

}