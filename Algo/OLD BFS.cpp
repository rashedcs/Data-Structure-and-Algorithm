//Adjacency list to store graph
vector<int> adjlist[NMAX];
 
//Arrays
char visited[NMAX];
int distance[NMAX];
 
//Read Graph
//First read number of vertices (N) and edges (M)
//Then read the (undirected) edges
//Note that vertices are zero-indexed
int N,M;
scanf("%d%d",&N,&M);
 
for(int i=0;i<M;i++)
{
  int a,b;
  scanf("%d%d",&a,&b);
  adjlist[a].push_back(b);
  adjlist[b].push_back(a);
}
 
//Now do the BFS from vertex 0 to find distances to all vertices
//Start by initialising all visited values as 0 and distances as -1
memset(visited,0,sizeof visited);
memset(distance,-1,sizeof distance);
 
//Create the BFS queue and put the start vertex in
distance[0]=0;
visited[0]=1;
 
queue<int> bfsq;
bfsq.push(0);
 
//BFS
while(!bfsq.empty())
{
  int u=bfsq.front();
  bfsq.pop;
 
  //Now look at all neighbours of u
  for(int i=0;i<adjlist[u].size();i++)
  {
    int v=adjlist[u][i];
 
    //If v has not been processed yet, do that now
    if(!visited[v])
    {
      visited[v]=1;
      distance[v]=distance[u]+1;
      bfsq.push(v);
    }
  }
}  
 
