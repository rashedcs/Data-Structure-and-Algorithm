
// Subset Sum Dynamic Problem
// N is the size of array and sum is the target to make by summing all or few elements of the array
// Recursive Method
#include <cstdio>
#include <cstring>
using namespace std;
#define memo(a,b) memset(a,b,sizeof(a))
#define mx 10000
int dp[50][mx+10] ,arr[mx+10];
int solve(int N,int sum)
{
    if(sum==0) return 1;
    if(N==0&&sum!=0) return 0;
    int &ret = dp[N][sum];
    if(ret!=-1) return ret ;
    if(sum-arr[N]<0) return ret = solve(N-1,sum);
    return ret = solve(N-1,sum-arr[N])||solve(N-1,sum);
}


int main()
{
    int N , sum ;
    scanf("%d%d",&N,&sum);
    for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
    memo(dp,-1);
    if(solve(N,sum)) puts("YES");else puts("NO");
    return 0;
}
