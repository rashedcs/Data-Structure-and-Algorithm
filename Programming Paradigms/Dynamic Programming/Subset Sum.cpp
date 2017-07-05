//Bottom up
#include<bits/stdc++.h>
using namespace std;

bool issubsetsum(int arr[],int n,int sum)
{
	int i,j;
	bool dp[sum+1][n+1];

	for(i=0;i<=n;i++)   dp[0][i]=true;
	for(i=1;i<=sum;i++) dp[i][0]=false;

	for(i=1; i<=sum; i++)
	{
		for(j=1; j<=n; j++)
		{
           dp[i][j] = dp[i][j-1];
		   if(arr[j-1]<=i)
		   {
			  dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
		   }
		}
	}
	return dp[sum][n];
}


int main()
{
	int t, n, m, i, *arr;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		arr = new int[n];
		for(i=0;i<n;i++) cin>>arr[i];

		if(issubsetsum(arr,n,m)==true)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		free(arr);
	}
	return 0;
}














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
