#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

//  undirected graph
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
            l[v].push_back(u);// as its a undireted grapg  
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

       void bfs(){
           queue<int> q;
           vector<bool> visited(V , false);
           
           q.push(0);
              visited[0] = true;

              while(!q.empty()){
                 int value = q.front();
                 q.pop();

                 cout << value << " " ;

                //  add this nodes and visites its immediate neigbour 
                list<int> neighbours = l[value];
                for(int val: neighbours){
                    if(!visited[val]){
                        visited[val] = true;
                        q.push(val);
                    }
                }

              }
       }

       void dfsHelper(int src , vector<bool> &visited){

            visited[src] = true;
            cout << src << " ";

            list<int> neighbours = l[src];

            for(int val: neighbours){
                if(!visited[val]){

                    dfsHelper(val , visited);
                }
            }

       }

       void dfs(){
            vector<bool> visited(V , false);
            dfsHelper(0 , visited);
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


    graph.bfs();

    cout << endl;

    graph.dfs();

    return 0;

}