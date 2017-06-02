#include<bits/stdc++.h>
using namespace std;

vector<int>AdjList[200];


void init()
{
	for(int i=0;i<200;i++){
		AdjList[i].clear();
	}
}
void bfs(int V)
{
 		queue<int> q;
		q.push(0);
		vector<int> color(V, -1);
		color[0] = 0;
		bool isBipartite = true;
		while(!q.empty() && isBipartite)
		{
			int u = q.front();
			q.pop();
			for (int j = 0; j < (int) AdjList[u].size(); j++)
			{
				int v = AdjList[u][j];
				if (color[v] == -1)
				{
					color[v] = 1 - color[u];
					q.push(v);
				}
                else if (color[v] == color[u])
                {
					isBipartite = false;
					break;
				}
			}
		}

		if (isBipartite)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");

}


int main()
{
	int V, E, u, v;
	//vector<vi> AdjList;


	while (scanf("%d", &V), V)
	{
	   init();
		//AdjList.assign(V, vi());
		scanf("%d", &E);

		for(int i = 0; i < E; i++)
		{
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
        bfs(V);

	}

	return 0;
}

