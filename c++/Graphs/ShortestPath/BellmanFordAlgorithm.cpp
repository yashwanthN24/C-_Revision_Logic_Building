#include <bits/stdc++.h>

using namespace std;


class Edge{
    public:
    int v; // for u -> v this represent the neighbour v 
    int wt; // weight of edge between u and v i.e u -> v

    Edge(int v , int wt){
        this->v = v;
        this->wt = wt;
    }

};

void bellmanFordAlgorithm(vector<vector<Edge>> &graph , int V , int src){
    // creates distance array 
    vector<int> dist(V , INT_MAX);

    dist[src] = 0;

    // V-1 iterations 
    for(int i = 0 ; i<V-1; i++){ // O(V*E) == O(N^2) worst than dijsktra which has O((V+E)logV) i,.e O(nlogn)
        
       for(int u = 0; u < V; u++) {       // every vertex

        for(Edge e : graph[u]) {       // every edge from u

            int v = e.v;
            int wt = e.wt;

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
        }
    }

    // print shortest distance 
    for(int d: dist){
        cout << d << " ";
    }
}


int main(){

    int V = 5;
    vector<vector<Edge>> graph(V); // creates a vector of size 5 element where each element is a vector that can store Edge Objects 

    graph[0].push_back(Edge(1 , 2));
    graph[0].push_back(Edge(2 , 4));

    graph[1].push_back(Edge(2 , -4));

    graph[2].push_back(Edge(3 , 2));

    graph[3].push_back(Edge(4 , 4));

    graph[4].push_back(Edge(1 , -1));

    bellmanFordAlgorithm(graph , V , 4);
}