//Top down approach

#include<bits/stdc++.h>
using namespace std;

char A[2000],B[2000];
int memo[2000][2000];

int editDistance(int n,int m)
{
    if(memo[n][m]!=-1) return memo[n][m];
    if(n==0)         return m;
    if(m==0)         return n;
    return memo[n][m] = min( min( 1+editDistance(n-1,m), 1+editDistance(n,m-1) ),   editDistance(n-1,m-1)+(A[n-1]!=B[m-1]));
}



int main()
{
    ios::sync_with_stdio(false);
    cin>>A>>B;
    memset(memo,-1,sizeof(memo));
    cout<<editDistance(strlen(A),strlen(B))<<endl;
    return 0;
}

