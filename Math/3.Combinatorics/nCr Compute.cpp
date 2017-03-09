///Naive approach

#include<iostream>
using namespace std;
int main()
 {
     int n,r,i;
     long p;
     cin>>n>>r;
     
     p=1;
     for(i=1;i<=r;i++)
      {
         p=p*(n-i+1)/i;
      }
 
     cout<<(long )p;
     return 0;
 }

//Dp Approach
// A Dynamic Programming based solution that uses table C[][] to
// calculate the Binomial Coefficient
#include<bits/stdc++.h>
using namespace std;

// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}
 
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}
 

 
/* Drier program to test above function*/
int main()
{
    int n = 5, k = 2;
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
    return 0;
}
