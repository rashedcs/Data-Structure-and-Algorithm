//Problem : https://www.hackerrank.com/challenges/bfsshortreach 
 
  #include<bits/stdc++.h>
  using namespace std;


  void bfs(int start, int vertex, vector<int>nodes[])
  {
        queue<int>que;

        bool visited[vertex+1];
        int dist[vertex+1];

        memset(visited,false,sizeof(visited)); 
      
        memset(dist,false,sizeof(dist)); 



       que.push(start);

       visited[start]=true;
       dist[start]=0;

       while(!que.empty())
       {
	       int u = que.front();
	       que.pop();
           for(int i=0; i<nodes[u].size(); i++)
           {
             int v = nodes[u][i];
             if(!visited[v])
             {
                visited[v]=true;
                dist[v]=dist[u]+1;? 
                //Each node is labeled from  to  and the edge between any two nodes is always of length is 1
                que.push(v);
             }
           }
      }

      for(int i=1; i<=vertex; i++)
      {
         if(start!=i)
         {
            if(dist[i]==false)   cout<<"-1 ";
            else                 cout<<dist[i]<<" ";
         }
      }
      cout<<endl;
  }



 int main()
 {
       int tc, start, vertex, edges,a,b;
       

       cin>>tc;
       while(tc--)
       {
	      cin>>vertex>>edges;
        vector<int>nodes[vertex+1];
	      for(int i=0; i<edges; i++)
	      {
		     cin>>a>>b;
		     nodes[a].push_back(b);
		     nodes[b].push_back(a);
	      }

          cin>>start;
          bfs(start, vertex,nodes);

       }

       return 0;

  }
