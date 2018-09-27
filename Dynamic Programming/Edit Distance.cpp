#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    int len1 = a.size();
    int len2 = b.size();
    
    int dp[len+1][len2];

    for(int i=1;i<=len1;i++) dp[i][0]=i;
    for(int i=1;i<=len2;i++) dp[0][i]=i;

    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(A[i-1]==B[j-1]) 
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else 
            {
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    return dp[len1][len2];
}
int main()
{
    string a, string b;
    cin>>a>>b;
    printf("%d\n",solve(a,b);
    return 0;
}
