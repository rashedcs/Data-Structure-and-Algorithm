#include<bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2)
{
       int n=str1.size(), k=str2.size();
       int dp[n+1][k+1]={}; 
    
	    for(int i=0; i<=n; i++)
	    {
	        for(int j=0; j<=k; j++)
	        {
	            if(i==0||j==0)
	            {
	                dp[i][j]=0;
	            }
	            else if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j]=dp[i-1][j-1]+1;
	            }
	            else
	            {
	                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	            }
	        }
	    }
        return dp[n][k];
}

int main()
{
        string a, b;
    	    cin>>a>>b;
    	    cout<<lcs(a, b)<<endl;
    	return 0;
}
