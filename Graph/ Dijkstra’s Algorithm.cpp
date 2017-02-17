//Source : http://ideone.com/vGPHXA
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define inf 999999


 long long int n,m,u,v,w;


void dijkstra(int start, vector<pii>G[])
 {

      priority_queue<pii,vector<pii>,greater<pii> >q;

      long long int dist[1000000],prev[1000000];
      vector<int>path;


      memset(dist,inf,sizeof(dist));
      memset(prev,-1,sizeof(prev));


     q.push(pii(0,start));
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
        G[u].push_back(pii(w,v));
        G[v].push_back(pii(w,u)); ///Ai line ta na dile directed hoye jabe.
     }

     int start = 1;
     dijkstra(start,G);

    return 0;
}


//Simple Way : http://ideone.com/QknEbW
