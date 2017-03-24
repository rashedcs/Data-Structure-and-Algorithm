//Bottom up approach
// Edit Distance Dynamic Programing
// Make a string to another string by adding , removing or replacing minimum number of characters
// Tabulation Technique
// Time Complexity O(N*M)
// N -> 1st string length M -> 2nd string length
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char A[2000+10],B[2000+10];
int dp[2000+10][2000+10];
int solve(int len1,int len2)
{
    for(int i=1;i<=len1;i++) dp[i][0]=i;
    for(int i=1;i<=len2;i++) dp[0][i]=i;

    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    return dp[len1][len2];
}
int main()
{
    scanf("%s%s",&A,&B);
    printf("%d\n",solve(strlen(A),strlen(B)));
    return 0;
}



















//Top down approach

#include<bits/stdc++.h>
using namespace std;

char A[2000],B[2000];
int memo[2000][2000];

int editDistance(int n,int m)
{
    if(memo[n][m]!=-1) return memo[n][m];
    if(n==0)         return m;
    if(m==0)         return n;
    return memo[n][m] = min( min( 1+editDistance(n-1,m), 1+editDistance(n,m-1) ),   editDistance(n-1,m-1)+(A[n-1]!=B[m-1]));
}



int main()
{
    ios::sync_with_stdio(false);
    cin>>A>>B;
    memset(memo,-1,sizeof(memo));
    cout<<editDistance(strlen(A),strlen(B))<<endl;
    return 0;
}

