#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int a[],int n, int sum)
{
	    bool dp[n+1][s+1];
	    int s = sum/2;
	    for(int i=0; i<=n; i++)
	    {
		for(int j=0; j<=s; j++)
		{
		    if(j==0)        
		    {
			dp[i][j]=1;
		    }
		    else if(i==0 )  
		    {
			dp[i][j]=0;
		    }
		    else if(a[i-1]>j)
		    {
			dp[i][j]=dp[i-1][j];
		    }
		    else if(a[i-1]<=j)
		    {
			dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
		    }
		}
	    }
	    return dp[n][s];
}

int main()
{
	    int  n, sum;
	    sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        sum += arr[i];
	    }
	    if(sum%2!=0 || isSubsetSum(arr, n, sum)==false)
	    {
	          puts("NO"); 
	    }
	    else
	    {
	          puts("YES"); 
	    }
	    return 0;
}
