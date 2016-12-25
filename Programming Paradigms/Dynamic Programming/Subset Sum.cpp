//Top down dp

#include<bits/stdc++.h>
using namespace std;

#define mx 1000

int dp[50][mx+10] ,arr[mx+10];

int solve(int N,int sum)
{
    if(dp[N][sum]!=-1)      return dp[N][sum];
    if(sum==0)              return 1;  //Base Case
    if(N==0 && sum!=0)      return 0;  //Failure Base Case
    else if(sum-arr[N]<0)   return dp[N][sum] = solve(N-1, sum);
    else                    return dp[N][sum] = solve(N-1,sum) || solve(N-1,sum-arr[N]) ;
}


int main()
{

    int N , sum;
    cin>>N>>sum;
    for(int i=1;i<=N;i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    if(solve(N,sum)) cout<<"YES"<<endl;
    else             cout<<"NO"<<endl;
    return 0;
}
