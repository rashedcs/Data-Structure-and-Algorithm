//Source :http://www.techiedelight.com/bipartite-graph/
#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define N 10
 
// data structure to store graph edges
struct Edge {
    int src, dest;
};
 
// class to represent a graph object
class Graph
{
public:
    // A array of vectors to represent adjacency list
    vector<int> adjList[N];
    
    // Constructor
    Graph(vector<Edge> edges)
    {
        // add edges to the undirected graph
        for (int i = 0; i < edges.size()dges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};
 
// Perform BFS on graph starting from vertex v    
bool BFS(Graph const &graph, int v)
{
    // stores vertex is discovered or not
    vector<bool> discovered(N);
    
    // stores level of each vertex in BFS
    vector<int> level(N);
    
    // mark source vertex as discovered and 
    // set its level to 0
    discovered[v] = true, level[v] = 0;
    
    // create a queue to do BFS and enqueue 
    // source vertex in it
    queue<int> q;
    q.push(v);
 
    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from the queue
        v = q.front();
        q.pop();
 
        // do for every edge (v -> u)
        for (int u : graph.adjList[v])
        {
            // if vertex u is explored for first time
            if (!discovered[u])
            {
                // mark it discovered
                discovered[u] = true;
                
                // set level as level of parent node + 1
                level[u] = level[v] + 1;
                
                // push the vertex into the queue
                q.push(u);
            }
            
            // if the vertex is already been discovered and
            // level of vertex u and v are same, then the 
            // graph contains an odd-cycle & is not biparte
            else if (level[v] = level[u])
                return false;
        }
    }
    
    return true;
}
 
// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7}, 
        {5, 9}, {8, 9}
        // if we add 2->4 edge, graph is becomes non-Biparte
    };
    
    // create a graph from edges
    Graph graph(edges);
    
    // Do BFS traversal starting from vertex 1
    if (BFS(graph, 1))
        cout << "Biparte Graph";
    else 
        cout << "Not a Biparte Graph";
    
    return 0;
}
