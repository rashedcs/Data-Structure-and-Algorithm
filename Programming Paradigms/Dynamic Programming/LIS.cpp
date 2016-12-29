// Longest Increasing Subsequence
// Dynamic Problem
// Time Complexity O(N^2)
// N -> Number of elements
#include <cstdio>
#include <iostream>
using namespace std;
#define mx 100
int LIS[mx],seq[mx],sol[mx];
int solve(int N)
{
    for(int i=1;i<=N;i++) LIS[i]=1;
    int ans=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(seq[i]<seq[j]&&LIS[j]<LIS[i]+1)
            {
                LIS[j]=LIS[i]+1;
                ans=max(ans,LIS[j]);
            }
        }
    }
    return ans;
}
void printSolution(int N,int lis)
{
    int temp = lis;
    while(N>0)
    {
        if(LIS[N]==temp)
        {
            sol[temp--]=seq[N];
        }
        N--;
    }
    for(int i=1;i<=lis;i++) printf("%d ",sol[i]);
}
int main()
{
    int N; // N is the number of elements
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&seq[i]);
    int ans = solve(N);
    printf("%d\n",ans);
    printSolution(N,ans);
    return 0;
}










//Complexity : 0(nlogn)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    int n, num;
   
    cin>>n;
    for(int i=0; i<n; i++)
    {
      cin>>num;
      vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
      if(v.end()==it) v.push_back(num);
      else   v[it-v.begin()] = num;
    }
    cout<<"LIS = "<<v.size()<<endl;

    return 0;
}


