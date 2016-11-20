#include<bits/stdc++.h>
#define pii pair<int,int>
#define infinity 999999999999999999
using namespace std;

long long int n,m,u,v,w,d[1000000],dir[1000000];
vector<pii>G[1000000];
priority_queue<pii,vector<pii>,greater<pii> >q;
vector<int>path;


int main()
{
     int tc, start;

     cin>>n>>m;

     for(int i=0; i<m; i++)
     {
        cin>>u>>v>>w;
        G[u].push_back(pii(w,v));
        G[v].push_back(pii(w,u));
     }

    for(int i=1; i<=n; i++)
    {
        d[i]=infinity;
        dir[i]=-1;
    }

    start = 1;

    q.push(pii(0,start));
    d[start]=0;

    while(!q.empty())
    {
        u=q.top().second;
        q.pop();
        for(int i=0; i<G[u].size();i++)
        {
            v=G[u][i].second;
            w=G[u][i].first;
            if(d[u]+w<d[v])
            {

                d[v]=d[u]+w;
                dir[v]=u;
                q.push(pii(d[v],v));
            }
        }
     }


    if(dir[n]==-1)
    {
       cout<<"-1"<<endl;
    }

    else
    {
        u=n;
        while(u!=-1)
        {
            path.push_back((u));
            u=dir[u];
        }

        for(int i=path.size()-1; i>=0; i--)
        {
           cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
