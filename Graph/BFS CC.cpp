//You can use dfs to find the cc
#include<bits/stdc++.h>
using namespace std;

bool visited[100001];
vector <int> adj[100001];



  void bfs(int start)
  {
       queue<int>que;
       que.push(start);

       visited[start]=true;

       while(!que.empty())
       {
	       int u = que.front();
	       que.pop();
           for(int i=0; i<adj[u].size(); i++)
           {
              int v = adj[u][i];
              if(visited[v]!=true)
              {
                 visited[v]=true;
                 que.push(v);
              }
           }
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
            bfs(i);
            cc++;
         }
       }
       cout<<cc<<endl;
    }
    return 0;
}
