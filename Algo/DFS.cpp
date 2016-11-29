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









