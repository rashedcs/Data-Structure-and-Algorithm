//Top down approach
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_W 100

int i, tc, G, ans, N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int value(int id, int w)
{
  if (id == N || w == 0)       return 0;
  else if (memo[id][w] != -1)  return memo[id][w];
  else
  {
     if (W[id] >w)             return memo[id][w] = value(id + 1, w);
     else                      return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
  }
}


int main()
{
	cin>>tc;
	while(tc--)
	{
	    memset(memo, -1, sizeof memo);

	    cin>>N; //Number of value and weight
	    cin>>MW; //Weight

	   // V = new int[N];
	  //  W = new int[N];

	    for(int i=0;i<N;i++)   cin>>V[i];  //Value
	    for(int i=0;i<N;i++)   cin>>W[i];  //Weight

	    cout<<value(0,MW)<<endl;

	}
	return 0;
}
























//0-1 Knaspack 
#include<bits/stdc++.h>
using namespace std;



int knapSack(int wt[], int val[], int n, int W)
{
   int K[n+1][W+1];
   
   for(int i = 0; i <= n; i++)
   {
       for(int w = 0; w <= W; w++)
       {
           if (i==0 || w==0)        K[i][w] = 0;
           else if (wt[i-1] <= w)   K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else                     K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
}


int main()
{
	int tc,n,W,*v,*w;
	cin>>tc;
	while(tc--)
	{
	    cin>>n;

	    cin>>W;

	    v = new int[n];

	    w = new int[n];

	    for(int i=0;i<n;i++)   cin>>v[i];

	    for(int i=0;i<n;i++)   cin>>w[i];

	    cout<<knapSack(w, v, n, W)<<endl;

	}
	return 0;
}
