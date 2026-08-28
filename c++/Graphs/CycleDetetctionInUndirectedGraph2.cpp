#include <bits/stdc++.h>

using namespace std;        


class Solution{
public:
    bool isCycleUtil(vector<int> graph[] , vector<bool> &visited , int src , int parent){

        visited[src] = true;

        // get neigbours 
        for(int n: graph[src]){
            if(!visited[n]){
                if(isCycleUtil(graph , visited , n , src))
                    return true;
            }else if(n != parent){ /// visited neigbour anmd is not parent then cycle case backedge 
                return true;
            }
        }

        return false;
    } 
 
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V , false);

        for(int i = 0 ;i<V; i++){
            if(!visited[i]){
                if(isCycleUtil(adj , visited , i , -1)){
                    return true;
                }
            }
        }
        return false;
    }
};