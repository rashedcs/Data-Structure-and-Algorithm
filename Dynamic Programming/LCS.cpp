//http://ideone.com/tR451k
#include<bits/stdc++.h>
using namespace std;

string A, string B;
int solve(int m,int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)            dp[i][j]=0;
            else if(A[i-1]==B[j-1])   dp[i][j]=1+dp[i-1][j-1];
            else                      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    scanf("%s%s",&A,&B);
    memo(dp,-1);
    printf("%d\n",solve(strlen(A),strlen(B)));
    return 0;
}
