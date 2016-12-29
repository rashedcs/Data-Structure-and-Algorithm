// Longest Palindromic Subsequence Dynamic Problem
Source : copied
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define memo(a,b) memset(a,b,sizeof(a))
char arr[1000];
int dp[1000][1000];
int solve(int low,int high)
{
    if(low>high) return 0;
    if(low==high) return 1;
    int &ret = dp[low][high];
    if(arr[low]==arr[high]) return ret = 2 + solve(low+1,high-1);
    else return ret = max(solve(low+1,high),solve(low,high+1));
}
int main()
{
    scanf("%s",&arr);
    memo(dp,-1);
    cout<<solve(0,strlen(arr)-1)<<endl;
    return 0;
}
