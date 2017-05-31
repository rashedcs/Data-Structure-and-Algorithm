//Al pair shortest path
#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000



int main()
{
  ios::sync_with_stdio(false);

  long int V, E, u, v, w;

  cin>>V>>E;
  long int  AdjMatrix[V][E];
  for(int i=1; i<=V; i++)
  {
     for(int j=1; j<=V; j++)
     {
        AdjMatrix[i][j] = INF;
        AdjMatrix[i][i] = 0;
     }
  }

  for (int i=1; i<=E; i++)
  {
    cin>>u>>v>>w;
    AdjMatrix[u][v] = w;
  }

  for(int k=1; k<=V; k++)
  {
    for(int i=1; i<=V; i++)
    {
       for(int j=1; j<=V; j++)
       {
          AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
       }
    }
  }

  for (int i=2; i<=V; i++)
  {
    cout<<AdjMatrix[1][i]<<" ";
  }
  cout<<endl;


  return 0;
}

//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-problem/
SAMPLE INPUT 
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5
SAMPLE OUTPUT 
5 2 3 7

