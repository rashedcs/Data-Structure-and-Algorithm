#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;


class Edge{
    public: int u,v,weight;
    Edge(int u,int v,int weight): u(u), v(v), weight(weight) { }
};
int main()
{
    int T; cin>>T;
    while(T--){
    vector<Edge> G;
    vector<int> D;
    int n,v,e,u,w;
    cin>>n>>e;
    D.resize(n,inf);
        
    while(e--) 
    {    
        cin>>u>>v>>w;  
        G.push_back(Edge(u-1,v-1,w));     
        G.push_back(Edge(v-1,u-1,w)); 
    }
        
    cin>>u;
    D[u-1]=0;
        
    for(int i=1;i<=n-1;i++)
        for(int j=0;j<G.size();j++)
         {
            if(D[G[j].u]!=inf && D[G[j].v] > D[G[j].u] + G[j].weight)   D[G[j].v] = D[G[j].u] + G[j].weight;
         }
        
         for(int i=0;i<n;i++)
         {
           if(i==u-1) continue;
           cout<<(D[i]==inf? -1:D[i])<<" ";
         }
        cout<<endl;
     }
}
