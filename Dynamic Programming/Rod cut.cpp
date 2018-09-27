#include<bits/stdc++.h>
using namespace std;

int rodcut(int price[], int n)
{
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            dp[i] = max(dp[i], price[j-1]+dp[i-j]);
        }
    }
    return dp[n];
}

int main()
{
	  int n, arr[100];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<rodcut(arr, n)<<endl;
  	return 0;
}
