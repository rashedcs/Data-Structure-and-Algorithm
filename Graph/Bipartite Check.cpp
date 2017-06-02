#include<bits/stdc++.h>
using namespace std;
vector<int> AdjList[201];
vector<int>color;


void checkBipartitie(int n)
{
        queue<int> q;
		q.push(0);
        vector<int>color(n, 1e9);
		color[0] = 0;
		bool isBipartite = true;
		while(!q.empty() && isBipartite)
		{
			int u = q.front();
			q.pop();
			for (int j=0; j<AdjList[u].size(); j++)
			{
				int v = AdjList[u][j];
				if (color[v] == 1e9)
				{
					color[v] = 1 - color[u];
					q.push(v);
				}
                else if(color[v] == color[u])
                {
					isBipartite = false;
					break;
				}
			}
		}
    if(isBipartite)
			printf("BICOLORABLE.\n");
    else
			printf("NOT BICOLORABLE.\n");
}


int main()
{
    ios::sync_with_stdio(false);

	int n, m, u, v;

	while(scanf("%d",&n) && n!=0)
	{
		cin>>m;

		while(m--)
		{
			cin>>u>>v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
        checkBipartitie(n);
	}
	return 0;
}
