#include<bits/stdc++.h>
#define pii pair<int,int>
#define infinity 999999999999999999
using namespace std;

long long int n,m,u,v,w,i,d[1000000],dir[1000000];
vector<pii>G[1000000];
priority_queue<pii,vector<pii>,greater<pii> >q;
vector<int>print;


int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
    cin>>n>>m;

    while(m--)
    {
        cin>>u>>v>>w;
        G[u].push_back(pii(w,v));
        G[v].push_back(pii(w,u));
    }

    for(i=1; i<=n; i++)
    {
        d[i]=infinity;
        dir[i]=-1;
    }
    q.push(pii(0,1));
    d[1]=0;
    while(!q.empty())
    {
        u=q.top().second;
        q.pop();
        for(i=0;i<G[u].size();i++)
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

     for(int i=1; i<=n; i++)
         {
            if(i == 1)  continue;
            if(d[i] >= infinity) cout<<"-1"<<" ";
            else cout<<d[i]<<" ";
         }
    }

    return 0;
}

