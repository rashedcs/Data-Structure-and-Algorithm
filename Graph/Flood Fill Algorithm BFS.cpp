#include<bits/stdc++.h>
using namespace std;


int grid[20][20];
int vis[20][20];


int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};


int n, m,  sum;

int safe(int n, int m,int x, int y)
{
   return x>=0 && y>=0 && x<n && y<m;
}


void bfs(int n, int m,int sx, int sy, int k)
{
    queue< pair<int, int> > Q;


    Q.push(make_pair(sx,sy));
    int oc = grid[sx][sy];

    vis[sx][sy]=1;
    grid[sx][sy] = k;


    while(!Q.empty())
    {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++)
        {
           int a = r+dr[i];
           int b = c+dc[i];

            if(safe(n,m,a,b) && !vis[a][b] && grid[a][b]==oc)
            {
                grid[a][b]=k;
                vis[a][b]=1;
                Q.push(make_pair(a,b));
            }
        }
    }

}



int main()
{
    ios::sync_with_stdio(false);
    int tc, n, m, dx, dy, k;

    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;

        memset(grid,0,sizeof(grid));
        memset(vis, 0, sizeof(vis));
      //  memset(dist, 0, sizeof(dist));

        for(int i=0; i<n; i++)
        {
           for(int j=0; j<m; j++)
           {
              cin>>grid[i][j];
           }
        }

        cin>>dx>>dy>>k;

        bfs(n,m,dx, dy, k);

        for(int i=0; i<n; i++)
        {
           for(int j=0; j<m; j++)
           {
              cout<<grid[i][j]<<" ";
           }
        }

        cout<<endl;
    }
    return 0;
}
//Link : http://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
