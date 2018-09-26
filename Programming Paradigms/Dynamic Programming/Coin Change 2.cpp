	int coinChange(vector<int>& coins, int amount)
	{
                int max = amount+1; 
		vector<int> dp(amount+1, max); //fill with max cause it can not exceeds max
        
		dp[0] = 0;
		for (int i=0; i<coins.size(); i++)
		{
			for (int j=1; j<=amount; j++)
			{
				if(j>=coins[i]) 
				{
				    dp[j]=min(dp[j], dp[j-coins[i]]+1);
				}
			}
		}
		if (dp[amount]<max) return dp[amount];
		else return -1;
	}
