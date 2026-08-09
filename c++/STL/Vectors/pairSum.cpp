#include<iostream>
#include<vector>

using namespace std;

void printAllPairs(const vector<int> &v){
    for(int i = 0 ; i<v.size(); i++){
        for(int j = i+1 ; j<v.size() ; j++){
            cout << " ( " << v[i] << " , " << v[j] << " ) " << " ";
        }
        cout << endl;

    }
}

vector<int> pairsumBruteForce(const vector<int> &v , int target){
    vector<int> indexes ;
    for(int i = 0 ; i<v.size(); i++){
        for(int j = i+1 ; j<v.size() ; j++){
            cout << " ( " << v[i] << " , " << v[j] << " ) " << " ";
            if(v[i] + v[j] == target){
                indexes.push_back(i);
                indexes.push_back(j);
                return indexes;
            }
        }
        cout << endl;

    }
    return indexes;
}

vector<int> pairSum(const vector<int> &v , int target){
    int start  = 0 , end = v.size() -1;
    vector<int> ans;
    while(start < end ){
        int curSum = v[start] + v[end];
        cout << curSum << endl;
        if(curSum == target){
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }else if(curSum < target){
            start++;
        }else{
            end--;
        }
    }

    return ans;
}


int main(){
    vector<int> v1 = {2 , 7 , 11 , 15};
    int target = 9;

    printAllPairs(v1);

    vector<int> res = pairSum(v1 , target);

    cout << res[0] << " " << res[1] << endl;


    return 0;
}