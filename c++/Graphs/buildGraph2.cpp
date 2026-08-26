#include <iostream>
#include <list>

using namespace std;

//  directed graph
class Graph{

    int V; 
    list<int> *l;

    public: 
       Graph(int vertices){
            this->V = vertices;
            this->l = new list<int>[V]; // now l contains V empty lists unlike java which has nulls for references because java build objects in heap via new 
            // here stl container are andking akll that for us so direct get what we want 
       }

       void addEdge(int u , int v){
            l[u].push_back(v);
       }

       void printGraph(){
            for(int u = 0; u<V;u++){
                list<int> neighbours = l[u];
                cout << u << " : " << "[ " ;
                for(int n: neighbours){
                    cout   << n << " " ; 
                }
                cout << " ] " ;
                cout << endl;
            }
       }

};

int main(){
    Graph graph(5);

    graph.addEdge(0 , 1 );
    graph.addEdge(1 , 2 );
    graph.addEdge(1 , 3 );
    graph.addEdge(2 , 3 );
    graph.addEdge(2 , 4);

    graph.printGraph();

    return 0;

}