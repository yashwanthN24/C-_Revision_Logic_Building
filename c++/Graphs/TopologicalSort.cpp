#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

//  undirected graph
class Graph{

    int V; 
    list<int> *l;
    bool isUndir;

    public: 
       Graph(int vertices , bool isUndir = true){
            this->V = vertices;
            this->l = new list<int>[V]; // now l contains V empty lists unlike java which has nulls for references because java build objects in heap via new 
            // here stl container are andking akll that for us so direct get what we want 
            this->isUndir = isUndir;
       }

       void addEdge(int u , int v){
            l[u].push_back(v);
            if(isUndir)
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

       void calcIndegree(vector<int> &indeq){
           for(int i = 0 ; i<V ; i++){
               list<int> neighbours = l[i];
               for(int val : neighbours){
                   indeq[val]++;
               }
           }
       }

       void topologicalSortBFSKahnsAlogorithm(){
            vector<int> indegree(V , 0);
            calcIndegree(indegree);

            queue<int> q;

            // finding starting node indegree  0 
            for(int i =0 ; i<indegree.size();i++){
                if(indegree[i] == 0){
                    q.push(i);
                }   
            }

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                cout << curr << " ";

                for(int val : l[curr]){
                    indegree[val]--;
                    if(indegree[val] == 0){ // no pending dependencies 
                        q.push(val);
                    }   
                }
            }

       }

       bool cycleDetectionInDirectedGraphUsingKahnAlgorithmTopologicalsortbfs(){
            vector<int> indegree(V , 0);
            calcIndegree(indegree);

            queue<int> q;

            // finding starting node indegree  0 
            for(int i =0 ; i<indegree.size();i++){
                if(indegree[i] == 0){
                    q.push(i);
                }   
            }

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                // cout << curr << " ";

                for(int val : l[curr]){
                    indegree[val]--;
                    if(indegree[val] == 0){ // no pending dependencies 
                        q.push(val);
                    }   
                }
            }


            //  check indegree array if any vertex indegree non-zero cycle exists else if allvertyex indegree 0 hen no cycle 

            for(int i = 0 ; i<indegree.size() ; i++){
                if(indegree[i] != 0){
                    return true;
                }
            }

            return false;

       }

       void topologicalSortDfsUtil(int  src , vector<bool> &visited , stack<int> &stack){

            visited[src] = true;

            // get all neighbour visist the immediate 1st neighbour 
            for(int val : l[src]){
                if(!visited[val]){
                    topologicalSortDfsUtil(val , visited , stack);
                }
            }

            stack.push(src);
       }

       void topologicalSortDfs(){

            vector<bool> visited(V , false);

            stack<int> st;
            for(int i = 0 ; i<visited.size() ; i++){
                if(!visited[i]){
                    topologicalSortDfsUtil(i , visited , st);
                }
            }

            while(!st.empty()){
                cout << st.top() << " " ; 
                st.pop();
            }

            cout << endl;
       }
    };


    int main(){

        // Graph graph(6 , false);

        // graph.addEdge(5,0);
        // graph.addEdge(5,2);
        // graph.addEdge(4,0);
        // graph.addEdge(4,1);
        // graph.addEdge(2,3);
        // graph.addEdge(3,1);
        // graph.topologicalSortDfs();

        // cout << endl;
        // graph.topologicalSortBFSKahnsAlogorithm();

        Graph graph(4 , false); // directed graph of 4 vertices 

        graph.addEdge(1 , 2);
        graph.addEdge(0 , 2);
        graph.addEdge(2 , 3);
        graph.addEdge(3 , 1);

        graph.topologicalSortBFSKahnsAlogorithm(); 


        cout << endl;

        cout << graph.cycleDetectionInDirectedGraphUsingKahnAlgorithmTopologicalsortbfs();
        

    }


    // https://chatgpt.com/c/6a919790-cab4-83e8-b46d-8fbf2c46d81f

    