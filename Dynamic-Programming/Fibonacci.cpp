//Top down approach
#include<bits/stdc++.h>
using namespace std;

int n, memo[100];

int fibo(int n)
{
     if(n<=2)               return 1;
     else  if(memo[n]!=-1)  return memo[n];
     else                   return memo[n] = fibo(n-1) + fibo(n-2);
}


int main()
{
     memset(memo, -1, sizeof (memo));
     cin>>n;
     cout<<fibo(n)<<endl;
     return 0;
}
