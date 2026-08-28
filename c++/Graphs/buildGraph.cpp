#include <iostream>
#include <list>
#include <queue>
#include <vector>

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

       void bfsHelper(int src , vector<bool> &visited){
           queue<int> q;
          
           
           q.push(src);
           visited[src] = true;

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

       void bfs(){
            vector<bool> visited(V , false);
            for(int i = 0; i< visited.size(); i++){
                if(!visited[i]){
                    bfsHelper(i , visited);
                }
            }
       }

       void dfsHelper(int src , vector<bool> &visited){
            // visit 1st neighiour always 
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

            // To handle disconnnected components of a graph i.e diconnected graph
            for(int i = 0 ;i<visited.size() ; i++){
                if(!visited[i]){
                    dfsHelper(i , visited);
                }
            }
       }

    //    hasPath using dfs approach
       bool hasPathHelper1(int src , int dest , vector<bool> &visited){
          if(src == dest) return true;

          visited[src] = true;

        //   get its neighbours and visiste the 1st neighbour alwazys 
          list<int> neighbours = l[src]; 
          for(int val : neighbours){
             if(!visited[val] && hasPathHelper1(val , dest , visited)){
                return true;
             }
          }

          return false;
       }

       bool hasPath(int src , int dest){

          vector<bool> visited(V , false);
          return hasPathHelper1(src , dest , visited);
       }

       bool hasPath2(int src , int dest){
            queue<int> q ;
           vector<bool> visited(V , false);

           q.push(src);
           visited[src] = true;
           
           while(!q.empty()){
                int val = q.front();
                q.pop();
                
                if(val == dest) return true;

                    

                    // add its neigours and visite the immediate neighbours 
                    list<int> neighbours = l[val];

                    for(int val : neighbours){
                        if(!visited[val]){
                            visited[val] = true;

                            q.push(val);
                        }   
                    }
                
           }

           return false;
           
       }


       /*
       
       
       Maintain a visited array to keep track of visited nodes.
Iterate through all nodes to handle disconnected components.
If a node is unvisited, start a DFS from it with the parent set to -1 (or null).
In DFS, for the current node, explore all its neighbors.
If a neighbor is not visited, recursively call DFS with the current node as parent.
If a neighbor is already visited and is not the parent, then a cycle exists.
If the DFS completes without such a condition, no cycle exists.

       
       
       */

       bool detectCycleInUndirectedGraphHelper(int src , vector<bool> &visited , int parent){

            visited[src] = true;

            // get nrighbours 
            list<int> neighbours = l[src];

            for(int val : neighbours){
                if(!visited[val]){ // dont try to && it in one condition as it wont give right resuklt this is the righjt way to do it 
                    if(detectCycleInUndirectedGraphHelper(val , visited , src)){
                        return true;
                    }
                }else if(val != parent){ // meaning already visited and parent not equal to neighbour cycle case 
                    return true;
                }   
            }


            return false;

       }

       bool detectCycleInUndirectedGraph(){
            vector<bool> visited(V , false);

            for(int i = 0 ; i<visited.size() ; i++){
                if(!visited[i]){
                    if(detectCycleInUndirectedGraphHelper(i , visited , -1)){
                        return true;
                    }
                }
            }

            return false;
       }

       bool detectCycleInDirectedGraphHelper(int src , vector<bool> &visited , vector<bool> &recPath){
            visited[src] = true;
            recPath[src] = true;

            for(int val : l[src]){
                if(!visited[val]){
                    if(detectCycleInDirectedGraphHelper(val , visited , recPath)){
                        return true;
                    }
                }else if(recPath[val]){ // meaning already visited and is in the recursion path then cycle case 
                    return true;
                }                       
            }

            recPath[src] = false;
            return false;
       }

       bool detectCycleInDirectedGraph(){
            vector<bool> visited(V , false);
            vector<bool> recurPath(V , false);

            for(int i = 0 ; i<visited.size() ; i++){
                if(!visited[i]){
                    if(detectCycleInDirectedGraphHelper(i , visited , recurPath)){
                        return true; // any component have cycle ereturn true 
                    }
                }   
            }

            return false; // all components have no cycle
       }

       bool isBipartiteGraphHelper(int src , vector<bool> &visited , vector<int> colors){

           
            queue<int> q ;

            q.push(src);
            visited[src] = true;
            colors[src] = 0 ; // 0 means blue set and 1 means white set 
            // graph coloring 

            while(!q.empty()){

                int currEle = q.front();
                q.pop();

                // get its neighbour bfs go to immedeita neighbours 
                list<int> neighbours = l[currEle];
                for(int val : neighbours){
                    // if not visited mark as visted and assign opposite color  of curnode 
                    if(!visited[val]){
                        visited[val] = true;
                        colors[val] = !colors[currEle]; // oppsoite coloring  of the element we just processed i.e oppoisute color assigned diffeetn from curnode
                        q.push(val);
                    }else{
                        // visited case but sme color as curnode then return false as two nope of same color are connected 
                        if(colors[val] == colors[currEle]){
                            return false;
                        }

                        // rest all do nothing case when visited and different olore fine go forward 
                    }
                }


            }

            return true;

       }

       bool isBipartiteGraphHelper2(int src , vector<int> &colors){
            // in this appraoch same but we dont need visisted array only through colors array itsefl we caqn identify whether a node is visited or not 

            // since intially we have all nodes colors intilaized to -1 it mesans that node is not visited once color those nodes either have a coor or 0 or 1 so 

            // if (colors[i] == -1) it means the node is not visisted 

            // else case i.e when colors[i] = 0  or colors[i] = 1 then the node is already visited as its already colored 

            queue<int> q;

            q.push(src);
            colors[src] = 0; // intially assigning blue color i.e adding src node to blue set 

            while (!q.empty()){
                int curEle = q.front();
                q.pop();

                //  find neight and go towards immediate neighbours  as its bfs
                list<int> neighbours = l[curEle];

                for(int val : neighbours){

                    // if(colors[val] == -1) means node is not visited thats why its not colored yet 
                    if(colors[val] == -1){
                        // color it and oush into quque colored also means marking it as visited
                        colors[val] = !colors[curEle];
                        q.push(val); 
                    }else {
                        //  node already visited case i.e colors[val] = 0  or 1 
                        
                        //  if neighbor alreayd visited and are off same color as current processing node (its not bipartite as same colored nodes are olored i.e saeme set5 nodes are connected whihc is wrong )

                        if(colors[val] == colors[curEle]){
                            return false;
                        }

                    }
                }
            }

            return true;
            
       }

       bool isBipartiteGraph(){
            vector<bool> visited(V , false);
            vector<int> colors(V , -1);
            for(int i = 0 ; i<visited.size() ; i++){
                 if(!visited[i]){
                    if(!isBipartiteGraphHelper(i , visited , colors)){
                        return false;
                    }
                 }
            }

            return true;
       }

       bool isBipartiteGraph2(){
            vector<int> colors(V , -1);
            for(int i = 0 ; i<colors.size() ; i++){
                 if(colors[i] == -1){
                    if(!isBipartiteGraphHelper2(i  , colors)){
                        return false;
                    }
                 }
            }

            return true;
       }

    //    dfs
       void pathHelper(int src , int dest , vector<bool> &visited , string &path){
            if(src == dest){
                cout << path << dest << endl;
                return;
            }

            // path += src; // direct means adds ascii value character to string which is wrong so convert it to tostring and add 

            path += to_string(src);

            visited[src] = true;

            for(int val : l[src]){
                if(!visited[val]){
                    pathHelper(val , dest , visited , path);
                }
            }

            // while backtracking remove current src from path 

            path.pop_back();
            visited[src] =false;

       }


    //    more simple and easy to understand 
       void pathHelper2(int src, int dest,
                vector<bool>& visited,
                string& path) {

    // choose
    path += to_string(src);
    visited[src] = true;

    // base case
    if (src == dest) {
        cout << path << endl;

        // undo
        path.pop_back();
        visited[src] = false;
        return;
    }

    // explore
    for (int next : l[src]) {
        if (!visited[next]) {
            pathHelper(next, dest, visited, path);
        }
    }

    // undo
    path.pop_back();
    visited[src] = false;
}
    /*
    
        Remember the distinction

DFS/BFS traversal of entire graph:

for every vertex:
    if not visited:
        DFS(vertex)

➡️ Need to handle disconnected components.

All paths from src to dest:

DFS(src, dest)

➡️ Only the component containing src matters.

So your all-paths algorithm is perfectly fine for a disconnected graph—it just won't find paths in unrelated components because those aren't paths from your chosen src to dest.
    
    */


       void printAllpathsFromSrctoDst(int src , int dest){
          vector<bool> visited(V, false);
          string path = "";
          pathHelper(src , dest , visited , path);
       }

};

int main(){
    // Graph graph(5);

    // graph.addEdge(0 , 1 );
    // graph.addEdge(1 , 2 );
    // graph.addEdge(1 , 3 );
    // graph.addEdge(2 , 3 );
    // graph.addEdge(2 , 4);

    // Graph graph(10);

    // disconnected graph 

    // 1st component
    // graph.addEdge(0 , 2 );
    // graph.addEdge(2 , 5);

    // // 2nd component
    // graph.addEdge(1 , 6);
    // graph.addEdge(6 , 4);
    // graph.addEdge(4 , 3);
    // graph.addEdge(4 , 9);
    // graph.addEdge(3 , 7);
    // graph.addEdge(3 , 8);


    // directed graph 
    // Graph graph(4 , false); // directed graph so falss by default true so undirected graph

    // graph.addEdge(1 , 0);
    // graph.addEdge(0 , 2);
    // graph.addEdge(2 , 3);
    // graph.addEdge(3 , 0);


    // undirected non bipartite graph 
    // Graph graph(5);

    // graph.addEdge(2 , 1);
    // graph.addEdge(0 , 1);
    // graph.addEdge(0 ,2);
    // graph.addEdge(0 , 3);
    // graph.addEdge(3 , 4);

    // Graph graph(4);

    // graph.addEdge(0 ,1);
    // graph.addEdge(0 ,2);
    // graph.addEdge(2 , 3);
    // graph.addEdge(1 , 3);

    // graph.addEdge(0 , 3);


    // Print all paths from src to dest directed graph 
    Graph graph(6 , false);

    graph.addEdge(5 , 0);
    graph.addEdge(5 , 2);
    graph.addEdge(0 , 3);
    graph.addEdge(4 , 0);
    graph.addEdge(4 , 1);
    graph.addEdge(2 , 3);
    graph.addEdge(3 , 1);


    graph.printGraph();


    graph.bfs();

    cout << endl;

    graph.dfs();

    cout << endl;

    cout << graph.hasPath(0 , 4 );


    cout << endl;

    cout << graph.hasPath2(2 , 4) << endl;

    cout << endl;
    // cout << graph.detectCycleInDirectedGraph() << endl;

    cout << graph.isBipartiteGraph();

    cout << endl << graph.isBipartiteGraph2() << endl;

    cout << endl ; graph.printAllpathsFromSrctoDst(5 , 1);


    return 0;

}


// https://chatgpt.com/c/6a9131b2-afec-83e8-9f4d-67470adef7d3


/*


vector<vector<int>> createGraph(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}




or 



void buildGraph(vector<vector<int>>& edges,
                vector<vector<int>>& adj,
                bool undirected) {

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);

        if (undirected) {
            adj[v].push_back(u);
        }
    }
}


ans call 


vector<vector<int>> adj(n);

buildGraph(edges, adj, true);






vector<vector<int>> buildGraph(
    int n,
    vector<vector<int>>& edges,
    bool undirected
) {
    vector<vector<int>> adj(n);  // n is needed HERE

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);

        if (undirected)
            adj[v].push_back(u);
    }

    return adj;
}


vector<vector<int>> adj = buildGraph(n, edges, true);
\
So your intuition is correct: if adj is already created and passed by reference, n is unnecessary.


Adjancy matrix to adjancy list 


vector<vector<int>> matrixToList(vector<vector<int>>& matrix) {

    int n = matrix.size();
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    return adjList;
}

handles both directed and undircted cases as the adjancey matrix handles the cases for you if directed bopth i,j and j i will be 1 else only 1 woulkd be 1 


So for edge list → adjacency list, use the bool undirecedOrnot.

For adjacency matrix → adjacency list, you normally don't need it.


void buildGraph(
    int n,
    vector<vector<int>>& edges,
    vector<vector<int>>& adj,
    bool undirected
) {
    for (auto edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);

        if (undirected) {
            adj[v].push_back(u);
        }
    }
}


vector<vector<int>> matrixToList(
    vector<vector<int>>& matrix,
    bool undirected
) {
    int n = matrix.size();

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    return adjList;
}


list<int>* matrixToList(vector<vector<int>>& matrix, bool undirected) {

    int n = matrix.size();

    list<int>* adjList = new list<int>[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    return adjList;
}


*/



// https://chatgpt.com/c/6a917f71-f180-83ee-b989-89fc37ad9653