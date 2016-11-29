#include<bits/stdc++.h>
using namespace std;

vector<int>nodes[1000];

void bfs(int start, int edges)
{

    queue<int>que;

    bool visited[edges];

    for(int i=0;i<edges;i++)
    {
       visited[i]=false;
    }


    que.push(start);
    visited[start]=true;


	cout<<"\nBFS Traversal\n";

     while(!que.empty())
     {
		 int front = que.front();
		 cout<<front<<" ";
		 que.pop();

	     for(vector<int>::iterator it=nodes[front].begin();
		 it!=nodes[front].end();++it)
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









