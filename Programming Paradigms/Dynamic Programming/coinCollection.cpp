// A Dynamic Programming based C++ program to find minimum of coins to make a given change V
//http://www.programcreek.com/2015/04/leetcode-coin-change-java/
//http://www.csegeek.com/csegeek/view/tutorials/algorithms/dynamic_prog/dp_part5.php
//VII - https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/CoinChanging.java

#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
void minCoins(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];

    // Base case (If given value V is 0)
         table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;


    // Compute minimum coins required for all values from 1 to V
    for (int i=1; i<=V; i++)
    {
        cout<<i<<endl;// Go through all coins smaller than i
        for(int k=0; k<m; k++)
        {
          if (coins[k]<=i) //if(i-coins[k]>=0)
          {
            cout<<"i ->"<<i<<"  k ->"<<k<<" coins -> "<<coins[k]<<" table ->"<<table[i]<<" Other -> ";
            cout<<table[i-coins[k]]+1<<endl;
            table[i] = min(table[i], table[i-coins[k]]+1);
          }
        }
    }
    for(int k=0; k<=V; k++) cout<<table[k]<<" ";
    cout<<endl<< table[V]<<endl;
}

// Driver program to test above function
int main()
{
    int coins[] = {1,2,3};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 6;
   // cout << "Minimum coins required is ";
        minCoins(coins, m, V);
    return 0;
}




/*
public class CoinChange {

    public int getMinNumberOfCoins(int[] coins, int sum)
    {
        int[] solution = new int[sum + 1];
        for (int i=0; i<solution.length; i++)
        {
            solution[i] = Integer.MAX_VALUE;
        }
        solution[0] = 0;  // base case
        for (int i = 1; i <=sum; i++)
        {  // build solution one-by-one
            for (int coin: coins)
            {
                if (i - coin >= 0)
                {
                    solution[i] = Math.min(solution[i], solution[i-coin]+1);
                }
            }
        }
        return solution[sum];
    }
}
*/
