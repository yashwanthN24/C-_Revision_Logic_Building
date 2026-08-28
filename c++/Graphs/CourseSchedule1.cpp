#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCycle(int src , vector<bool> &visited , vector<bool> &recPath , vector<vector<int>>& graph){

        visited[src] = true;
        recPath[src] = true;

        for(int i = 0 ; i<graph.size() ; i++ ){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u == src){
                if(!visited[v]){
                    if(isCycle(v , visited , recPath , graph)){
                        return true;
                    }
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
        }


        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> graph = prerequisites;
        vector<bool> visited(V , false);
        vector<bool> recPath(V , false);

        for(int i = 0 ; i<visited.size() ; i++){
            if(!visited[i]){
                if(isCycle(i , visited , recPath , graph)){
                    return false; // cycle so topological sort cant be applied as its not a DAG directed acyclic graph 
                }
            }
        }

        return true; // meaningacyclic no cycle so dag so topological sort can be applied 
    }
};


// same a detection of cycle in directed graph if cycyle topological sort not possible so false else true as toplogical sotr possible for DAg directed acyclic graph 

