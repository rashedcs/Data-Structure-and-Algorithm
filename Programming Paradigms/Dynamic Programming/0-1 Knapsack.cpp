//Top down approach : 
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 2001    //You must size+1 otherwise it will shown wrong answer

int  n, val[MAX_N], wt[MAX_N], memo[MAX_N][MAX_N];


int knapSack(int n, int w)
{
   if (memo[n][w] != -1)       return memo[n][w]; //Memoization
	
   if (n == 0 || w == 0)  return 0;  // Base Case : We can not take anything else
	
   else if (wt[n-1] > w)  return memo[n][w] = knapSack(n-1,w);  //We have no choice
	
   //We have two choices : ignore or take this item : we take the maximum value
   else return memo[n][w] = max( knapSack(n-1, w),  val[n-1] + knapSack(n-1, w-wt[n-1]));  
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
      int dp[n+1][W+1];

      for(int i=0; i<=n; i++)
      {
         for(int m=0; m<= W; m++)
         {
             if (i==0 || m==0)        dp[i][m] = 0;

             else if (wt[i-1] <= m)   dp[i][m] = max(val[i-1] + dp[i-1][m-wt[i-1]],  dp[i-1][m]);

             else                     dp[i][m] = dp[i-1][m];
         }
      }
     return dp[n][W];
}


   int main()
   {
	    int n,W,*va,*wt;

	    cin>>W>>n;

	    va = new int[n];

	    wt = new int[n];

	    for(int i=0;i<n;i++)   cin>>va[i]>>wt[i];

	    cout<<knapSack(wt, va, n, W)<<endl;


	    return 0;
    }









//Please : Do not follow below code......It is just daught code not absolute.
//Daught



///Source : Internet


#define MAX_N 2000
#define MAX_W 2000

int   N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];
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

//Source : Internet
int knapSack(int n, int w)
{
   if (memo[n][w] != -1)       return memo[n][w];
   // Base Case
   if (n == 0 || w == 0)  return 0;
 
 
   else if (wt[n-1] > w)  return memo[n][w] = knapSack(n-1,w);
 
   else return memo[n][w] = max(val[n-1] + knapSack(n-1, w-wt[n-1]), knapSack(n-1, w));
}
*/
