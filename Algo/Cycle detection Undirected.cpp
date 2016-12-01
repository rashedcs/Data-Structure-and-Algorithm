#include<bits/stdc++.h>
using namespace std;

list<int> adj[1000];


bool isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i=adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))  return true;
        }
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)                return true;
    }
    return false;
}
//vector<int>nodes[1000];
// Returns true if the graph contains a cycle, else false.
bool isCyclic(int V)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {// Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))   return true;
        }
    }
    return false;
}


int main()
{

        int start, vertex, edges,a,b;
	    cin>>vertex>>edges;
	    for(int i=0;i<edges;i++)
	    {
	  	  cin>>a>>b;
		  adj[a].push_back(b);
		  adj[b].push_back(a);
	    }

	    if(isCyclic(vertex)==true)  cout<<"Graph contains cycle\n";
	    else                        cout<<"Graph doesn't contain cycle\n";


       cout<<endl;
       return 0;
}



