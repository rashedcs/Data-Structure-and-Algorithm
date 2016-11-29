  #include<bits/stdc++.h>
  using namespace std;

  vector<int>nodes[1000];

  void bfs(int start, int edges)
  {
       stack<int>stack;

       bool visited[edges];

       for(int i=0;i<edges;i++)
       {
           visited[i]=false;
       }

       stack.push(start);
       visited[start]=true;

       while(!stack.empty())
       {
		   int u = stack.top();
		   cout<<u<<" ";
		   stack.pop();
	       
	           for(vector<int>::iterator it=nodes[u].begin(); it!=nodes[u].end(); it++)
                   {
		 	  if(visited[*it]==false)
		 	  {
				visited[*it] = true;
				stack.push(*it);
			  }
                  }
        }
   }



int main()
{

    int edges,a,b;
    cout<<"Enter the no of edges"<<endl;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>a>>b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	int start;
        cout<<"\nEnter the starting node"<<endl;
        cin>>start;
        bfs(start, edges);

	cout<<endl;
	return 0;

}








Recursive : 

             #include<bits/stdc++.h>
       using namespace std;


       stack<int>S;
       vector<int>adj[1000];

       bool visited[10];//n is no of vertices and graph is sorted in array G[10][10]


       void dfs(int u)
       {
           printf("\n%d",u);
		   visited[u] = true;
		   for(int i=0; i<adj[u].size(); i++)
		   {
			  if (visited[adj[u][i]] == false)
			  {
				dfs(adj[u][i]);
			  }
		   }
       }


      int main()
      {
         int vertex, start, edges, a, b;
	     cin>>vertex>>edges;

	     for(int i=0; i<edges; i++)
	     {
	        cin>>a>>b;
	        adj[a].push_back(b);
	      //  adj[b].push_back(a);
	     }

          cin>>start;

         for(int i=start; i<vertex; i++)
         {
            if(visited[i]==false)  dfs(i);
         }
         cout<<endl;

         return 0;
      }
