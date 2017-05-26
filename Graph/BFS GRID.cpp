//Source : http://ideone.com/KGV9ft

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
char arr[1010][1010];
 
int vis[1010][1010];
int dist[1010][1010];
 
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
 
int n, m;
 
int safe(int x,int y)
{
  return x>=0 && y>=0 && x<n && y<m;
}
 
 
void bfs(int sx, int sy)
{
	queue< pii >q;
	q.push(pii(sx,sy));
 
    vis[sx][sy]=1;
    dist[sx][sy]=1;
 
	while(!q.empty())
	{
		pii top=q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int a = top.first + dr[i];
			int b = top.second + dc[i];
 
            if(safe(a,b) && !dist[a][b] && (int)arr[a][b]!=(int)arr[top.first][top.second])
            {
               q.push(pii(a,b));
               dist[a][b] = dist[top.first][top.second]+1;
               vis[a][b]=1;
            }
		}
	}
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    int tc;
 
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
 
        memset(arr,0,sizeof(arr));
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
 
        for(int i=0; i<n; i++)
        {
          cin>>arr[i];
        }
        bfs(0,0);
        if(!vis[n-1][m-1])
            cout<<"-1\n";
        else
            cout<<dist[n-1][m-1]<<endl;
    }
    return 0;
}
 
