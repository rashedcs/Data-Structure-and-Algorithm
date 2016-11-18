#include<bits/stdc++.h>
#define pp pair<int,int>
#define INF (1<<20)
using namespace std;


struct comp
{
    bool operator() (const pp &p1, const pp &p2)
    {
        return p1.second<p2.second;
    }
};



int main()
{
    priority_queue< pp, vector<pp>, comp>q;
    int n, s, e,u,v,w;

    cin>>n>>e;

    vector<pp> g[n+1];

    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(pp(v,w));
        g[v].push_back(pp(u,w));
    }

    s = 1;
    int d[n+1];

    ///Initialize all node are infinity
    for(int i=1;i<=n;i++)
    {
      d[i]=INF;
    }

    d[s]=0;
    q.push(pp(s,d[s]));

    while(!q.empty())
    {
        u=q.top().first;
        q.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            v=g[u][i].first;
            w=g[u][i].second;

            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push(pp(v,d[v]));
            }
        }
     }
    cout<<d[n]<<endl;

    return 0;
}
