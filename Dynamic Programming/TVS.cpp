http://wikistack.com/traveling-salesman-problem-dynamic-programming/
#include<bits/stdc++.h>
using namespace std;

#define maxn 100;

int g[10][100];
int p[10][100];
int graph[10][10];

int tsp(int city, int start, int set, int npow)
{
  int masked, mask, result = -1, temp;
  if (g[start][set] != -1)
    {
      return g[start][set];
    }
  else
    {
      for (int x = 0; x < city; x++)
    {
      mask = npow - 1 - (int) pow (2, x);
      masked = set & mask;
      if (masked != set)
        {
          temp = graph[start][x] + tsp (city, x, masked, npow);
          if (result == -1 || result > temp)
        result = temp;
          p[start][set] = x;
        }
    }
    }
   g[start][set] = result;
   return result;
}


int main ()
{
    int city, npow;
    cin>>city;
    npow = city*city;

    memset(g,-1,sizeof(g));
    memset(p,-1,sizeof(p));

  	for( int i=0; i<city; i++)
  	{
      for ( int j=0; j<city; j++)
      {
        cin>>graph[ i ][ j ];
      }
    }

    for (int i = 0; i < city; i++)
    {
      g[i][0] = graph[i][0];
    }
    //cout << "The min cost is :";
    cout << tsp(city,0, npow - 2, npow)<<endl;
    cout << endl;
    return 0;
}


























#include<bits/stdc++.h>
using namespace std;


#define city 4
#define npow 16            // pow(2,city)

// adjacency matrix of graph
int graph[city][city] = {
                 {0, 8, 12, 25},
                 {8, 0, 21, 10},
                 {12, 21, 0, 30},
                 {25, 10, 30, 0}
           };

 int g[city][npow];
 int p[city][npow];

 int tsp (int start, int set)
  {
    int masked, mask, result = -1, temp;
    if (g[start][set] != -1)
    {
      return g[start][set];
    }
    else
    {
       for (int x = 0; x < city; x++)
       {
         mask = npow - 1 - (int) pow (2, x);
         masked = set & mask;
         if(masked != set)
         {
           temp = graph[start][x] + tsp (x, masked);
           if (result == -1 || result > temp)  result = temp;
            p[start][set] = x;
         }
       }
     }
   g[start][set] = result;
   return result;
}

int tsphelper ()
{
  for (int i = 0; i < city; i++)
    {
      for (int j = 0; j < npow; j++)
    {
      g[i][j] = -1;
      p[i][j] = -1;
    }
    }

// init matrix g ,from distance matrix graph
  for (int i = 0; i < city; i++)
    {
      g[i][0] = graph[i][0];
    }

  return tsp (0, npow - 2);
}

int
main ()
{
  cout << "The min cost is :";
  cout << tsphelper ();
  cout << endl;
  return 0;
}
