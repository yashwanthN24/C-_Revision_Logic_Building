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

void dijkstrasAlgorithm(int src , vector<vector<Edge>> &graph , int V ){
    // V vertices of a graph 

    // create a priority_queue containing pai<int, int> where first value is distance dist[u] and secondis the actuall neighbour (u) 

    // min heap to get the minimum distance edge from the avaialabel neighbours 

    // for priority queue of pair its sorts based on first value anmd if  tie then based +++++on the second value if tie with firstvalue 

    priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    // add src pair in pq since src is 0 always src sdistance is 0 as its the starting point 

    vector<int> dist(V , INT_MAX);// each Vertex distance array intiallization all distanc to largest value +infinity

    // first element is dist[u] , u 
    pq.push({0 , src}); // or pq.push(make_pair(0 , src)); as src is reachable itself shortest path is 0 as we start rom here only 
    dist[src] = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int u = it.second; // vertex u 
        int wt = it.first; // dist[u]
        
        // for each neighbour of u
        for(Edge e: graph[u]){
            int v = e.v;
            int edgeWeight = e.wt;

            // relaxation step 
            if(dist[u] + edgeWeight < dist[v]){
                dist[v] = dist[u] + edgeWeight;
                pq.push({dist[v] , v});
            }   
        }

       
         
    }
    // print distances 
    //  for(int i = 0 ; i<dist.size() ; i++){
    //         cout << i << " " << " = " << dist[i] << endl;
    //  }

    for(int d : dist){
        cout << d << " ";
    }

}

int main(){
    int V = 6; // 6 vertices 
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1 ,2));
    graph[0].push_back(Edge(2 ,4));
    
    graph[1].push_back(Edge(3 , 7));
    graph[1].push_back(Edge(2 , 1));

    graph[2].push_back(Edge(4 , 3));

    graph[3].push_back(Edge(5 , 1));

    graph[4].push_back(Edge(3 , 2));
    graph[4].push_back(Edge(5 , 5));

    dijkstrasAlgorithm(0 , graph , V);


}


// https://chatgpt.com/c/6a92edd5-e8f4-83e9-98bd-6bf2305954e6


// https://chatgpt.com/c/6a93088e-b96c-83e8-9759-c94201df3dc3

// https://chatgpt.com/c/6a93088e-b96c-83e8-9759-c94201df3dc3