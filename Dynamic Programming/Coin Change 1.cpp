#include<bits/stdc++.h>
using namespace std;


int coinChange(int arr[], int n, int k)
{
        int dp[k+1]={};
        dp[0] = 1;
        for (int i=0; i<n; i++) 
        {
            for (int j=1; j<=k; j++) 
            {
                if(arr[i]<=j) dp[j] += dp[j - arr[i]];
            }
        }
        return dp[k]; 
}


int main()
{
        int  n, k;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        cout<<coinChange(arr, n, k)<<endl;
    
	return 0;
}
