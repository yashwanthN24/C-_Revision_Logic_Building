#include <iostream>
#include <vector>
#include <queue>


using namespace std;

void printSlidingWindowMaximum(vector<int> arr , int k){

    // create a priotiy queue that acts as a windows for trackjing maximum element via max heap we store a pair in  each of these have element and its index 

    priority_queue<pair<int, int>> pq;
    //  1st k size window
    for(int i = 0; i<k ; i++){
        pq.push(make_pair(arr[i] , i));
    }

    // print first max element fo the window via prioty queue max heap magic
    cout << "top = " <<   pq.top().first << " ";


    for(int i = k ; i<arr.size() ; i++){
        if(!pq.empty() && pq.top().second <= (i-k)){
            pq.pop();
        }

        pq.push(make_pair(arr[i] , i));

        cout << pq.top().first << " ";
    }

}
vector<int> printSlidingWindowMaximum2(vector<int> arr , int k){

    // create a priotiy queue that acts as a windows for trackjing maximum element via max heap we store a pair in  each of these have element and its index 
    int n = arr.size();
    vector<int> ans(n-k+1 , 0); /// those many possible windows for K sized windows 
    priority_queue<pair<int, int>> pq;
    //  1st k size window
    for(int i = 0; i<k ; i++){
        pq.push(make_pair(arr[i] , i));
    }

    ans[0]  = pq.top().first;

    // print first max element fo the window via prioty queue max heap magic
    // cout << "top = " <<   pq.top().first << " ";


    for(int i = k ; i<arr.size() ; i++){
        // because wndows starts from i-k +1 to i for any k sized window 
        if(!pq.empty() && pq.top().second <= (i-k)){
            pq.pop();
        }

        pq.push(make_pair(arr[i] , i));

        ans[i-k+1] = pq.top().first;

        // cout << pq.top().first << " ";
    }

    return ans;

}

int main(){
    vector<int> vec = {1 , 3 , -1 , -3 , 5 , 3 , 6 ,7};

    int K = 3;
    printSlidingWindowMaximum(vec , K );
    cout << endl;
    vector<int> q = printSlidingWindowMaximum2(vec , K );

    for(int ch: q){
        cout << ch << " " ;
    }
}