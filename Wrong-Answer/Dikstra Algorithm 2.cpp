///Ai duitar compare code sundor code korbe



#include<bits/stdc++.h>
using namespace std;
//#define INF (1<<20)
//#define pp pair<int,int>
typedef pair< int, int >pii;

const int MAX = 3001;

const int INF = 0x3f3f3f3f;

vector< pii > G[MAX];
int d[MAX];

/*
struct greater
{
    bool operator() (const pp &p1, const pp &p2)
    {
        return p1.second<p2.second;
    }
};

*/



void dijkstra(int start)
{
    int u, v, c, w;

    priority_queue< pii, vector<pii>, greater<pii> >Q;

    memset(d, 0x3f, sizeof d);
    // 
   /*Initialize all node are infinity
    for(int i=1;i<=n;i++)
    {
      d[i]=INF;
    }
    */
    d[start] = 0;
    Q.push(pii(0, start));


    while(!Q.empty())
    {
        u = Q.top().second; // node
        //c = Q.top().first; // node cost so far
        Q.pop(); // remove the top item.

       // if(d[u] < c) continue;

        for(int i = 0; i < G[u].size(); i++)
        {
            v = G[u][i].first; // node
            w = G[u][i].second; // edge weight

            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}



int main()
 {
    int n, e,  u, v, w, start, tc;

    cin>>tc;
    while(tc--)
    {
      cin>>n>>e;
      {

         for(int i = 0; i < e; i++)
         {
            cin>>u>>v>>w;
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w)); // only if bi-directional
         }

         cin>>start;

         dijkstra(start);

         for(int i=1; i<=n; i++)
         {
            if(i == start)  continue;
            if(d[i] >= INF) cout<<"-1"<<" ";
            else cout<<d[i]<<" ";
         }

       }
    }
    return 0;
}
