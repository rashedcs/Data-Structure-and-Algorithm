 //Lab
   #include<bits/stdc++.h>
   #define inf 9999
   using namespace std;

   int node, m, a,b,c;
   vector<int> cost[3000+1];




   void dijkstra(int source, vector<int>G[])
   {

     queue <int> x;
     vector<int> path;

     int distance[1000000];
     int prev[1000000];


     for(int i=1; i<=node; i++)
     {
        distance[i] = inf;
        prev[i] = -1;
     }

     distance[source] = 0;
     x.push(source);


     while(!x.empty())
     {
        int u = x.front();
        x.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int p = G[u][i];

            if(distance[u] + cost[u][i] < distance[p])
            {
                distance[p] = distance[u] + cost[u][i];
                x.push(p);
                prev[p] = u;
            }
        }
     }

     int start = node;

     if(prev[node]==-1)
     {
       cout<<"-1"<<endl;
     }

     else
     {
        while(start!=-1)
        {
          path.push_back(start);
          start = prev[start];
        }

        for(int i=path.size()-1; i>=0; i--)
        {
           cout<<path[i]<<" ";
        }
     }
  }


int main()
{

     cin>>node>>m;

     vector<int> G[node+1];

     for(int i=0; i<m; i++)
     {
        cin>>a>>b>>c;
        G[a].push_back(b);
        G[b].push_back(a);     ///Ata na dile shudhu directed ar moto kaz korbe
        cost[a].push_back(c);
        cost[b].push_back(c); ///Ata na dile shudhu directed ar moto kaz korbe
     }

     int start = 1;
     dijkstra(start,G);

     return 0;
}



//Daught Program : http://ideone.com/tWbmpl

