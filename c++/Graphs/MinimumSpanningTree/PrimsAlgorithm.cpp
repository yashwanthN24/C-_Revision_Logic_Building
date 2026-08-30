#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;


class Edge{

    public:
        int v;
        int wt;

        Edge(int v , int wt){
            this->v = v;
            this->wt = wt;
        }

    
};

//  undirected graph
class Graph{

    int V; 
    list<pair<int,int>> *l;
    bool isUndir;

    public: 
       Graph(int vertices , bool isUndir = true){
            this->V = vertices;
            this->l = new list<pair<int,int>>[V]; // now l contains V empty lists unlike java which has nulls for references because java build objects in heap via new 
            // here stl container are andking akll that for us so direct get what we want 
            this->isUndir = isUndir;
       }

       void addEdge(int u , int v , int wt){
            l[u].push_back({v , wt});
            if(isUndir)
                l[v].push_back({u , wt});// as its a undireted grapg  
       }

       void printGraph(){
            for(int u = 0; u<V;u++){
                list<pair<int,int>> neighbours = l[u];
                cout << u << " : " << "[ " ;
                for(auto n: neighbours){
                    cout   << n.first << " " ; 
                }
                cout << " ] " ;
                cout << endl;
            }
       }


       void primsAlgorithm(int src){

            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;// min heap for pair so first value sorted if tie sedonc dvalue minum sorted 

            vector<bool> mstSet(V , false);

            vector<Edge> edges;          

            pq.push({0 , src});
            int ans = 0;

            while(!pq.empty()){

                auto p = pq.top();
                pq.pop();
                int wt = p.first;
                int u = p.second;

                
                if(!mstSet[u]){
                    mstSet[u] = true;
                    ans += wt;
                    edges.push_back(Edge(u , wt));
                    // add neighbours
                    for(auto neighbour : l[u]){
                       int v = neighbour.first;
                       int weight = neighbour.second;
                          if(!mstSet[v]){ // to avoid duplicate entries in queue doesnt matter 
                             pq.push({weight , v});
                          }
                    }

            }

        }
        cout << " cost of mst is : " << ans << endl;

        // print edges 
        for(Edge e: edges){
            cout << "edge : " << e.v << " weight : " << e.wt << endl;
        }

    }

};

int main(){
    Graph graph(4);

    graph.addEdge(0 , 1 , 10);
    graph.addEdge(0 , 3 , 30);
    graph.addEdge(0 , 2 , 15);
    graph.addEdge(1 , 3 , 40);
    graph.addEdge(3 , 2 , 50);

    graph.primsAlgorithm(0);

}


/*

A spanning tree is a tree in which we have N nodes(i.e. All the nodes present in the original graph) and N-1 edges and all nodes are reachable from each other.

Among all possible spanning trees of a graph, the minimum spanning tree is the one for which the sum of all the edge weights is the minimum.
*/