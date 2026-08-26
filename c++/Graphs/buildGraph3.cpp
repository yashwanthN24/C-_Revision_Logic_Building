#include <iostream>
#include <list>

using namespace std;

//  undirected weighted graph
class Graph{

    int V; 
    list<pair<int,int>> *l;

    public: 
       Graph(int vertices){
            this->V = vertices;
            this->l = new list<pair<int,int>>[V]; // now l contains V empty lists unlike java which has nulls for references because java build objects in heap via new 
            // here stl container are andking akll that for us so direct get what we want 
       }

       void addEdge(int u , int v , int w){
            l[u].push_back({v , w});
            l[v].push_back({u , w});
       }

       void printGraph(){
            for(int u = 0; u<V;u++){
                list<pair<int,int>> neighbours = l[u];
                cout << u << " : " << "[ " ;
                for(auto n: neighbours){
                    cout   << "(" << n.first << " ," << n.second << ")" ; 
                }
                cout << " ] " ;
                cout << endl;
            }
       }

};

int main(){
    Graph graph(5);

    graph.addEdge(0 , 1 , 5 );
    graph.addEdge(1 , 2  , 1);
    graph.addEdge(1 , 3  , 3);
    graph.addEdge(2 , 3 , 1);
    graph.addEdge(2 , 4 , 2);

    graph.printGraph();

    return 0;

}


// https://chatgpt.com/c/6a8eb1cf-67a0-83e8-be78-d24877115469