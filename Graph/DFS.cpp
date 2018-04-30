   #include<bits/stdc++.h>
   using namespace std;

   vector<int>nodes[1000];

   void dfs(int start, int vertex)
   {
         stack<int>stack;

         bool visited[vertex];

         memset(visited,false,sizeof(visited));

         stack.push(start);
         visited[start]=true;

         while(!stack.empty())
         {
		    int u = stack.top();
		    cout<<u<<" ";
		    stack.pop();

		    for(int i=0; i<nodes[u].size(); i++)
		    {
			  int v = nodes[u][i];
			  if(visited[v]==false)
			  {
				visited[v] = true;
				stack.push(v);
			  }
		    }
         }
    }



  int main()
  {
          int start, vertex, edges,a,b;

	   cin>>vertex>>edges;
	   for(int i=0;i<edges;i++)
	   {
		 cin>>a>>b;
		 nodes[a].push_back(b);
		// nodes[b].push_back(a);
	   }

	   cout<<"\nEnter the starting node"<<endl;
	   cin>>start;
	   dfs(start, vertex);

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


/* Input  : Directed graph
    5 5
    1 0
    0 2
    2 1
    0 3
    1 4
    0
    Output : 0 3 2 1 4
    //http://www.geeksforgeeks.org/iterative-depth-first-traversal/
    		          //bool *visited = new bool[V];
	//bool *visited = new bool[V];
        for(int i=0; i<vertex; i++)
        {
            visited[i]=false;
        }
	
            for(vector<int>::iterator it=nodes[u].begin(); it!=nodes[u].end(); it++)
            {
		      if(visited[*it]==false)
		      {
			 visited[*it] = true;
			 stack.push(*it);
		      }
            }
*/




//https://gist.github.com/78526Nasir/c81ec5fd2843d69038cec798e8154460




