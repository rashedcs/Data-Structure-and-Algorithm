#include<bits/stdc++.h>
   using namespace std;

   vector<int>nodes[1000];

   void dfs(int start, int vertex)
   {
        stack<int>stack;

        bool visited[vertex];

       /*
        for(int i=0; i<vertex; i++)
        {
            visited[i]=false;
        }
        */
         memset(visited,false,sizeof(visited));
        //bool *visited = new bool[V];
	    //bool *visited = new bool[V];
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
           /*
            for(vector<int>::iterator it=nodes[u].begin(); it!=nodes[u].end(); it++)
            {
              if(visited[*it]==false)
              {
                visited[*it] = true;
                stack.push(*it);
              }
            }
          */
         }
     }



  int main()
  {

       int start, vertex, edges,a,b;

       cout<<"Enter the no of vertex and edges"<<endl;
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
*/




//https://gist.github.com/78526Nasir/c81ec5fd2843d69038cec798e8154460



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
https://www.codechef.com/viewsolution/8931801
