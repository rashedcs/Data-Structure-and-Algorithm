// Best way : https://www.hackerrank.com/challenges/dijkstrashortreach


#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define inf 999999


 long long int n,m,u,v,w;


void dijkstra(int start, vector<pii>G[])
 {
      priority_queue<pii,vector<pii>,greater<pii> >q;

      vector<int>path;

      long long int dist[1000000];
      memset(dist,inf,sizeof(dist));
 
      //  vector<int>dist(1000000, inf); // instead of 17 -18 line but run time error
     
 
      long long int dist prev[1000000]; 
      memset(prev,-1,sizeof(prev));
    


     q.push(pii(0,start)); // q.push(make_pair(0,start));
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
       
        // G[u].push_back(make_pair(w,v));
       //  G[v].push_back(make_pair(w,u));
     }

     int start = 1;
     dijkstra(start,G);

    return 0;
}
//This program : //Source : http://ideone.com/vGPHXA
//Similarly but wrong :  http://ideone.com/VnN41N
//Simple Way : http://ideone.com/QknEbW
// Another way : //Source : http://ideone.com/vGPHXA
