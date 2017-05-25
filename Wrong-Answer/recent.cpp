#include<bits/stdc++.h>
using namespace std;


int t,n,m,x,y,k,i,ans;
bool used[100005][11];
vector<int> v[100005][11];
void dfs(int u, int e)
{
    used[u][k]=true;
    for(int i=0;i<v[u][k].size();i++)
        if(!used[v[u][k][i]][k] && v[u][k][i]!=e)
            dfs(v[u][k][i],u);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            v[x][k].push_back(y);
            v[y][k].push_back(x);
        }
        for(i=0;i<n;i++)
        {
            if(!used[i][k])
            {
                ans++;
                dfs(i,-1);
            }
        }
        cout<<ans<<endl; ans=0; k++;
    }
}

