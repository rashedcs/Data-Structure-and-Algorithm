#include<bits/stdc++.h>
using namespace std;

int editDistance(string a, string b)
{
    int m=a.size(), n=b.size();
    int dp[m+1][n+1]={};
    
    for(int i=1;i<=m;i++) dp[i][0]=i;
    for(int i=1;i<=n;i++) dp[0][i]=i;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1]) 
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else 
            {
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main()
{
         string a,b;
         cin>>a>>b;
         printf("%d\n",editDistance(a,b));
         return 0;
}
