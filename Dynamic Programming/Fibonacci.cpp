#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
        int dp[n];
        for(int i=0; i<n; i++)
        {
            if(i==0 || i==1)
            {
                dp[i]=1;
            }
            else
            {
                dp[i] = dp[i-2] + dp[i-1];
            }
        }
        return dp[n-1];
}

int main()
{
	int  n;
	  cin>>n;
       cout<< fib(n)<<endl;
	return 0;
}


/*
Top down approach
Code : https://ideone.com/nvV15K
*/

