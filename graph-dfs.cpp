#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int, int);
    void DFS(int);
    void DFSUtil(int , bool*);    
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int s){
    bool *visited = new bool[V];
    DFSUtil(s, visited);
}

void Graph::DFSUtil(int vertex, bool *visited){
    visited[vertex] = true;
    cout << vertex << " ";
    list<int>::iterator i;
    for(i=adj[vertex].begin(); i != adj[vertex].end(); i++){
        if(!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}


int main(){
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.DFS(2); 
  
    return 0; 
}