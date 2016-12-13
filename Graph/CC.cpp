#include<bits/stdc++.h>
using namespace std;


list<int> adj[1000];


void DFS(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])  DFS(*i, visited);
    }
}


void connectedComponents(int V)
{
    bool *visited = new bool[V];
    memset(visited,false,sizeof(visited));
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            DFS(v, visited);
            cout<<endl;
        }
    }
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

        connectedComponents(vertex);

        cout<<endl;
        return 0;

}




