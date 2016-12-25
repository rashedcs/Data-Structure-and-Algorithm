//Top down approach
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 2001    //You must size+1 otherwise it will shown wrong answer

int  n, val[MAX_N], wt[MAX_N], memo[MAX_N][MAX_N];


int knapSack(int n, int w)
{
   if (memo[n][w] != -1)       return memo[n][w];
   // Base Case
   if (n == 0 || w == 0)  return 0;


   else if (wt[n-1] > w)  return memo[n][w] = knapSack(n-1,w);

   else return memo[n][w] = max(val[n-1] + knapSack(n-1, w-wt[n-1]), knapSack(n-1, w));
}




int main()
{
         int n, mw;
         memset(memo, -1, sizeof memo);

         cin>>mw>>n;

         for(int i=0;i<n;i++)   cin>>wt[i]>>val[i];

         cout<<knapSack(n,mw)<<endl;

         return 0;
}







//Bottom Up Approach
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














//Please : Do not follow below code......It is just daught code not absolute.
//Daught : 
//Source : 

/*
Source : competitive programming 3

#define MAX_N 2000
#define MAX_W 2000

int   N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int value(int id, int w)
{
  if (id == N || w == 0)       return 0; //Base Case
  else if (memo[id][w] != -1)  return memo[id][w];
  else  if (W[id] >w)          return memo[id][w] = value(id + 1, w);
  else                         return memo[id][w] = max(value(id + 1, w),  V[id] + value(id + 1, w - W[id]));

}





Source : Internet

int value(int id, int w)
{
  if (id == N || w == 0)       return 0;
  else if (memo[id][w] != -1)  return memo[id][w];
  else
  {
       if (W[id] >w)       memo[id][w] = value(id + 1, w);
       else               memo[id][w] = max( value(id + 1, w), V[id] + value(id + 1, w-W[id]));

      return  memo[id][w];
  }
}

Source : Internet

int knapSack(int n, int w)
{
   if (memo[n][w] != -1)       return memo[n][w];
   // Base Case
   if (n == 0 || w == 0)  return 0;
 
 
   else if (wt[n-1] > w)  return memo[n][w] = knapSack(n-1,w);
 
   else return memo[n][w] = max(val[n-1] + knapSack(n-1, w-wt[n-1]), knapSack(n-1, w));
}
*/
