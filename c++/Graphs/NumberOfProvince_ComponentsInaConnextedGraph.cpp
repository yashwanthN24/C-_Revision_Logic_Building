#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int src, list<int> adjList[], vector<bool> &visited) {
        // Mark current node as visited
        visited[src] = true;

        // Visit all adjacent unvisited nodes
        for (auto neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Create adjacency list from adjacency matrix
        list<int> adjList[isConnected.size()];
        int V = isConnected.size();

        // Convert matrix to list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Ignore self-loops
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visted(isConnected.size() , false);
        int count = 0;
        for(int i = 0; i<visted.size(); i++){
            if(!visted[i]){
                count++;
                dfs(i , adjList , visted);
            }
        }

        return count;
    }
};