// Best way : https://www.hackerrank.com/challenges/dijkstrashortreach

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define inf 999999


 long long int n,m,u,v,w;


void dijkstra(int edge, int start, vector<pii>G[])
 {

     priority_queue< pii,vector<pii>,greater<pii> >q;

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

















