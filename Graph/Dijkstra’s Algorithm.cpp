// Best way : https://www.hackerrank.com/challenges/dijkstrashortreach

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define inf 999999


 long long int n,m,u,v,w;


void dijkstra(int edge, int start, vector<pii>G[])
 {

     priority_queue< pii, vector<pii>, greater<pii> >q;

      long long int prev[1000000];
      memset(prev,-1,sizeof(prev));

      vector<int>path;


     long long int  dist[1000000];
     memset(dist,inf,sizeof(dist));
    //  vector<int>dist(1000000, inf); //





     q.push(make_pair(0,start));
     dist[start]=0;

     while(!q.empty())
     {
        u=q.top().second;
        q.pop();
        for(int i=0; i<G[u].size();i++)
        {
            v=G[u][i].second;
            w=G[u][i].first;

            if(dist[u]+w<dist[v])
            {

                dist[v]=dist[u]+w;
                prev[v]=u;
                q.push(pii(dist[v],v));
            }
        }
     }

    if(prev[n]==-1)
    {
       cout<<"-1"<<endl;
    }

    else
    {
        u=n;
        while(u!=-1)
        {
            path.push_back((u));
            u=prev[u];
        }

        for(int i=path.size()-1; i>=0; i--)
        {
           cout<<path[i]<<" ";
        }
        cout<<endl;
    }
}






int main()
{

     cin>>n>>m;
     vector<pii>G[n+1];

     for(int i=0; i<m; i++)
     {
        cin>>u>>v>>w;
        //G[u].push_back(pii(w,v));
         G[u].push_back(make_pair(w,v));
        //G[v].push_back(pii(w,u));
         G[v].push_back(make_pair(w,u));
     }

     int start = 1;
     dijkstra(m,start,G);

    return 0;
}










// Does not support negative cycle .
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int u , w ; // u is the road number and w is the total cost needed to reach u from source
};
class cmp
{
    public :
    bool operator () (node &a,node &b)
    {
        if(a.w>b.w) return true; else return false; // Sorted in ascending order according to cost
    }
};
vector <int> graph[100+10];
vector <int> cost[100+10];
int Dijkstra(int N,int source,int destination)
{
    bool visit[100+10] ;
    for(int i=1;i<=100;i++) visit[i]=false;
    priority_queue <node,vector<node>,cmp> Q;

    node n;
    n.u=source;n.w=0;
    Q.push(n);
    while(Q.size()!=0)
    {
        n = Q.top(); Q.pop();
        int u = n.u , w = n.w;
        if(visit[u]) continue;
        visit[u]=true;
        if(u==destination) return w;

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(visit[v]==false)
            {
                n.u=v ; n.w=w+cost[u][i];
                Q.push(n);
            }
        }
    }
    return -1; //Not found any path between source and destination
}
int main()
{
    int N,M; //N is the node numbers and M is the relation numbers
    scanf("%d%d",&N,&M);
    while(M--)
    {
        int u , v , w; // from node u to v is cost w
        scanf("%d%d%d",&u,&v,&w);
        graph[u].push_back(v);
        cost[u].push_back(w);
    }
    int x , y ; // Find the minimum distance from x to y
    scanf("%d%d",&x,&y);
    printf("%d\n",Dijkstra(N,x,y));
    return 0;
}







  #include<bits/stdc++.h>
  using namespace std;
  #define INF 99999999
  #define pb push_back
  #define mp make_pair
  #define pi pair<int,int>

  vector<pair<int,int> >::iterator it;
  vector<pair<int,int> >adj[10000];


  vector<int> dijkstra(int s, int n)
  {
     vector<int>d;
     d.resize(n+1);
      
     for(int i=0; i<=n; i++)  d[i]=INF;
     
     set<pair<int,int> >q;
     bool vis[n+1];
     memset(vis,false,sizeof(vis));
     vis[s]=true;
     d[s]=0;

     q.insert(mp(0,s));
     while(!q.empty())
     {
        pair<int,int> top = *q.begin();
        q.erase(q.begin());

        int u=top.second;
        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
           int cost=it->first;
           int v=it->second;

           if(d[v]>d[u]+cost)
           {
              if(d[v]!=INF) q.erase(q.find(mp(d[v],v)));
              d[v]=d[u]+cost;
              q.insert(mp(d[v],v));
           }
         }
      }
      return d;
   }

  int main()
  {
    int T,r,x,y,n,m,i,s,d;

    cin>>T;
    while(T--)
    {
      cin>>n>>m;
      for(i=0; i<n+1; i++)
      adj[i].clear();
      vector<int>dist;
      dist.resize(n+1);
      for(i=0; i<m;i++)
      {
        cin>>x>>y>>r;
        adj[x].pb(mp(r,y));
        adj[y].pb(mp(r,x));
      }
      cin>>s;
      dist=dijkstra(s,n);

      for(i=1; i<=n; i++)
      {
        if(i!=s)
        {
            if(dist[i]!=INF)  cout<<dist[i]<<" ";
            else              cout<<"-1 ";
        }
      }
      cout<<endl;
    }
    return 0;
 }

















