// Longest Common Subsequence Dynamic Problem
// Given two string . Find the longest common subsequence between them .
// Tabulation Method
// Time Complexity O(m*n)
// m -> 1st string length n -> 2nd string length
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define mx 2000
#define memo(a,b) memset(a,b,sizeof(a))
char A[mx+10],B[mx+10];
int dp[mx+10][mx+10];
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
