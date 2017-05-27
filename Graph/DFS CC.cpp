#include<bits/stdc++.h>
using namespace std;
 
bool visited[100001];
vector <int> adj[100001];
 
 
void dfs(int v)
{
    visited[v]=true;
    for(int i=0; i<adj[v].size(); i++)
    {
      if(visited[adj[v][i]]!=true)  dfs(adj[v][i]);
    }
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    int tc, u,v, cc, node, edge;
 
    cin>>tc;
    while(tc--)
    {
       cc=0;
       cin>>node>>edge;
       memset(adj,0,sizeof(adj));
       memset(visited,false,sizeof(visited));
 
       for(int i=0; i<edge; i++)
       {   cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
 
       for(int i=0; i<node; i++)
       {
         if(visited[i]!=true)
         {
            dfs(i);
            cc++;
         }
       }
       cout<<cc<<endl;
    }
    return 0;
}










































Daught: 

#include<bits/stdc++.h>
using namespace std;


list<int> adj[100001];


void DFS(int v, bool visited[])
{
    visited[v] = true;
    if(v!=0) cout<<v<<",";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])  DFS(*i, visited);
    }
}


void connectedComponents(int V)
{
    int cc=0;
    bool *visited = new bool[V];
    memset(visited,false,sizeof(visited));
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            DFS(v, visited);
            //cout<<",";
            cc++;
        }
    }
    cout<<cc;
}


int main()
{

        int tc, start, vertex, edges,a,b;
        cin>>tc;
    while(tc--){
	    cin>>vertex>>edges;
	    for(int i=0;i<edges;i++)
	    {
		   cin>>a>>b;
		   adj[a].push_back(b);
		   adj[b].push_back(a);
	    }

        connectedComponents(vertex);
        cout<<endl;
    }
        return 0;

}


