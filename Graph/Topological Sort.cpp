    #include<bits/stdc++.h>
    using namespace std;

    const int MAX = 2e5 + 5;

    vector<int> adj[MAX];
    vector<int>topological_order;

    stack<int>S;
    bool visited[MAX];


    void dfs(int u)
    {
		  visited[u] = true;

		  for(size_t i=0; i<adj[u].size(); ++i)
		  {
			  if (visited[adj[u][i]] == false)    dfs(adj[u][i]);
		  }
     
		  S.push(u);
    }

    void topologicalSort(int V)
    {
	  	for(int i=0; i<V; ++i)
	  	{
			  if(visited[i]==false)
			  {
			   	dfs(i);
		 	  }
		 }

	  while(!S.empty())
	  {
		  topological_order.push_back(S.top());
			 S.pop();
  	}
 }


   int main()
   {
      int vertex, edges, a, b;
	    cin>>vertex>>edges;

	    for(int i=0; i<edges; i++)
	    {
	       cin>>a>>b;
	       adj[a].push_back(b);
	    }

     topologicalSort(vertex);

     for(int i=0; i<vertex; ++i)
 	   {
	      printf("%d ", topological_order[i]);
	   }

	   cout<<endl;
	   return 0;
     
   }

