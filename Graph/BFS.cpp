//BFS implementation

#include<bits/stdc++.h>
using namespace std;

vector<int>nodes[1000];

void bfs(int start, int vertex)
{

     queue<int>que;

     bool visited[vertex];
   
     for(int i=0; i<vertex; i++)
     {
        visited[i]=false;
     }
  
         //You can use initialize all variable to false to use memset function instead of for loop
    // memset(visited,false,sizeof(visited)); 

         //bool *visited = new bool[V];
	//bool *visited = new bool[V];
     que.push(start);
     visited[start]=true;

     while(!que.empty())
     {
	 int front = que.front();
	 cout<<front<<" ";
	 que.pop();

	 for(vector<int>::iterator it=nodes[front].begin(); it!=nodes[front].end();  ++it)
         {
		  if(visited[*it]==false)
		   {
		        visited[*it]=true;
		       que.push(*it);
		   }
         }
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
		nodes[b].push_back(a);
	}

       cout<<"\nEnter the starting node"<<endl;
       cin>>start;
       bfs(start, vertex);

       cout<<endl;
       return 0;

}





//Best Way :
#include<bits/stdc++.h>
using namespace std;

vector<int>nodes[1000];

void bfs(int start, int vertex)
{

     queue<int>que;

     bool visited[vertex+1];

    /*	
     for(int i=0; i<vertex; i++)
     {
        visited[i]=false;
     }
     */
    //You can use initialize all variable to false to use memset function instead of for loop
     memset(visited,false,sizeof(visited)); 

         //bool *visited = new bool[V];
	//bool *visited = new bool[V];
     que.push(start);
     visited[start]=true;

     while(!que.empty())
     {
	   int u = que.front();
	   cout<<u<<" ";
	   que.pop();
           for(int i=0;i<nodes[u].size();i++)
           {
             int v = nodes[u][i];
             if(visited[v]==false)
             {
                visited[v]=true;
                que.push(v);
             }
          }
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
		  nodes[a].push_back(b); //For directed graph
		  //nodes[b].push_back(a);
	    }

       cout<<"\nEnter the starting node"<<endl;
       cin>>start;
       bfs(start, vertex);

       cout<<endl;
       return 0;

}

