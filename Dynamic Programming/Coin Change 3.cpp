   /* Problem Source : Programming Contest Variant 3 */
    #include <bits/stdc++.h>
    using namespace std;

    int coinChange(int amount, vector<int>& coins) 
    {
                int dp[amount+1]={};
                dp[0] = 1;

                for (int i=0;  i<coins.size();  i++) 
                {
                    for (int j=amount; j>=1; j--) 
                    {
                        if(j>=coins[i] and dp[j-coins[i]]) 
                        {
                            dp[j] = 1;
                        }
                    }
                }
                return dp[amount];

    }

    int main() 
    {
        int n, amount;
        cin>>n>>amount;
        vector<int>coins(n);
        for(int i=0; i<n; i++) cin>>coins[i];
        cout<<coinChange(amount,coins)<<endl;
    }
