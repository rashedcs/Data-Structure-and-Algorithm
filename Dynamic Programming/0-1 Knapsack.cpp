
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
	    for(int i=0;i<n;i++)
	    {
		    cin>>va[i]>>wt[i];
	    }
	    cout<<knapSack(wt, va, n, W)<<endl;
	    return 0;
    }




